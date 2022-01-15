//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2093


#include <bits/stdc++.h>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--)
#define pi             acos(-1)

using namespace std;


ll i,j,temp;

int main()
{_
	double a,b,c,s,r,arr[3];
	while(cin>>a>>b>>c){

		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		sort(arr,arr+3);
		r = (a*b*c)/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
		s = (a+b+c)/2;
		//cout<<r<<endl;
		printf("%.4lf",pi*r*r - sqrt(s*(s-a)*(s-b)*(s-c)));
		printf(" %.4lf",sqrt(s*(s-a)*(s-b)*(s-c)) - pi*((s-a)*(s-b)*(s-c))/s);
		printf(" %.4lf\n",pi*((s-a)*(s-b)*(s-c))/s);

	}
	return 0;
}
