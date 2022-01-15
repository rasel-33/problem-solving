//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3194


#include <bits/stdc++.h>
using namespace std;

int nod(long long n){
	long long i;
	long long number = 0;
	for(i=1;i*i<=n;i++){
		if(!(n%i) && n/i==i){
			number+=1;
		}
		else if(n%i==0){
			number+=2;
		}
	}

	return number;
}

int sod(long long n){
	long long i;
	long long sum ;
	sum = 0;
	for(i=1;i*i<=n;i++){
		if(!(n%i) && n/i==i){
			sum += i;
		}
		else if(n%i==0){
			sum += (i + n/i);
		}
	}

	return sum;
}


int main(){
	int tc;
	cin>>tc;
	while(tc--){
        long long a,b,k,sum=0,div=0;
        cin>>a>>b>>k;
        long long i;
        for(i=a;i<=b;i++){
            if(i%k==0){
                sum += sod(i);
                div += nod(i);
            }
        }

        cout<<div<<" "<<sum<<endl;
	}
	return 0;
}
