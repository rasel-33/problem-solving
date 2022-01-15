#include<bits/stdc++.h>
using namespace std;



int main()
{
    
    int i,fp,sp,tp;
    while(cin>>i>>fp>>sp>>tp){
        if(i==0 && fp==0 && sp==0 && tp==0){
            break;
        }
        int res =1080;

        if(i<fp){
            res += 9*(i+40-fp);
        }
        else{
            res += 9*(i-fp);
        }
        if(sp<fp){
            res+= 9*(sp+40-fp);
        }
        else{
            res+= 9*(sp-fp);
        }
        if(sp<tp){
            res += 9*(sp+40 - tp);
        }
        else{
            res += 9*(sp - tp);
        }
        
        cout<<res<<endl;

    }



return 0;
}
