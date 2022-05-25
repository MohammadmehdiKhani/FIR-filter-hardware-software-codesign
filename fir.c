#include "stdio.h"
#include "windows.h"

void filter(double* coeff,int N,double* pulse,double* output,int len);
int main()
{
    FILE* data;
    double pulse[120]={-4,-2,0,-4,-6,-4,-2,-4,-6,-6,-4,-4,-6,-6,-2,6,12,8,0,-16,-38,-60,-84,-90,-66,
    				-32,-4,2,-4,8,12,12,10,6,6,6,4,0,0,0,0,0,-2,-4,0,0,0,-2,-2,0,0,-2,-2,-2,-2,0,
					-2,-4,-2,0,-2,-4,-4,2,0,0,-2,-4,-2,0,0,-2,-4,-2,0,0,-4,-4,-2,-2,-4,-6,-6,-4,-4,
					8,-10,-8,-6,-6,-8,-12,-10,-8,-8,-10,-12,-10,-8,-8,-10,-10,-8,-6,-6,-8,-8,-4,-2,
					-4,-4,-4,0,0,-2,-4,-2,-2,0,-4};

    double coeff[67]={0.000546024755771983,	-8.00488171187003e-19,	-0.000641650065867609,	-0.00104725705356440,
    				-0.000877258147492076,	1.27886017174141e-18,	0.00127652786106233,	0.00218580141828661,
					0.00186568941030091,	-2.32847245018841e-18,	-0.00267514624146246,	-0.00448838701221188,
					-0.00374221969880826,	3.79895321245428e-18,	0.00511581347459534,	0.00839744539407861,
					0.00686453751885322,	-5.47963530561660e-18,	-0.00909146654707184,	-0.0147536388082741,
					-0.0119626104967189,	7.12973726512319e-18,	0.0157664648229160,		0.0256998900276194,
					0.0210528838383762,		-8.51285866278668e-18,	-0.0290097940801829,	-0.0492117508516849,
					-0.0427435305950880,	9.43084780939840e-18,	0.0736794505899312,		0.157941404747747,
					0.224766065816018,		0.250173419845741,		0.224766065816018,		0.157941404747747,
					0.0736794505899312,		9.43084780939840e-18,	-0.0427435305950880,	-0.0492117508516849,
					-0.0290097940801829,	-8.51285866278668e-18,	0.0210528838383762,		0.0256998900276194,
					0.0157664648229160,		7.12973726512319e-18,	-0.0119626104967189,	-0.0147536388082741,
					-0.00909146654707184,	-5.47963530561660e-18,	0.00686453751885322,	0.00839744539407861,
					0.00511581347459534,	3.79895321245428e-18,	-0.00374221969880826,	-0.00448838701221188,
					-0.00267514624146246,	-2.32847245018841e-18,	0.00186568941030091,	0.00218580141828661,
					0.00127652786106233,	1.27886017174141e-18,	-0.000877258147492076,	-0.00104725705356440,
					-0.000641650065867609,	-8.00488171187003e-19,	0.000546024755771983};

    double output[120]={0};

    filter(coeff,67,pulse,output,120);
    data=fopen("data.txt","w");
    for(int i=0;i<120;i++)
    {
        fprintf(data,"%d\t%lf\n",i,output[i]);
    }
    fclose(data);

    return 0;
}

void filter(double* coeff,int N,double* pulse,double* output,int len)
{
    for(int i=0;i<len;i++)
    {
    	output[i]=pulse[i]*coeff[0];
        for(int j=1;i-j>=0 && j<N;j++)
        {
        	output[i] = output[i] + pulse[i-j]*coeff[j];
        }
    }
}