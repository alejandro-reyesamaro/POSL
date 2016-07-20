#include "squaring_square_cost_structure.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define Z _squares.size()

vector<int> store_movement_capacity(vector<int> & _squares, int _size)
{
    vector<int> mc(Z);
    for(unsigned int i = 0; i < Z; i++)
        mc[i] = (_size * _size) / (_squares[i] * _squares[i]);
    return mc;
}

SquaringSquareCostStructure::SquaringSquareCostStructure(int _size, vector<int> _squares)
    : CurrentCost(-1),
      Configuration(Z * 2),
      size(_size),
      squares(_squares),
      m_cost(Z),
      m_cost_aux(Z),
      configuration_aux(Z * 2),
      cost_on_variable(Z, 0),
      cost_on_variable_aux(Z, 0),
      cost_on_leaving(Z, 0),
      cost_on_leaving_aux(Z, 0),
      momement_capacity(store_movement_capacity(_squares, _size))
{}

void SquaringSquareCostStructure::set(std::vector<int> _configuration)
{
    //copy(_configuration.begin(), _configuration.end(), Configuration.begin());
    Configuration = _configuration;
    fill(cost_on_variable.begin(), cost_on_variable.end(), 0);
    fill(cost_on_leaving.begin(), cost_on_leaving.end(), 0);
    CurrentCost = 0;
    int sqrs = squares.size();
    int intersecX, intersecY;
    for(int i = 0; i < sqrs -1; i++)
        for(int j = i + 1; j < sqrs; j++)
        {
            intersecX = Tools::segmentIntersection(Configuration[i],
                                                   Configuration[i]+squares[i],
                                                   Configuration[j],
                                                   Configuration[j]+squares[j]);
            intersecY = Tools::segmentIntersection(Configuration[i+sqrs],
                                                   Configuration[i+sqrs]+squares[i],
                                                   Configuration[j+sqrs],
                                                   Configuration[j+sqrs]+squares[j]);
            m_cost.set(i,j, intersecX * intersecY);         // Intersection square_i and square_j
            cost_on_variable[i] += intersecX * intersecY;    // Projected cost of square i
            cost_on_variable[j] += intersecX * intersecY;    // Projected cost of square i
        }        

    int extra_x, extra_y;
    for(int i = 0; i < sqrs; i++)
    {
        extra_x = std::max(0, Configuration[i]+squares[i] - size);
        extra_y = std::max(0, Configuration[i+sqrs]+squares[i] - size);

        // Cost on leaving the big square (square i)
        cost_on_leaving[i] = (extra_x * squares[i]) + (extra_y * squares[i]) - (extra_x * extra_y);

        CurrentCost += cost_on_variable[i] + (cost_on_leaving[i] * cost_on_leaving[i]);
    }
}

int SquaringSquareCostStructure::relative_cost(UpperMatrix & matrix_cost,
                                               vector<int> & current_config,
                                               vector<int> & new_config,
                                               T_Changes & change,
                                               int current_cost,
                                               vector<int> & cost_on_variable_vector,
                                               vector<int> & cost_on_leaving_vector)
{
    for (int i_change = 0; i_change < change.dim; i_change++)
    {
        unsigned int index_change = change.positions[i_change];
        unsigned int the_square = (index_change < new_config.size() / 2)
                                ? index_change
                                : index_change - new_config.size() / 2;
        unsigned int x_coord_new_loccation = (index_change < new_config.size() / 2)
                                  ? change.new_values[i_change]
                                  : current_config[index_change - squares.size()];
        unsigned int y_coord_new_loccation = (index_change >= new_config.size() / 2)
                                  ? change.new_values[i_change]
                                  : current_config[index_change + squares.size()];
        int new_intersecX, new_intersecY;
        int sqrs = squares.size();
        for(unsigned int i = 0; i < current_config.size()/2; i++)
        {
            if(i == the_square) continue;
            new_intersecX = Tools::segmentIntersection(current_config[i],
                                                       current_config[i]+squares[i],
                                                       x_coord_new_loccation,
                                                       x_coord_new_loccation+squares[the_square]);
            new_intersecY = Tools::segmentIntersection(current_config[i+sqrs],
                                                       current_config[i+sqrs]+squares[i],
                                                       y_coord_new_loccation,
                                                       y_coord_new_loccation+squares[the_square]);
            //int corrent_piece_cost = matrix_cost.elementAt(i,the_square);
            current_cost += new_intersecX * new_intersecY - matrix_cost.elementAt(i,the_square);
            cost_on_variable_vector[i] += new_intersecX * new_intersecY - matrix_cost.elementAt(i,the_square);
            matrix_cost.set(i,the_square, new_intersecX * new_intersecY);
        }
        int current_cost_the_square = matrix_cost.getLineSum(the_square);
        current_cost += current_cost_the_square - cost_on_variable_vector[the_square];
        cost_on_variable_vector[the_square] = current_cost_the_square;

        int extra_x = std::max(0, (int)x_coord_new_loccation+squares[the_square] - size);
        int extra_y = std::max(0, (int)y_coord_new_loccation+squares[the_square] - size);
        int this_cost_on_leaving = (extra_x * squares[the_square]) + (extra_y * squares[the_square]) - (extra_x * extra_y);        
        current_cost += Tools::sqr(this_cost_on_leaving) - Tools::sqr(cost_on_leaving_vector[the_square]);
        cost_on_leaving_vector[the_square] = this_cost_on_leaving;
        current_config[change.positions[i_change]] = change.new_values[i_change];
    }
    if(current_cost < 0)
        throw "(POSL Esception) Cost under zero (SquaringSquareCostStructure::relative_cost)";
    return current_cost;
}

int SquaringSquareCostStructure::relative_cost(std::vector<int> & new_config, T_Changes change, bool updating)
{
    if(updating)
    {
        CurrentCost = relative_cost(m_cost, Configuration, new_config, change, CurrentCost, cost_on_variable, cost_on_leaving);
        return CurrentCost;
    }
    else
    {
        m_cost_aux = m_cost;
        copy(Configuration.begin(), Configuration.end(), configuration_aux.begin());
        copy(cost_on_variable.begin(), cost_on_variable.end(), cost_on_variable_aux.begin());
        copy(cost_on_leaving.begin(), cost_on_leaving.end(), cost_on_leaving_aux.begin());
        return relative_cost(m_cost_aux, configuration_aux, new_config, change, CurrentCost, cost_on_variable_aux, cost_on_leaving_aux);
    }
}

int SquaringSquareCostStructure::costOnVariable(int index)
{
    //int cov = (cost_on_variable[index] + (cost_on_leaving[index] * cost_on_leaving[index])) * momement_capacity[index];
    return (cost_on_variable[index] + (cost_on_leaving[index] * cost_on_leaving[index])) * momement_capacity[index];
}
