//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2457


#include<bits/stdc++.h>


using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long x,i;
	
	cin>>x;
	while(x!=0){
		
		int arr[x];

		for(i=0;i<x;i++)
			cin>>arr[i];

		sort(arr,arr+x);

		for(i=0;i<x;i++){
			if(i!=(x-1)){
				cout<<arr[i]<<" ";
			}
			else{
				cout<<arr[i];
			}
			
		}
		cout<<endl;
		cin>>x;
	}

	return 0;

}
