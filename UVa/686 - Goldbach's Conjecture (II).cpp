//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=627

#include<bits/stdc++.h>
#define MAX 100000
#define ll long long

using namespace std;
bitset<MAX> prime;

ll i,j;

void seive(){
	prime[0] = prime[1] =1;
	for(i=4;i<MAX;i+=2){
		prime[i] = 1;
	}
	for(i=3;i*i<MAX;i+=2){
		if(!prime[i]){
			for(j=i+i;j<=MAX;j+=i){
				prime[j]=1;
			}
		}
	}
}

int main()
{
	ll x;
	seive();
	while(cin>>x){
		
		if(x==0) break;
		int cnt =0;
		if(prime[2]==0 && prime[x-2]==0 ){
			cnt++;
		}
		for(i=3,j=x-3;i<=j;i+=2,j-=2){
			if(prime[i]==0 && prime[j]==0) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
