#include<bits/stdc++.h>
#define tc()       int t_case;scanf("%d",&t_case);while(t_case--)
#define MX         1000006
#define ll         long long
#define BASE       263
#define M          1000000007
 
 
using namespace std;

int is_comp[MX];
int par[MX];

vector<int> primes;

void seive()
{
    for(int i = 2;i * i <= MX;i++)
    {
        if(!is_comp[i]){
            for(int j = i * i;j <= MX;j += i)
            {
                is_comp[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<=MX;i+=2){
        if(!is_comp[i])
            primes.push_back(i);
    }
}

vector<int> get_primefact(int n){
    vector<int> primefact;
    for(int i = 0;i < primes.size() && primes[i]*primes[i] <= n;i++){
        if(n%primes[i]==0){

            primefact.push_back(primes[i]);
            while(n%primes[i]==0){
                n /= primes[i];
            }
        }
    }
    if(n > 1) primefact.push_back(n);
    return primefact;
}

int get_parent(int u){
    if(par[u]==u) return u;
    return par[u] = get_parent(par[u]);
}

void update(int u,int v){
    int pv = get_parent(v);
    int pu = get_parent(u);
    if(pu != pv)
        par[pu] = pv;
}
 
int main()
{
    
    seive();
    int cas=1;
    tc(){
        int n;
        scanf("%d",&n);

        int val[n],onecnt=0;
        for(int i=1;i<MX;i++) par[i] = i;


        for(int i = 0;i < n;i++){
            scanf("%d",&val[i]);
            if(val[i]==1)onecnt++;
            else{
                vector<int> pubs = get_primefact(val[i]);
                for(int j=0;j<pubs.size();j++){
                    
                    update(pubs[j],val[i]);
                }
                
            }

        }
        set<int> st;
        for(int i=0;i<n;i++){
            if(val[i]>1){
                int pp = get_parent(get_parent(val[i]));
                
                st.insert(pp);
            }
        }
        printf("Case %d: %d\n",cas++,onecnt+(int)st.size());

    }
    return 0;
}
