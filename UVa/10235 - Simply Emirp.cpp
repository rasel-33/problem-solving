#include<bits/stdc++.h>
#define max 1000000

using namespace std;

int reversed(int x){
	int arr[10],cnt=0,N,new_N=0,i;
	N = x;
	while(x>0){
		arr[cnt] = x%10;
		x/=10;
		cnt++; 
	}
	for(i=0;i<cnt;i++){
		new_N = (new_N*10) + arr[i];
	}

	return new_N;
}

int main()
{
	bitset<max> prime;

	int i,cnt,j,limit,number;

	prime[0] = 1;
	prime[1] = 1;
	prime[2] = 0;

	limit = sqrt(max);

	for(i=4;i<=max;i+=2){
		prime[i] = 1;
	}

	for(i=3;i<=limit;i++){
		if(prime[i]==0){
			for(j=i+i;j<=max;j+=i){
				prime[j] = 1;
			}
		}
	}
	
	while(scanf("%d",&number)!=EOF){
		if(prime[number]==1){
			cout<<number<<" is not prime."<<endl;
		}
		else if(prime[number]==0 && prime[reversed(number)]==0 && number!=reversed(number)){
			cout<<number<<" is emirp."<<endl;
		}
		else if(prime[number]==0 && (prime[reversed(number)]==1 || number==reversed(number) )){
			cout<<number<<" is prime."<<endl;
		}
		
		
	}
	return 0;
}
