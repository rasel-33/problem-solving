//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=435

#include<bits/stdc++.h>
using namespace std;

int main(){
	
    string str;
    while(getline(cin,str)){
        int len = str.size();
        int count=0;
        bool letter= false;
        for(int i=0;i<=len;i++){
            int j=i;
            if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
                while((str[j]>='A' && str[j]<='Z') || (str[j]>='a' && str[j]<='z')){
                    j++;
                    if(j==len){
                        break;
                    }
                }
                count++;
                i = j;
            }
        }
        cout<<count<<endl;
        
    }

return 0;
}
