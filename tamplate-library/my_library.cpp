
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


///////////////////////////////////////segment tree////////////////
ll tree[4000009];
void build(ll node, ll b, ll e){
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}
ll query(ll node, ll b, ll e, ll i, ll j){
    if(i > e || j < b)return 0;
    if(b >= i && e <= j)return tree[node];
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}
void update(ll node, ll b, ll e, ll i, ll newvalue){
    if(i > e || i < b)return;
    if(b >= i && e <= i){
        tree[node] = newvalue;
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node] = tree[left] + tree[right];
}

///////////////////////////////////////segment tree////////////////

//////////////////////////////////////Disjoint Set Union///////////
ll par[1000006];
ll cnt[1000006];
void init(ll n){
    for(ll i = 0; i <= n; i++){
        par[i] = i;
        cnt[i] = 1;
    }
}
ll find(ll x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}
void Union(ll x, ll y){
    ll u = find(x);
    ll v = find(y);
    if(u == v) return;
    if(cnt[u] > cnt[v]) swap(u, v);
    par[u] = v;
    cnt[v] += cnt[u];
}
//////////////////////////////////////Disjoint Set Union///////////

