//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=235

#include<iostream>
#define ll long long

using namespace std;

int main(){
	int t;

	cin>>t;

	while(t--){
		ll x,i,cnt =0,j;

		cin>>x;

		int arr[x],temp;

		for(i=0;i<x;i++){
			cin>>arr[i];
		}
		for(i=0;i<x;i++){
			for(j=i;j<x;j++){
				if(arr[i] > arr[j]){
					cnt++;

					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}

		cout<<"Optimal train swapping takes "<<cnt<<" swaps."<<endl;

	}

	return 0;
}
