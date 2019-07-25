#include <iostream>
#include <cstdlib>      //defines rand(), srand(), RAND_MAX
#include <ctime>        //defines ctime() for random numbers
#include <cmath>        //defines math functions
#include <omp.h>

int main()
{
    double x, y, test;
    srand(time(NULL));      //creates the seed time
    test = rand() / double(RAND_MAX);
    double throwDist;       //distance from the origin
    double a = 0;              //times a dart ends up inside the circle
    int numThrows;          //times to throw the dart
    int num_threads = omp_get_max_threads();
    int i
    numThrows = 1000000;

    //creates 2 random numbers 'n' times
    #pragma omp parallel shared(numThrows, a) private(throwDist, i)
    #pragma omp for
    for(i = 1; i <= numThrows * 4; i++)
    {
        x = (double)rand() / (RAND_MAX);
        y = (double)rand() / (RAND_MAX);
        throwDist = sqrt(x*x + y*y);
        //counts how often the dart is thrown inside the circle
        if(throwDist <= 1)
        {
            a++;
        }
    }
    double pi_value = a / numThrows;
    cout<< "The value of PI is: " << pi_value;
return 0;
}
