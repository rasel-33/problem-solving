#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long arr[9];
	while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8])!=EOF){
		long long total= arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] +arr[6] + arr[7] + arr[8];
		long long mn = 100000000000000;
		char str[4] = "";
		long long temp;
		//BCG
		temp = arr[0]+arr[5]+arr[7];
		temp = total - temp;
		if(temp<mn){
			mn = temp;
			strcpy(str,"BCG");
		}
		//BGC
		temp = arr[0]+arr[4]+arr[8];
		temp = total - temp;
		if(temp<mn){
			mn = temp;
			strcpy(str,"BGC");
		}
		//CBG
		temp = arr[2]+arr[3]+arr[7];
		temp = total - temp;
		if(temp<mn){
			mn = temp;
			strcpy(str,"CBG");
		}
		//CGB
		temp = arr[2]+arr[4]+arr[6];
		temp = total - temp;
		if(temp<mn){
			mn = temp;
			strcpy(str,"CGB");
		}
		//GBC
		temp = arr[1]+arr[3]+arr[8];
		temp = total - temp;
		if(temp<mn){
			mn = temp;
			strcpy(str,"GBC");
		}
		//GCB
		temp = arr[1]+arr[5]+arr[6];
		temp = total - temp;
		if(temp<mn){
			mn = temp;
			strcpy(str,"GCB");
		}
		if(total==0){
			printf("%s 0\n","BCG");
		}
		else{
			printf("%s %lld\n",str,mn);
		}
		

	}
	return 0;
}
