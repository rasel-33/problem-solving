#include<iostream>
#include<cmath>
#include<stdio.h>
#define pi acos(-1)

using namespace std;

int main()
{

	double x1,y1,x2,y2,CMD,ENF,AN,AB,AM;

	while(cin>>x1>>y1>>x2>>y2>>CMD>>ENF){

		AB = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
		AN = AB*(1/tan(ENF*pi/180));
		AM = AB*(1/tan(CMD*pi/180));
		printf("%0.3lf\n",AN+AM);

	}
	return 0;
}
