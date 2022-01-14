//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=615

#include<bits/stdc++.h>

#define ll                  long long
#define tc()                int tc;scanf("%d",&tc);while(tc--)
#define fast                ios::sync_with_stdio();cin.tie(0)
#define endl                "\n"
#define pi                  2*acos(0)

using namespace std;

int main(){
	fast;
	int status[10005];
	for(int i=0;i<10005;i++){
		status[i] =0;
	}
	status[0] =1;
	int n=5,x;
	int arr[n];
	arr[0] = 1;
	arr[1] = 5;
	arr[2] = 10;
	arr[3] = 25;
	arr[4] = 50;
	for(int i=0;i<n;i++){
		for(int j=arr[i];j<10005;j++){
			status[j] += status[j-arr[i]];
		}
	}
	while(scanf("%d",&x)!=EOF){
		cout<<status[x]<<endl;
	}
return 0;
}
