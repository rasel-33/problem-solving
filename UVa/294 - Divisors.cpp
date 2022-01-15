//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=230


#include<iostream>

using namespace std;

long long divisor(long long x){

	int i,cnt = 0,sqr=0;

	for(i=1;i*i<=x;i++){
		if(x%i==0){
			cnt++;
			
		}
	}

	return 2*cnt-sqr;
}

int main(){

	long long t;

	cin>>t;

	while(t--){

		long long L,U,max=0,i,divisor_number,div,k;

		cin>>L>>U;

		for(i=L;i<=U;i++){
			
			k = sqrt(i);
			if(k*k==i){
				div = -1;
			}
			
			if((div + divisor(i))>max){

				max = divisor(i) + div;
				divisor_number = i;
			}
			div = 0;
		}

		cout<<"Between "<<L<<" and "<<U<<", "<<divisor_number<<" has a maximum of "<<max<<" divisors."<<endl;
	}

	return 0;
}
