//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1335


#include<bits/stdc++.h>
#define max 20000000

using namespace std;

int main()
{
	bitset<max> prime;

	int p,i,j,cnt = 1,len;
	int t_prime[max];

	for(auto i=4;i<=max;i+=2){
		prime[i]=1;
	}

	len = sqrt(max);

	for(i=3;i<=len;i++){
		if(prime[i]==0){
			for(j= i+i;j<=max;j += i){
				prime[j] = 1;
			}
		}
	}
	
	for(i=3;i<max;i++){
		if(prime[i]==0 && prime[i+2]==0){
			t_prime[cnt] = i;
			cnt++;
		}
	}

	while(scanf("%d",&p)!=EOF){
		cout<<"("<<t_prime[p]<<", "<<t_prime[p]+2<<")"<<endl;
		
	}
	return 0;
}
