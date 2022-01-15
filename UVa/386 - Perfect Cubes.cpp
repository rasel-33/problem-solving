//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=322


#include <bits/stdc++.h>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--) 
#define pi             acos(-1) 
#define array_sorted   sort(arr,arr+n)        

using namespace std;

//ll i,j,temp,k,a,b,c,l;

void cubee(int n){
	long long cube,temp,i,j,k,l;
	cube = n*n*n;
	for(int i=2;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=j;k<n;k++){
				temp = i*i*i + j*j*j + k*k*k;
				if(temp==cube){
					cout<<"Cube = "<<n<<", Triple = ("<<i<<","<<j<<","<<k<<")"<<endl;
				}
			}
		}
	}
}

int main()
{_
	int x;
	for(x=6;x<=200;x++){
		cubee(x);
	}

return 0;
}
