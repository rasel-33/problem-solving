Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2877



#include<bits/stdc++.h>

using namespace std;

int main(){

   int t,i;

   cin>>t;

   for(i=1;i<=t;i++){

      int arr[7],j;
      double marks=0;
      char ch;

      for(j=0;j<7;j++){
         cin>>arr[j];

      }
      marks =  arr[0] + arr[1]+ arr[2] + arr[3];
      sort(arr+4,arr+7);
      marks = marks + ((double)arr[5] + (double)arr[6])/2;
      
      if(marks>=90){
         ch = 'A';
      }
      else if(marks>=80 && marks<90){
         ch = 'B';
      }
      else if(marks>=70 && marks<80){
         ch = 'C';
      }
      else if(marks>=60 && marks<70){
         ch = 'D';
      }
      else if(marks<60){
         ch = 'F';
      }

      cout<<"Case "<<i<<": "<<ch<<endl;

   }
   return 0;
}
