//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4442


#include<stdio.h>
#include<math.h>
int square(int n){
    if(n==0){
        return 0;
    }
    else return n*n;
}


int main()
{
    int x,y,r,N,i,sum;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        double large,small;
        double extra;

        scanf("%d %d %d",&x,&y,&r);

        sum = square(x) + square(y);
        extra = sqrt(sum);
        small = r - extra;
        large = r + extra;

        printf("%.2lf %.2lf\n",small,large);
    }
    return 0;
}
