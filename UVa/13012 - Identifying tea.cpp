//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=866&page=show_problem&problem=4900


#include <stdio.h>

int main()
{
  int T;
    
  while(scanf("%d",&T)==1){
        int x,count =0;
        for(int i=0;i<5;i++){
            scanf("%d",&x);
            if(x==T)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
