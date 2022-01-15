//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=310


#include<iostream>
#include<stdio.h>

using namespace std;

long long mod(long long base,long long power,long long modulo){
   long long result=1;
   base =base%modulo;
   while(power>0){
      if(power%2==1){
         result = (result*base)%modulo;
      }
      power/=2;
      base = (base*base)%modulo;
   }
   return result;
}

int main(){
   long long b,p,m;
   while(cin>>b>>p>>m){
      cout<<mod(b,p,m)<<endl;
   }
   return 0;
}
