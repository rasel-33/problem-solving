//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484

#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int primity(ll x){
	ll i;
	for(i=2;i*i<=x;i++){
		if(x%i==0)
			return 0;
	}
	return 1;

}

int main(){
	int x,a,b,i,j;

	while(cin>>x){
		if(x==0)
			break;

		for(i=2,j=x-2;i<=j;i++,j--){
			if(primity(i)==1 && primity(j)==1){
				cout<<x<<" = "<<i<<" + "<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
