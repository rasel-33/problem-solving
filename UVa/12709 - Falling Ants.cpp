//Problem Link :  https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&category=824&page=show_problem&problem=4447


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;

	while(cin>>t){

		if(t==0)
			break;
		int L[t],W[t],H[t],V[t],i,x,cnt=0,index[t],Volume[t],max;
		for(i=0;i<t;i++){
			cin>>L[i]>>W[i]>>H[i];
		}
		for(i=0;i<t;i++){
			V[i] = L[i]*W[i]*H[i];
		}
		max = H[0];
		for(i=0;i<t;i++){
			if(H[i]>max){
				max = H[i];
			}
		}
		for(i=0;i<t;i++){
			if(H[i] == max){
				Volume[cnt]= V[i];
				cnt++;
			}
		}
		sort(Volume,Volume+cnt);
		cout<<Volume[cnt -1]<<endl;
	}
	return 0;
}
