//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4375


#include<stdio.h>
int main()
{
    int a,b,c;
    char x;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        if((a==1 && b==0 && c==0) || (a==0 && b==1 && c==1)){
            x='A';
        }
        else if((b==1 && a==0 && c==0) || (b==0 && a==1 && c==1)){
            x='B';
        }
        else if((c==1 && a==0 && b==0) || (c==0 && a==1 && b==1)){
            x='C';
        }
        else if((a==0 && b==0 && c==0 ) || (a==1 && b==1 && c==1)){
            x='*';
        }
        printf("%c\n",x);
    }
    return 0;
}
