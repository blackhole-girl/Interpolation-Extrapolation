#include<stdlib.h>
#include <stdio.h>
#include <err.h>
#include <math.h>
#include "polint.h"


int main(void)
{
	/*VARIABLES*/
	
	double  *xa = NULL, *ya = NULL;
	double x = 0, y = 0, dy = 0;
	int i = 0, n = 30;

	/*INSTRUCTIONS*/

	/*generate n pairs of (x, f(x))*/
	xa = (double*) malloc(n*sizeof(double));
        if(xa==NULL)
                err(-1,"Malloc  failed  in %s,line %d",__FILE__ ,__LINE__ );

        ya = (double*) malloc(n*sizeof(double));
        if(ya==NULL)
                err(-1,"Malloc  failed  in %s,line %d",__FILE__ ,__LINE__ );

	/* array vals */
	for (i = 0; i<n; i++)
	{
		xa[i] = i;
		ya[i] = sin(i);
	}

	/*prompt user for an arbitary value x */
	printf("please enter an arbitary value of x : ");
	scanf("%lf", &x);

	/*call polint and print func value with error estimate*/
	polint(xa,ya,n,x, &y, &dy);
	printf("x : %f gives %f with an error of %f \n", x, y, dy);


	return 0;
}
