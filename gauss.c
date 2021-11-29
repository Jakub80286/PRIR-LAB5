#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctime>



double funkcja(double x)
 {

    return 4 * x - 6 * x + 5;
}


double Gauss(int a, int b, double waga[], double wezel[]){
	int n = sizeof(waga);
	double suma = 0;
	for(int i=0; i<n; i++){
		suma += waga[i] * funkcja(((b-a)/2)*wezel[i] + ((b+a)/2));
	}
	return ((b-a)/2)*suma;
}
 int random(int min, int max)
{
	srand(getpid());
   return min + rand() % (( max + 1 ) - min);
}
int main(){


	double waga[] =
				{0.3626837833783620,
				0.3626837833783620,
				0.3137066458778873,
				0.3137066458778873,
				0.2223810344533745,
				0.2223810344533745,
				0.1012285362903763,
				0.1012285362903763};


	double wezel[] =
				{-0.1834346424956498,
				0.1834346424956498,
				-0.5255324099163290,
				0.5255324099163290,
				-0.7966664774136267,
				0.7966664774136267,
				-0.9602898564975363,
				0.9602898564975363};


	int pidy;
    scanf("%d", &pidy);

    for(int i=0; i<pidy; i++){
		if(fork() == 0){
			int a = random(-20,0);
			int b = random(0,20);
			printf("Calka wynosi %f",Gauss(a,b,waga,wezel));
			exit(0);
		}
	}


return 0;
}
