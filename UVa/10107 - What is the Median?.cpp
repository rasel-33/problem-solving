#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    
    vector<int> fv;
    ll x,i=0;
    while(cin>>x){
        
        fv.push_back(x);
        sort(fv.begin(),fv.end());
        if(i%2==0){
            ll half_i;
            half_i = i/2;
            cout<<fv[half_i]<<endl;
           
       }
        else{
          
          ll half_i;
          half_i = i/2;
          cout<<int(((fv[half_i +1] + fv[half_i])/2))<<endl;
       }
       
        i++;
    }
    return 0;
}
