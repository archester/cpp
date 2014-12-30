#include <iostream>
#include <functional>


double lambda = 0.0001;

double abs(double a)
{
    return a>0 ? a: -a;
}

/*recursive version*/
double sqrt(double val, double from, double to)
{
    double mid = (from+to)/2;
    if (abs(mid*mid - val) < lambda)
    {
        std::cout << mid << "-1\n";
        return mid;
    }
    else if (mid*mid > val)
    {
        std::cout << mid << "-2\n";
        return sqrt(val, from, mid);

    }
    else
    {
        std::cout << mid << "-3\n";
        return sqrt(val, mid, to);
    }
}

/*iterative version*/
double sqrt2(double val, double from, double to)
{
    double mid;
    while (true)
    {
        mid = (from+to)/2;
        if (abs(mid*mid - val) < lambda)
        {
            return mid;
        }
        else if(mid*mid > val)
        {
            to = mid;
        }
        else
        {
            from = mid;
        }
    }
}

int main()
{
    std::cout << sqrt2(9.0, 0, 9.0) << "\n";

    return 0;
}

