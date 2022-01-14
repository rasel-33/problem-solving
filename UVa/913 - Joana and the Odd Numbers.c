
//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=854

#include<stdio.h>

int main(){
	long long n;
    while(scanf("%lld",&n)!=EOF){
        if(n==1){
            printf("1\n");
        }
        else{
            long long temp = n/2+1;
            temp*=temp;
            temp = 2*temp-1;
            long long ans = temp*3 -6;
            printf("%lld\n",ans );
        }
    }
	
	
return 0;
}
