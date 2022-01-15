//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1373


#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)

int main()
{
	double radius,n;

	while(scanf("%lf %lf",&radius,&n)==2){

		double a,height,halfa,area_triangle,total_area,cone_center,cone_radial;

		cone_radial = ((2*pi)/n)/2;
		
		a = radius*sin(2*pi/n)/2;

		area_triangle = n*radius*a;

		printf("%0.3lf\n",area_triangle);

	}	
	return 0;

}
