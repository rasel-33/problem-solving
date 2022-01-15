//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2349



#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;

	cin>>t;

	while(t--){
		int x,i,sum=0;

		cin>>x;

		int arr[x];

		for(i=0;i<x;i++){
			cin>>arr[i];
		}

		sort(arr,arr+x);
		for(i=0;i<x-1;i++){
			sum += abs(arr[i+1] - arr[i]);
		}

		cout<<2*sum<<endl;
	}

	return 0;
}
