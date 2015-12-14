#include "costas_array_cost_structure.h"

#include <algorithm>

using namespace std;

//#define ERROR  (size_sq - (dist * dist))
//#define ErrOn(k)   { err[k] += ERROR; err[k - dist] += ERROR; }

CostasArrayCostStructure::CostasArrayCostStructure(int n)
    : N(n), CurrentCost(-1), Configuration(n),
      dist(1), i(0), first_i(0), diff(0), diff_translated(0), nb(0), r(0),
      err(n, 0), nb_occ(2 * n, 0), first(2 * n, 0)
{}

void CostasArrayCostStructure::init(vector<int> config)
{
    copy(config.begin(), config.end(), Configuration.begin());
    //memset(err, 0, size * sizeof(int));
    fill(err.begin(), err.end(), 0);

    int size2 = (N - 1) / 2;
    dist = 1;
    r = 0;

    do
    {
        //memset(nb_occ, 0,  size * (2 * sizeof(int)));
        fill(nb_occ.begin(), nb_occ.end(), 0);

        i = dist;
        do
        {
            diff = config[i - dist] - config[i];
            diff_translated = diff + N;
            nb = ++ nb_occ[diff_translated];

            if (nb == 1)
                first[diff_translated] = i;
            else
            {
                if (nb == 2)
                {
                    first_i = first[diff_translated];
                    m_errOn(first_i);
                }
                m_errOn(i);
            }

            if (nb > 1)
                r += m_error();
        } while(++i < N);
    } while(++dist <= size2);

    CurrentCost = r;
}

int CostasArrayCostStructure::costOnVariable(int index)
{
    return err[index];
}
