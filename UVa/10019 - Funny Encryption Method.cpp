#include <bits/stdc++.h>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--)          
#define MAX            10000000

using namespace std;

ll i,j,temp;

int main()
{_

	
	int t;
	cin>>t;

	while(t--){

		int n,cnt =0,digit,new_n=0;
		cin>>n;

		bitset<40> bitset1(n);

		temp = n;
		while(temp>0){
			digit = temp%10;
			new_n = new_n + (digit*pow(16,cnt));
			cnt++;
			temp /= 10;
		}

		bitset<40> bitset2(new_n);
		cout<<bitset1.count()<<" "<<bitset2.count()<<endl;
	}
	return 0;
}
