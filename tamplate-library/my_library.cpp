///////////////////////////////////seive//////////////////////////
const ll N = 1000006;
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

///////////////////////////////////// Z-Algorithm  /////////////////
vector<ll> z_function(string s) {
    ll n = s.size();
    vector<ll> z(n);
    ll x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0ll,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}
///////////////////////////////////// Z-Algorithm  /////////////////

///////////////////////////find n , x = n*(n+1)/2 //////////////////
ll fun(ll x){
    double n = (-1+sqrt(1+8*x))/2;
    ll nn = n;
    if((n - nn)>EPS) return -1;
    else return nn;
}
///////////////////////////find n , x = n*(n+1)/2 //////////////////

//////////////////////////Find All Permutation /////////////////////
bitset<101> used;
int value_at[101];

void permutation(int pos, int n){
    if(pos == n)
    {
        f0(i, n){
            printf("%d ", value_at[i]);
        }
        printf("\n");
    }

    f1(i, n)if(!used[i]){
        used[i] = 1;
        value_at[pos] = i;
        permutation(pos+1, n);
        used[i] = 0;
    }
}
permutation(0, 4);//calling function

//////////////////////////Find All Permutation /////////////////////


/////////////////////////Prime factorization ///////////////////////
vector<ll> factors(ll n){
    vector<ll> f;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            f.push_back(i);
            n /= i;
        }
    }
    if(n > 1) f.push_back(n);
    return f;
}
/////////////////////////Prime factorization////////////////////////

///////////////////////// String Hashing ///////////////////////////


ll expo(ll a, ll b, ll m){if(b == 0) return 1ll;ll ret = expo(a, b/2, m);ret = (ret%m * ret%m)%m;if(b%2) ret = (ret*a)%m;return ret;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))


struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    Hashing(string a){
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < sz(hashPrimes); i++) {
            powersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
        }
        for(int i = 0; i < sz(hashPrimes); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    void addCharacter(char ch){
        s += ch;
        n = sz(s);
        for(int i = 0; i < sz(hashPrimes); i++){
            while(sz(powersOfBase[i]) < sz(s)){
                powersOfBase[i].pb((powersOfBase[i].back() * base) % hashPrimes[i]);   
            }
        }
        for(int i = 0; i < sz(hashPrimes); i++){
            while(sz(hashValues[i]) < sz(s)){
                if(sz(hashValues[i]) == 0){
                    hashValues[i].pb((s[0] - 'a' + 1LL) % hashPrimes[i]);
                }else{
                    ll extraHash = hashValues[i].back() + ((s.back() - 'a' + 1LL) * powersOfBase[i][sz(s) - 1]) % hashPrimes[i];
                    hashValues[i].pb((extraHash + hashPrimes[i]) % hashPrimes[i]);
                }
            }
        }
    }
    vector<ll> substringHash(int l, int r){ // extra O(log) factor
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), mminvprime(powersOfBase[i][l], hashPrimes[i]), hashPrimes[i]);
        }
        return hash;
    }
    bool compareSubstrings(int l1, int r1, int l2, int r2){ // use this for comparing strings faster
        if(l1 > l2){
            swap(l1, l2);
            swap(r1, r2);
        }
        for(int i = 0; i < primes; i++){
            ll val1 = mod_sub(hashValues[i][r1], (l1 > 0 ? hashValues[i][l1 - 1] : 0LL), hashPrimes[i]);
            ll val2 = mod_sub(hashValues[i][r2], (l2 > 0 ? hashValues[i][l2 - 1] : 0LL), hashPrimes[i]);
            if(mod_mul(val1, powersOfBase[i][l2 - l1], hashPrimes[i]) != val2)
                return false;
        }   
        return true;
    }
};



void sameLengthSubstrings(string &s, int l){
    ll n = s.size();
    ll prevHash = 0;
    ll constant_multiply = mod_div(1,po[1],M);
    for(int i=0;i<l;i++){
        prevHash = (prevHash + (po[i]*(s[i]-'a'+1))%M)%M;
    }
    for(int i=l;i<n;i++){
        prevHash = mod_sub(prevHash, s[i-l]-'a'+1, M);
        prevHash = (prevHash*constant_multiply)%M;
        prevHash = (prevHash + (po[l-1]*(s[i]-'a'+1))%M)%M;
    }
}

///////////////////////// String Hashing ///////////////////////////

////////////////////////mod inverse in linear complexity/////////////
ll p = 31;
void calculate_mo_inv(){
    for(int i=1;i<=1000005;i++){
        mo_inv[i] = expo(p, MOD1-1-i, MOD1);
    }
}
////////////////////////mod inverse in linear complexity/////////////

//////////////////////////Finding the cycle with corresponding nodes/////////////
vector<ll> vis(100005, 0);
vector<ll> par(100005, -1);
ll start_node, end_node;


bool dfs(ll cur, ll parent){
    vis[cur] = 1;
    for(auto child:adj[cur]){
        if(child==parent) continue;
        if(vis[child]){
            start_node = child;
            end_node = cur;
            return true;
        }
        par[child] = cur;
        if(dfs(child, par[child])) return true;
    }
    return false;
}


for(ll i=1; i<=n;i++){
    if(!vis[i] && dfs(i, -1)){
        vector<ll> vt;
        for(ll j=end_node;j!=start_node;j=par[j]){
            vt.push_back(j);
        }
        vt.push_back(start_node);
        if(vt.size()>=k+1){
            cout << vt.size() << endl;
            for(auto it:vt){
                cout << it <<" ";
            }
            cout << endl;
            return;
        }
    }
}
//////////////////////////Finding the cycle with corresponding nodes/////////////
