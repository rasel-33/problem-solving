#include<bits/stdc++.h>
#define ll long long
#define M 32

using namespace std;

int main(){

	ll x;
	

	while(cin>>x){
		if(x==0)
			break;

		ll cnt = 0,i,first_one;
		bitset<M> parity(x);

		for(i=31;i>=0;i--){
			if(parity[i]==1){
				first_one = i;
				break;
			}
		}

		cout<<"The parity of ";
		
		for(i=first_one;i>=0;i--){
			cout<<parity[i];
			if(parity[i]==1)
				cnt++;
		}
		cout<<" is "<<cnt<<" (mod 2)."<<endl;

	}
	return 0;
}
