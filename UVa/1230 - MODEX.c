//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3671


#include <stdio.h>

long long MODEX(long long base,long long power,long long mod){
	long long result = 1;
	base %= mod;
	while(power>0){
		if(power%2)
			result = (result * base) % mod;
		base = (base*base) % mod;
		power >>=1;
	}
	return result;
}

int main()
{
	long long tc;
	while(scanf("%lld",&tc)!=EOF && tc!=0){
		while(tc--){
			long long x,y,n;
			scanf("%lld %lld %lld",&x,&y,&n);
			printf("%lld\n",MODEX(x,y,n));
		}
	}
	return 0;
}
