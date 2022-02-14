#include<bits/stdc++.h>
using namespace std;
#define MX      5000006
bool is_composite[MX];
vector<int> primes;


void seive(){
    for(int i = 2; i*i <= MX ;i++){
        if(!is_composite[i])
            for(int j = i*i ;j<MX;j+=i)is_composite[j] = 1;
    }
    primes.push_back(2);
    for(int i = 3;i<MX;i+=2){
        if(!is_composite[i])primes.push_back(i);
    }
    
}

int main(){
    
    seive();
    
    return 0;
}
