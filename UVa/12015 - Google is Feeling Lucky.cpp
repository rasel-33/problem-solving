//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3166

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

struct webpages{
	char name[50];
	int rank;
};

int main(){

	int t,i;

	cin>>t;

	for(i=1;i<=t;i++){

		int j,x,carr[10];
		struct webpages arr[10];

		for(j=0;j<10;j++){
			cin>>arr[j].name>>arr[j].rank;
			carr[j] = arr[j].rank;
		}
		
		sort(carr,carr+10);
		
		x = carr[9];
		cout<<"Case #"<<i<<":"<<endl;

		for(j=0;j<10;j++){
			if(arr[j].rank == x){
				cout<<arr[j].name<<endl;
			}
		}
		
	}
	return 0;
}
