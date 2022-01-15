//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=424


#include <iostream> 
#include <string> 
#include <cstring>

using namespace std; 
  
int main() 
{ 
   string sentence;

   while(getline(cin,sentence)){

      int len = 0,cnt = 0,j = 0,i,k;

      while(sentence[len]!='\0'){
         len++;
      }

      char word[200][30];

      for(i=0;i<=len;i++){

         if(sentence[i]==' ' || sentence[i] == '\0'){
            word[cnt][j] = '\0';
            cnt++;
            j = 0;

         }
         else{
            word[cnt][j] = sentence[i];
            j++;
         }
      }
      

      for(i=0;i<cnt;i++){

         int small_len =0,half_len;

         while(word[i][small_len]!='\0'){

            small_len++;
         }
         
         half_len = small_len/2;

         for(j=0,k=small_len-1;j<k;j++,k--){

            char temp;
            temp = word[i][j];
            word[i][j] = word[i][k];
            word[i][k] = temp;
            
         }
         if(i == (cnt-1)){
            cout<<word[i]<<endl;
         }
         else{
            cout<<word[i]<<" ";
         }
      }

   }
   return 0; 
}
