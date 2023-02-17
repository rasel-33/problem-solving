
///////////////////////////////////seive//////////////////////////
const ll N = 1000000;
bitset<N> bt;
vector<ll> primes;
void sieve(){
    bt.set();
    bt[0] = bt[1] = 0;
    for(ll i = 2; i < N; i++){
        if(bt[i]){
            for(ll j = i*i; j < N; j+=i){
                bt[j] = 0;
            }
            primes.push_back(i);
        }
    }
}
///////////////////////////////////seive/////////////////////////

//////////////////////////////////Segmented seive//////////////////
vector<ll>pr;
bool mark[1000005];
void seive(ll n){
    ll i, j, limit = sqrt(n*1.0) + 2;
    mark[1] = 1;
    for(i = 4; i <= n; i += 2)mark[i] = 1;
    pr.push_back(2);
    for(i = 3; i <= n; i += 2){
        if(!mark[i]){
            pr.push_back(i);
            if(i <= limit){
                for(j = i*i; j <= n; j += i*2){
                    mark[j] = 1;
                }
            }
        }
    }
}
void segmented_seive(ll l, ll r){
    if(l == 1)l++;
    ll i, j, limit = sqrt(r) + 2;
    seive(limit);
    memset(mark, 0, sizeof mark);
    for(i = 0; i < pr.size(); i++){
        ll loLim = floor(l/pr[i]) * pr[i];
        if(loLim < l)loLim += pr[i];
        for(j = loLim; j <= r; j += pr[i]){
            mark[j-l] = 1;
        }
    }
    for(i = l; i <= r; i++){
        if(!mark[i-l])cout << i << endl;
    }
}
//////////////////////////////////Segmented seive//////////////////

//////////////////////////////////Find All Divisors////////////////
vector<ll>divisors[1000006];
void factorize(){
    for(ll i=1;i<=1000006;i++){
        for(ll j=i;j<=1000006;j+=i){
            divisors[j].pb(i);
        }
    }
}
//////////////////////////////////Find All Divisors////////////////

//////////////////////////////////value of nCr with mod m//////////
ll ncr(ll n, ll r, ll m){
    ll res = 1;
    if(r > n - r) r = n - r;
    for(ll i = 0; i < r; i++){
        res = (res * (n - i)) % m;
        res = (res * ModInv(i + 1, m)) % m;
    }
    return res;
}
//////////////////////////////////value of nCr with mod m//////////

//////////////////////////////////value of nCr ////////////////////
ll ncr(ll n, ll r){
    ll ans = 1;
    if(r > n-r) r = n-r;
    for(ll i = 0; i < r; i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}
//////////////////////////////////value of nCr ////////////////////
