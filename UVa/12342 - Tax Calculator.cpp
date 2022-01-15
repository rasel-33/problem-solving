//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3764


#include <iostream>
#include <stdio.h>
#include <math.h>


#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define tc()           int t;cin>>t;while(t--)


using namespace std;


ll i,j,temp;


int main()
{_
	
	int n=0;
	tc(){
		ll income;
		double tax =0;bool zero = false;
		cin>>income;
		if(income<=180000){
			zero = true;
		}
		income -= 180000;
		if(income > 300000){
			tax += 300000*0.10;
			
		}
		else if(income>0){
			tax += (double)income*0.10;
		}
		income -= 300000;

		if(income > 400000){
			tax += 400000*0.15;
			
		}
		else if(income>0){
			tax += (double)income*0.15;
		}
		income -= 400000;
		if(income > 300000){
			tax += 300000*0.20;
			
		}
		else if(income>0){
			tax += (double)income*0.20;
		}
		income -= 300000;
		if(income>0){
			tax += (double)income*.25;
		}
		double extra;
	    extra = tax - (int)tax;
	    if(extra){
	    	tax = (int)tax + 1;
	    }
	    if(tax<2000){
	    	tax = 2000;
	    }
	    if(!zero){
	    	printf("Case %d: %.0lf\n",++n,tax);
	    }
	    else
	    	printf("Case %d: %.0lf\n",++n,0);
	}
	
    return 0;
}
