
//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=516

#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>

using namespace std;

#define ll long long

int main()
{
   ll result =0;

   char number[100];

   while(scanf("%s",number)!=EOF){


      ll len,i,x,cnt =0;

      len = strlen(number);
      if(len==1 && number[0] == '0')
         break;

      for(i=len-1;i>=0;i--){
         x = (int)number[i] - 48;
         result += x*(pow(2,cnt+1) -1);
         cnt++;
      }

      cout<<result<<endl;
      cnt = 0;
      result =0;
   }
   return 0;
}
