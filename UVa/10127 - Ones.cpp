#include<bits/stdc++.h>

using namespace std;

int main(){

    long long x;
    while(scanf("%lld",&x)!=EOF){
        long long total_one = 0,gg = x,cnt = 0;
        int ldigit = gg%10;
        while(gg!=0){
            cnt = 0;
            while(ldigit!=1){
                gg += x;
                ldigit = gg%10;
            }
            while(ldigit==1){
                gg /= 10;
                ldigit = gg%10;
                cnt++;
            }
            total_one += cnt;   
        }
        printf("%lld\n",total_one);
            
    }
    return 0;
}
