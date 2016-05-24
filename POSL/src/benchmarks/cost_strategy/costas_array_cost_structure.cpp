#include "costas_array_cost_structure.h"

#include <algorithm>

using namespace std;

//#define ERROR  (size_sq - (dist * dist))
//#define ErrOn(k)   { err[k] += ERROR; err[k - dist] += ERROR; }
#define NB_OF_ERR_VARS_TO_TRY 3
#define BIG ((unsigned int) -1 >> 1)

CostasArrayCostStructure::CostasArrayCostStructure(int n)
    : N(n), CurrentCost(-1), Configuration(n),
      rand(make_shared<Randomizer>(n, 1)),
      dist(1), i(0), first_i(0), diff(0), diff_translated(0), nb(0), r(0),
      err(n, 0), nb_occ(2 * n, 0), first(2 * n, 0),
      save_sol(n), best_sol(n), i_err(n), to_add({1, 2, n - 2, n - 3})
{}

void CostasArrayCostStructure::init(vector<int> config)
{
    //copy(config.begin(), config.end(), Configuration.begin());
    Configuration = config;
    CurrentCost = Cost(config, true);
}

int CostasArrayCostStructure::Cost(vector<int> & config, bool update)
{
    int size2 = (N - 1) / 2;
    dist = 1;
    r = 0;

    if (update) //memset(err, 0, size * sizeof(int));
        fill(err.begin(), err.end(), 0);
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
            if (update)
            {
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
            }
            if (nb > 1)
                r += m_error();
        } while(++i < N);
    } while(++dist <= size2);

    return r;
}

int CostasArrayCostStructure::costOnVariable(int index)
{
    return err[index];
}

void CostasArrayCostStructure::Random_Array_Permut(vector<int> & vec, int begin, int size)
{    
    //random_shuffle(vec.begin() + begin, vec.begin() + begin + size);
    rand->vector_shuffle(vec, begin, begin + size);

    //int i, j, z;
    //for(i = size - 1; i > 0; i--)
    //{
    //    j = Random(i + 1);
    //    z = vec[i];
    //    vec[i] = vec[j];
    //    vec[j] = z;
    //}
}

void CostasArrayCostStructure::Reset()
{    
    int i, j, k, sz;
    int max = 0, nb_max = 0, imax;
    int cost_to_exit = CurrentCost; // p_ad->total_cost
    int best_cost = BIG;
    int cost;

    //memcpy(save_sol, sol, size_bytes);
    copy(Configuration.begin(), Configuration.end(), save_sol.begin());

    for(i = 0; i < N; i++)	/* collect most erroneous vars */
    {
        if (err[i] > max)
        {
            max = err[i];
            i_err[0] = i;
            nb_max = 1;
        }
        else if (err[i] == max)
            i_err[nb_max++] = i;
    }

    Random_Array_Permut(i_err, 0, nb_max);
    imax = i_err[--nb_max]; /* chose one var random (most often there is only one) - the last and dec nb_max */


    /* A way to reset: try to shift left/right all sub-vectors starting or ending by imax
     *                 need sol[] to be as at entry.
     */

    int size2 = (N - 1) / 2;

    for(k = 0; k < N; k++)
    {
        /* we need a random here to avoid to be trapped in the same "bests" chain (see best_cost) */
        if (rand->NextInt(0, 10) < 4) continue; //if (Random_Double() < 0.4) continue;
        if (imax < k)
        {
            i = imax;
            j = k;
        }
        else
        {
            i = k;
            j = imax;
        }
        sz = j - i;
        if (sz <= 1)
            continue;

        //sz *= sizeof(int);

        /* the following test is not precise (could be different),
         * we only want to avoid to do both left and right shift for efficiency reasons */

        if (imax < size2)
        {			/* shift left 1 cell */
            //memcpy(sol + i, save_sol + i + 1, sz);
            //sol[j] = save_sol[i];
            copy(save_sol.begin() + i + 1, save_sol.begin() + i + 1 + sz, Configuration.begin() + i);
            Configuration[j] = save_sol[i];

            if ((cost = Cost(Configuration, false)) < cost_to_exit) // NULL
                return;		/* -1 because the err[] is not up-to-date */

            if (cost < best_cost || (cost == best_cost && rand->NextInt(0, 10) < 2))
            {
                best_cost = cost;
                //memcpy(best_sol, sol, size_bytes);
                copy(Configuration.begin(), Configuration.end(), best_sol.begin());
            }
        }
        else
        {			/* shift right 1 cell */
            //memcpy(sol + i + 1, save_sol + i, sz);
            //sol[i] = save_sol[j];
            copy(save_sol.begin() + i, save_sol.begin() + i + sz, Configuration.begin() + i + 1);
            Configuration[i] = save_sol[j];

            if ((cost = Cost(Configuration, false)) < cost_to_exit) //NULL
                return;

            if (cost < best_cost || (cost == best_cost && rand->NextInt(0, 10) < 2))
            {
                best_cost = cost;
                //memcpy(best_sol, sol, size_bytes);
                copy(Configuration.begin(), Configuration.end(), best_sol.begin());
            }
        }
        /* restore */
        //memcpy(sol + i, save_sol + i, sz + sizeof(int));
        copy(save_sol.begin() + i, save_sol.begin() + i + sz, Configuration.begin() + i);
    }

    /* A way to reset: try to add a constant (circularly) to each element.
     *                 does not need sol[] to be as entry (uses save_sol[]).
     */
    for(j = 0; (k = to_add[j]) != 0; j++)
    {
        // PROBLEM : (not the same as AS)
        for(i = 0; i < N; i++)
            if ((Configuration[i] = save_sol[i] + k) > N)
                Configuration[i] -= N;

        if ((cost = Cost(Configuration, false)) < cost_to_exit) // NULL
            return;      /* -1 because the err[] is not up-to-date */

        if (cost < best_cost && rand->NextInt(0, 100) < 33)
        {
            best_cost = cost;
            //memcpy(best_sol, sol, size_bytes);
            copy(Configuration.begin(), Configuration.end(), best_sol.begin());
        }

    }
    //  memcpy(sol, save_sol, size_bytes); // can be needed depending if what follows need inital sol[]


    /* A way to reset: try to shift left from the beginning to some erroneous var.
     *                 does not need sol[] to be as entry (uses save_sol[]).
     */

    int nb_err = nb_max;		/* NB nb_max has been dec (see above) - thus we forget cur "imax" */
    if (nb_err < NB_OF_ERR_VARS_TO_TRY)		/* add other erroneous vars in i_err[] */
    {
        for(i = 0; i < N; i++)
            if (err[i] > 0 && err[i] < max)
                i_err[nb_err++] = i;

        Random_Array_Permut(i_err, nb_max, nb_err - nb_max); /* some randomness on new vars (don't touch max vars) */
    }

    for(k = 0; k < NB_OF_ERR_VARS_TO_TRY; k++)
    {
        imax = i_err[k];
        if (imax == 0 || /*imax == size - 1 ||*/ rand->NextInt(0, 100) < 33)
            continue;

        //memcpy(sol, save_sol + imax, (size - imax) * sizeof(int));
        //memcpy(sol + size - imax, save_sol, imax * sizeof(int));
        copy(save_sol.begin() + imax, save_sol.end(), Configuration.begin());
        copy(save_sol.begin(), save_sol.begin() + imax, Configuration.begin() + N - imax);

        if ((cost = Cost(Configuration, false)) < cost_to_exit) /* only if it is a var with max error */ // NULL
            return;      /* -1 because the err[] is not up-to-date */

        if (cost < best_cost)
        {
            best_cost = cost;
            //memcpy(best_sol, sol, size_bytes);
            copy(Configuration.begin(), Configuration.end(), best_sol.begin());
        }
    }

    /* return the best found solution */

    //memcpy(sol, best_sol, size_bytes);
    init(best_sol);
}
