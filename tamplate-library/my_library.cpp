//Find All Divisors/////////////////
vector<ll>divisors[1000006];
void factorize(){
    for(ll i=1;i<1000006;i++){
        for(ll j=i;j<1000006;j+=i){
            divisors[j].pb(i);
        }
    }
}
//Find All Divisors////////////////

//Dearrangement of n///////////////
ll dp[1000006];

ll dearrangement(ll n){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dp[n]) return dp[n];
    return dp[n] = (n-1)*(dearrangement(n-1) + derangement(n-2));
}
//Dearrangement of n///////////////



//Prime factorization ///////////////////////
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
//Prime factorization////////////////////////

//Prime factorization////////////////////////
#define MAXN 1000001

ll spf[MAXN];
 
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) spf[i] = i;
    for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

vector<ll> getPrimeFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
//Prime factorization////////////////////////

//seive///////////////////////////
#define N  1000006
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
//seive/////////////////////////

//Segmented seive//////////////////
vector<ll>pr;
bool mark[1000006];
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
//Segmented seive//////////////////

//Sum of divisora
long long SumOfDivisors(long long num) {
    long long total = 1;

    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);

            long long sum = 0, pow = 1;
            do {
                sum += pow;
                pow *= i;
            } while (e-- > 0);
            total *= sum;
        }
    }
    if (num > 1) {
        total *= (1 + num);
    }
    return total;
}
//Sum of divisora

//Number of divisors
long long numberOfDivisors(long long num) {
    long long total = 1;
    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}
//Number of divisors


//value of nCr with mod m//////////
ll ncr(ll n, ll r, ll m){
    ll res = 1;
    if(r > n - r) r = n - r;
    for(ll i = 0; i < r; i++){
        res = (res * (n - i)) % m;
        res = (res * ModInv(i + 1, m)) % m;
    }
    return res;
}
//value of nCr with mod m//////////

//value of nCr ////////////////////
ll N = 2000006;
ll fact[N], invfact[N];

void precompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    invfact[N-1]=mminvprime(fact[N-1], MOD);
    for(int i=N-2;i>0;i--)
    {
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=MOD;
    }
}


ll nCr(ll x, ll y)
{
    if(x == y) return 1;
    if(y>x)return 0;
    ll num=fact[x];
    num*=invfact[y];
    num%=MOD;
    num*=invfact[x-y];
    num%=MOD;
    return num;
}
//value of nCr ////////////////////

//Disjoint Set Union///////////
struct DSU {
    vector<ll> par, sz;
    DSU(ll n) {
        par.resize(n+1);
        sz.resize(n+1);
        for(ll i=1;i<=n;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    ll find(ll u) {
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    void merge(ll u, ll v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }
};
//Disjoint Set Union///////////

/ Z-Algorithm  /////////////////
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
/ Z-Algorithm  /////////////////

//find n , x = n*(n+1)/2 //////////////////
ll fun(ll x){
    double n = (-1+sqrt(1+8*x))/2;
    ll nn = n;
    if((n - nn)>EPS) return -1;
    else return nn;
}

n+(n-1)+(n-2)----(n-x) = (x+1)*(2*n-x)/2;
//find n , x = n*(n+1)/2 //////////////////

//Find All Permutation /////////////////////
vector<ll> vt = {2, 5, 3};
do{
    for(int i=0;i<vt.size();i++){
        cout << vt[i]<<" ";
    }
    cout << endl;
}while(next_permutation(vt.begin(), vt.end()));

//Find All Permutation /////////////////////


/ String Hashing ///////////////////////////


ll expo(ll a, ll b, ll m){if(b == 0) return 1ll;ll ret = expo(a, b/2, m);ret = (ret%m * ret%m)%m;if(b%2) ret = (ret*a)%m;return ret;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))


struct Hashing{
    string s;
    ll n;
    ll primes;
    ll base = 31;
    vector<ll> hashPrimes = {998244353, 972663749};
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowerOfBase;
 
    Hashing(string a){
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowerOfBase.resize(primes);
        s = a;
        n = s.size();
 
        for(int i=0;i<primes;i++){
            powersOfBase[i].resize(n+1);
            powersOfBase[i][0] = 1;
            for(int j=1;j<=n;j++){
                powersOfBase[i][j] = (powersOfBase[i][j-1]*base)%hashPrimes[i];
            }
            inversePowerOfBase[i].resize(n+1);
            inversePowerOfBase[i][n] = expo(powersOfBase[i][n], hashPrimes[i]-2, hashPrimes[i]);
            for(int j=n-1;j>=0;j--){
                inversePowerOfBase[i][j] = (inversePowerOfBase[i][j+1]*base)%hashPrimes[i];
            }
        }
        for(int i=0;i<primes;i++){
            hashValues[i].resize(n);
            for(int j=0;j<n;j++){
                hashValues[i][j] = (j==0 ? 0 : hashValues[i][j-1]);
                hashValues[i][j] = (hashValues[i][j] + (s[j]-'a'+1)*powersOfBase[i][j])%hashPrimes[i];
            }
        }
    }
    void addCharacter(char c){
        n++;
        s += c;
        for(int i=0;i<primes;i++){
            while(powersOfBase[i].size() < n){
                powersOfBase[i].push_back((powersOfBase[i].back()*base)%hashPrimes[i]);
                inversePowerOfBase[i].push_back((inversePowerOfBase[i].back()*expo(base, hashPrimes[i]-2, hashPrimes[i]))%hashPrimes[i]);
            }
        }
        for(int i=0;i<primes;i++){
            while(hashValues[i].size() < n){
                if(hashValues[i].empty()){
                    hashValues[i].push_back((c-'a'+1)%hashPrimes[i]);
                }
                hashValues[i].push_back((hashValues[i].back() + (c-'a'+1)*powersOfBase[i][n-1])%hashPrimes[i]);
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> res;
        for(int i=0;i<primes;i++){
            ll hashValue = hashValues[i][r];
            if(l > 0){
                hashValue = (hashValue - hashValues[i][l-1] + hashPrimes[i])%hashPrimes[i];
            }
            hashValue = (hashValue*inversePowerOfBase[i][l])%hashPrimes[i];
            res.push_back(hashValue);
        }
        return res;
    }
    bool compareSubstrings(int l1, int r1, int l2, int r2){
        if(r1-l1 != r2-l2){
            return false;
        }
        vector<ll> hash1 = substringHash(l1, r1);
        vector<ll> hash2 = substringHash(l2, r2);
        return hash1 == hash2;
    }
    vector<vector<ll>> samelengthSubstringHashes(int l){
        vector<vector<ll>> res;
        for(int i=0;i<primes;i++){
            vector<ll> hh;
            ll prevHash = 0;
            ll constant_multiply = inversePowerOfBase[i][1];
            for(int j=0;j<l;j++){
                prevHash = ((prevHash + ((s[j]-'a'+1)*powersOfBase[i][j])%hashPrimes[i]))%hashPrimes[i];
            }
            hh.push_back(prevHash);
            for(int j=l;j<n;j++){
                prevHash = mod_sub(prevHash, s[j-l]-'a'+1, hashPrimes[i]);
                prevHash = (prevHash*constant_multiply)%hashPrimes[i];
                prevHash = (prevHash + ((s[j]-'a'+1)*powersOfBase[i][l-1])%hashPrimes[i])%hashPrimes[i];
                hh.push_back(prevHash);
            }
            res.push_back(hh);
        }
        return res;
    }
};
// String Hashing ///////////////////////////

//Finding the cycle with undirected nodes/////////////
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
//Finding the cycle with corresponding nodes/////////////

//Segment Tree with single value ////////////////////////
ll sz, maxn;
ll t[4*maxn];

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void init(ll ar[], ll n){
    sz = n;
    build(ar, 1, 0, sz-1);
}

void setValue(ll idx, ll val){
    update(1, 0, sz-1, idx-1, val);
}

ll getQuery(ll l, ll r){
    return query(1, 0, sz-1, l-1, r-1);
}
//Segment Tree with single value ////////////////////////

/Segment tree with muiltiple values/////////////////////
struct item {
    ll sum, pref, suff, ans;
};

ll sz, maxn;
item t[4*maxn];
 
item combine(item l, item r) {
    item res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
 
item make_item(ll val) {
    item res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0ll, val);
    return res;
}
 
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = make_item(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
 
void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = make_item(new_val);
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
 
item query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return make_item(0);
    if (l == tl && r == tr) 
        return t[v];
    ll tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void init(ll ar[], ll n){
    sz = n;
    build(ar, 1, 0, sz-1);
}

void setValue(ll idx, ll val){
    update(1, 0, sz-1, idx-1, val);
}

item getQuery(ll l, ll r){
    return query(1, 0, sz-1, l-1, r-1);
}
///Segment tree with muiltiple values/////////////////////

// another way to implement binary search
ll binarySearch(ll x){
    int lo = -1, hi = n;
    while(hi > lo+1){
        int mid = (lo + hi)/2;
        if(ar[mid]<=x){
            lo = mid;
        }
        else hi = mid;
    }
    return lo;
}


//  Topological Sorting of a Directed Graph ////////////// 
class Graph {
    int V; // Number of vertices
    vector<set<int>> adj; // Adjacency list representation

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].insert(w);
    }

    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        if (!visited[v]) {
            visited[v] = true;
            recStack[v] = true;

            for (int i : adj[v]) {
                if (!visited[i] && isCyclicUtil(i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
        recStack[v] = false; // Remove the vertex from recursion stack
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int u = 0; u < V; u++) {
            if (isCyclicUtil(u, visited, recStack))
                return true;
        }
        return false;
    }
};

// Floyd Warshall
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
// Floyd Warshall

// BEllman ford algorithm
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int>& d) {
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
// BEllman ford algorithm

//Dijkstra algo
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
//Dijkstra algo

//KMP
int failure[1000006];
bool ok;

void build_failure(string pattern){
	int m = pattern.size();
	int j = 0;
	failure[0] = 0;
	for(int i=1;i<m;i++){
		while(j>0 && pattern[j]!=pattern[i]){
			j = failure[j-1];
		}
		if(pattern[j]==pattern[i]){
			j++;
		}
		failure[i] = j;
	}
}


void KMP(string text, string pattern){
	int m = pattern.size();
	int j=0;
	for(int i=0;i<text.size();i++){
		while(j>0 && text[i]!=pattern[j]){
			j = failure[j-1];
		}
		if(text[i]==pattern[j]){
			j++;
		}
		if(j==m){
			ok = true;
			cout << i-m+1 << endl;
			j = failure[j-1];
		}
	}
}
//KMP


//Trie
struct node{
    int flag;
    node* next[26]={NULL};
};

node* root = new node;

void insert(string word){
    node* it = root;
    for(int i=0;i<word.size();i++){
        if(it->next[word[i]-'a']==NULL)
            it->next[word[i]-'a'] = new node;
        it = it->next[word[i]-'a'];
    }
    it->flag ++;
}

bool search(string word){
    node* it = root;
    for(int i=0;i<word.size();i++){
        if(it->next[word[i]-'a']==NULL)
            return false;
        it = it->next[word[i]-'a'];
    }
    if(it->flag)
        return true;
    return false;
}

//Trie

//Strongly Connected Components
vector<ll> adj[MAXN], adj_rev[MAXN];
bool vis[MAXN];

vector<ll> order, component;

void dfs1(ll node){
    vis[node] = 1;
    for(auto child:adj[node]){
        if(!vis[child]){
            dfs1(child);
        }
    }
    order.push_back(node);
}

void dfs2(ll node){
    vis[node] = 1;
    component.push_back(node);
    for(auto child:adj_rev[node]){
        if(!vis[child]){
            dfs2(child);
        }
    }
}

vector<vector<ll>> findSCC(){
    for(int i=1;i<=n;i++) vis[i] = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs1(i);
    }
    for(int i=1;i<=n;i++) vis[i] = 0;
    reverse(order.begin(), order.end());
    vector<vector<ll>> SCC;
    for(auto u:order){
        if(!vis[u]){
            component.clear();
            dfs2(u);
            SCC.push_back(component);
        }
    }
    return SCC;
}
//Strongly Connected Components

//Lazy Propagation
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2 + 1]);
    }
}

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l == tl && tr == r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

//Lazy Propagation

//The number of relative primes in a given interval
int solve (int n, int r) {
    vector<int> p;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            p.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back (n);

    int sum = 0;
    for (int msk=1; msk<(1<<p.size()); ++msk) {
        int mult = 1,
            bits = 0;
        for (int i=0; i<(int)p.size(); ++i)
            if (msk & (1<<i)) {
                ++bits;
                mult *= p[i];
            }

        int cur = r / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }

    return r - sum;
}
//The number of relative primes in a given interval

//number of ones on (i-1)th bit in numbers ( 0 - num);
ll cntOne(ll num, ll i){
    ll seg = (1ll<<i);
    ll ones = (num / seg) * (seg/2);
    ll rones = ((num % seg) <= seg/2) ? 0: (num % seg) - seg/2;
    return ones + rones;
}
//number of ones on (i-1)th bit in numbers ( 0 - num);
//Diameter using DP
vector<ll> adj[101];
vector<ll> toLeaf(101);
vector<ll> diameter(101, 0);

ll findtoLeaf(ll node, ll par){
    toLeaf[node] = 0;
    for(auto it:adj[node]){
        if(it != par){
            toLeaf[node] = max(toLeaf[node], 1 + (findtoLeaf(it, node)));
        }
    }
    return toLeaf[node];
}

void findDiameter(ll node, ll par){
    vector<ll> vt;
    ll mx1 = 0, mx2 = 0;
    for(auto it:adj[node]){
        if(it != par){
            findDiameter(it, node);
            vt.push_back(toLeaf[it]);
        }
    }
    sort(vt.rbegin(), vt.rend());
    for(int i = 0; i < 2 && i < vt.size(); i++){
        diameter[node] += vt[i]+1;
    }
}

    findtoLeaf(1, 0);
    findDiameter(1, 0);
    for(int i = 1; i <= n; i++){
        cout << toLeaf[i] <<" ";
    }
    cout << endl;

    for(int i = 1; i <= n; i++){
        cout << diameter[i] <<" ";
    }
    cout << endl;
//Diameter using DP


// Binary Indexed Tree
struct BIT {
    vector<ll> bit;
    BIT(vector<ll> a) {
        bit = vector<ll>(a.size() + 1, 0);
        for (int i = 0; i < a.size(); i++) {
            add(i + 1, a[i]);
        }
    }
    void add(int i, ll x) {
        for (; i < bit.size(); i += i & -i) {
            bit[i] += x;
        }
    }
    ll sum(int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void increase(int i, ll x) {
        for (; i < bit.size(); i += i & -i) {
            bit[i] += x;
        }
    }
    void update(int i, ll x) {
        add(i, x - sum(i, i));
    }
};

// Binary Indexed Tree 
