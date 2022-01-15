#include<stdio.h>
int cycle(long long  i){
    long long  cnt=0;
    while(1){
            cnt++;
            if(i == 1) break;
            else if(i%2 != 0) i = 3*i + 1;
            else if(i%2 == 0) i = i/2;
    }
    return cnt;
}
int main()
{
    long long  N,cnt,i,j,I,max,a,b;

    while(scanf("%lld %lld",&i,&j)!=EOF){
            if(i<j){
                a=i;
                b=j;
            }
            else{
                a=j;
                b=i;
            }
        max = 0;
        for(I=a;I<=b;I++){
            cnt = cycle(I);
            if(cnt>=max){
                max = cnt;
            }
        }
        printf("%lld %lld %lld\n",i,j,max);

    }
    return 0;
}
