#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int n,i;
	while(scanf("%u",&n)==1){
		if(n==0) break;
		unsigned cnt=0,len;
		len = sqrt(n);
		
		if(len*len == n){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}
