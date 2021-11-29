#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
double funkcja(double x)
 {

    return 4 * x - 6 * x + 5;
}

int random(int min, int max)
{
	srand(getpid());
   return min + rand() % (( max + 1 ) - min);
}

int main ()
{

	int pidy;
    scanf("%d", &pidy);
	for(int j=0; j<pidy;j++)
	{

		if(fork()!=0)
		{
			srand(time(NULL) ^ (getpid()<<16));
			int a = random(-20,0);
			int b = random(0,20);
			double n=100;

			double h = ((b - a) / n);
			double wynik=0;
			double koncowy=0;
			for (int i=0; i<n; i++)
			{

				wynik += funkcja(a + ((i / n) * (b - a))) + funkcja(a + (((i + 1) /n) * (b - a)));

			}
			koncowy= (wynik * h) / 2;
		}
	}
}
