#include <random>
using namespace std;

bool checkDistance(double x, double y)
{
    if (sqrt(pow(x, 2) + pow(y, 2)) > 1)
    {
        return false;
    }
    return true;
}

double computePi(unsigned long numThrows)
{
    int min = 0;
    int max = 1;
    int dartsIn = 0;
    default_random_engine rnd{ random_device{}() };
    uniform_real_distribution<double> dist(min, max);

    for (unsigned long i = 0; i < numThrows; i++)
    {
        double x = dist(rnd);
        double y = dist(rnd);
        if (checkDistance(x, y))
        {
            dartsIn++;
        }
    }

    double piApprox = (4.0 * (double)dartsIn) / (double)numThrows;
    return piApprox;
}