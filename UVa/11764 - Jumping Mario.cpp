//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2864


#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll i,j,k,cnt;

int main()

{
    int t;

    cin>>t;
    for(i=1;i<=t;i++){
    	int N,high=0,low=0,initial;
    	cin>>N;

    	int arr[N];
    	cin>>arr[0];

    	initial = arr[0];
    	for(j=1;j<N;j++){
    		cin>>arr[j];
    		if(arr[j] == initial){
    			continue;
    		}
    		else if(arr[j] < initial){
    			low++;
    			
    		}
    		else if(arr[j] > initial ){
    			high++;
    		}
    		initial = arr[j];
    	}

    	cout<<"Case "<<i<<": "<<high<<" "<<low<<endl;
    }


    return 0;

}
