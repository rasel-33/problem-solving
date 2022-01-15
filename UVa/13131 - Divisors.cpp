//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5042


#include<bits/stdc++.h>

#define tc()                int tc;scanf("%d",&tc);while(tc--)
#define endl                "\n"
#define ll                  long long
#define M                   1000000007
#define MX                  100005
double pi =                 2 * acos(0);
long long inf = 1e18;
ll dr[] = { -1, 1, 0, 0, -1, 1, -1, 1};
ll dc[] = {0, 0, -1, 1, -1, -1, 1, 1};


using namespace std;

bool is_comp[MX];
vector<int> prime;
void seive() {
    for (int i = 2; i * i <= MX; i++) {
        if (!is_comp[i]) {
            for (int j = i * i; j < MX; j += i) {
                is_comp[j] = 1;

            }
        }
    }
    for (int i = 2; i < MX; i++) {
        if (!is_comp[i]) {
            prime.push_back(i);
        }
    }
    prime.push_back(2);
    for (int i = 3; i < MX; i += 2) {
        if (!is_comp[i]) {
            prime.push_back(i);
        }
    }
}


ll binpow(int base,int pow){
    if(pow==0) return 1;
    if(pow%2==0){
        ll half = binpow(base,pow/2);
        return half*half;
    }
    return base*binpow(base,pow-1);
}



int main()
{
    
    tc(){
        int n,k;
        scanf("%d %d",&n,&k);
        int cnt =0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int temp = n/i;
                if(i%k){
                    cnt += i;
                }
                if(temp%k && temp!=i){
                    cnt += temp;
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
