#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>


double PI(int n)
 {
    double sum = 0;

    for(int i = 1; i <= n; i++)
    {
        sum += pow(-1, i - 1) / (2 * i - 1);
    }

    return 4 * sum;
}

int main()
{
    int pidy;

    for (int i = 0; i < pidy; i++)
    {
        if (fork() == 0)
        {
            srand(time(0) ^ (getpid() << 16));
            int n = (rand() % (5000 - 100 + 1)) + 100;

            printf("n = %d, PI: %f\n", n, PI(n));
            exit(0);
        }
    }
    return 0;
}
