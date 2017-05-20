#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 99
#define W 0.5
#define H 0.0001
#define u(i) v[i]
int main(int argc, char const *argv[])
{
	int i,k;
	double v[N];
	double f[N];
	memset(v,0,sizeof(double)*N);
	memset(f,0,sizeof(double)*N);
	v[0] = -24.5;
	v[98] = -9.5;
	f[0] = 49/H;
	f[98] = 19/H;
	double mod=0;
	do{
		mod=0;
		u(0) = (1/-2)*((H)*f[0] - 50 - u(i+1)); 
		mod+=u(0)*u(0);
		for (i = 1; i < N-1; ++i)
		{
			u(i) = (1/-2)*((H)*f[i] - u(i-1) - u(i+1));
			mod+=u(i)*u(i);
		}
		u(i) = (1/-2)*((H)*f[i] - u(i-1) - 100);
		mod+=u(i)*u(i);
		k++;
	}while(1/sqrt(mod)>10e-7);
	do{
		mod=0;
		u(0) = (W/-2)*((H)*f[i] - 50 - u(i+1))+(1-W)*u(0); 
		mod+=u(0)*u(0);
		for (i = 1; i < N-1; ++i)
		{
			u(i) = (W/-2)*((H)*f[i] - u(i-1) - u(i+1))+(1-W)*u(i);
			mod+=u(i)*u(i);
		}
		u(i) = (W/-2)*((H)*f[i] - u(i-1) - 100)+(1-W)*u(i);
		mod+=u(i)*u(i);
		k--;
	}while(k>0&&1/sqrt(mod)>10e-7);
	return 0;
}