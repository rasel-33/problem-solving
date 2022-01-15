Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3051



#include <bits/stdc++.h>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--) 
#define pi             acos(-1)         

using namespace std;

ll i,j,temp,k;

int main()
{_
	int pop=0;
	tc(){
		int n,pic,max,egg_count=0,egg_weight=0;
		temp =0;
		cin>>n>>pic>>max;
		int arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
		} 
		sort(arr,arr+n);
		for(i=0;i<n;i++){
			temp += arr[i];
			if(i+1 <= pic && temp <= max)
				egg_count++;
			else
				break;
		}
		cout<<"Case "<<++pop<<": "<<egg_count<<endl; 
	}
return 0;
}
