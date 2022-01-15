//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2009


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a1,a2,b1,b2,c1,c2;
	double x,y;

	while(cin>>a1>>b1>>c1>>a2>>b2>>c2){

		if(a1==0 && b1==0 && c1==0 && a2==0 && b2==0 && c2==0)
			break;
		
		double pen ;
		pen = ((double)a1*(double)b2 - (double)a2*(double)b1);

		if(pen !=0){
			x = ((double)b1*(double)c2 - (double)c1*(double)b2)/pen;
			y = ((double)c1*(double)a2 - (double)a1*(double)c2)/pen;
			printf("The fixed point is at %.2lf %.2lf.\n",-x,-y);
		}
		else{
			cout<<"No fixed point exists."<<endl;
		}
	}
	return 0;
}
