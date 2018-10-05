#include <stdio.h>
#include <math.h>

void
kiir (double tomb[], int db)
{
	int i;
	for (i=0; i<db; i++)
		printf("PageRank [%d]: %lf\n", i, tomb[i]);
}

double tavolsag(double pagerank[],double pagerank_temp[],int db)
{
	double tav = 0.0;
	int i;
	for(i=0;i<db;i++)
		tav +=abs(pagerank[i] - pagerank_temp[i]);
	return tav;
}

int main(void)
{
	double L[4][4] = {
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};

	double PR[4] = {0.0, 0.0, 0.0, 0.0};
	double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

	long int i,j,h;
	i=0; j=0; h=5;

	for (;;)
	{
		for(i=0;i<4;i++)
		PR[i] = PRv[i];
		for (i=0;i<4;i++)
		{
			double temp=0;
			for (j=0;j<4;j++)
			temp+=L[i][j]*PR[j];
			PRv[i]=temp;
		}

		if ( tavolsag(PR,PRv, 4) < 0.00001)
		break;
	}
	kiir (PR,4);
	return 0;

}

