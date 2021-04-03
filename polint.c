#include<stdio.h>
#include<stdlib.h>
#include<err.h>
#include<math.h>
#include "polint.h"


void polint(double *xa, double *ya, int n, double x, double *y, double *dy)
{
	/* VARIABLES */
	double *c = NULL;
	double *d = NULL;
	int i = 0,m=0, j=1; 
	double d_x=0,differ=0,app=0,xo=0,xn=0, w = 0;


	/* INSTRUCTIONS */

	/* initial estimate of y given by ya[i], xa[i] close to x*/
	
	*y = ya[j--]; 

	/*memory allocation for c[i] and d[i] containing the poly coeffs */
	c = (double*) malloc(n*sizeof(double));
	if(c==NULL)
		err(-1,"Malloc  failed  in %s,line %d",__FILE__ ,__LINE__ );

	d = (double*) malloc(n*sizeof(double));
        if(d==NULL)
                err(-1,"Malloc  failed  in %s,line %d",__FILE__ ,__LINE__ );
        

	/*calculating difference between parent and child*/
	differ =fabs(x-xa[1]);

	/*setting c[i] and d[î] to ya[i]*/
	for (i = 0 ; i <= n; i ++)
	{
		if ((app=fabs(x-xa[i])) < differ)
		{
			j=i;
			differ=app;
		}
		c[i] = ya[i] ;
		d[i] = ya[i] ;
	}


	/*loop*/
	for( m = 1 ; m <n ; ++m ) 
	{          /*For each column of the tableau */   
		for( i = 1; i <= n-m ; ++i ) 
		{      /*we loop over the current c’s and d’s and update them.*/
			xo =xa[i]-x;
      			xn =xa[i+m]-x;
			d_x = xo - xn;
			w = c[i+1] -d[i];
			/*error for xa being identical */
			if (d_x == 0.0)	perror("error in the algorithm: the two inputs of xa are identical"); 
			d_x=w/d_x;

		/* Here the c’s and d’s are updated. d[i] = D_m+1,i  ,    c[i] = C_m+1,i */
			d[i] =xn*d_x;
			c[i] =xo*d_x;
		}
		*y += (*dy=(2*j < (n-m) ? c[j+1] : d[j--]));
	
	}



	/*free memory*/
	free(c);
	c = NULL;
	free(d);
        d = NULL;



	return ;


}
