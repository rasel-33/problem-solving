//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2412



#include <bits/stdc++.h>

#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--)
#define pi             acos(-1)
#define max            1000000001

using namespace std;


ll i,j,temp;
bitset<max> prime;
vector<int> prime_numbers;
vector<int>::iterator it;

int GCD(int x,int y){
	int smaller,greater;
	if(x<y){
		smaller = x;
		greater = y;
	}
	else if(x==y){
		return x;
	}
	else{
		smaller = y;
		greater = x;
	}
	while(greater%smaller!=0){
		temp = greater%smaller;
		greater = smaller;
		smaller = temp;

	}
	return smaller;
}
int main()
{_
	int n;
	while(scanf("%d",&n)!=EOF){
	long long count=0;
	if(n==0)
		break;
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			count += GCD(i,j);
		}
	}
	printf("%lld\n",count);
	}
	return 0;
}
