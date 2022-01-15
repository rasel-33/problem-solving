//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=49


#include<stdio.h>
#include<math.h>

int main()
{
	double k,p;
	while(scanf("%lf %lf",&k,&p)!=EOF){
		printf("%.0lf\n",pow(p,1/k));
	}
	return 0;
}
