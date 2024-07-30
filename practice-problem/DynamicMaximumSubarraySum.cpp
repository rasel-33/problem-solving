#include<bits/stdc++.h>
using namespace std;

#define              ll   long long
#define             MOD   1000000007
#define             inf   1e18
#define             EPS   1e-9
 
ll n, x, y, k, q, m, l , r, h;
string  s, sa;




struct DynamicMaxSubarraySum{

    struct node {
        ll sum, pref, suff, ans;
    };

    ll sz;
    vector<node> t;

    DynamicMaxSubarraySum(vector<ll>& a){
        sz = a.size();
        t.resize(sz * 4);
        for(int i = 0; i < 4*sz; i++){
            t[i] = {0, 0, 0, 0};
        }
        build(1, 0, sz - 1, a);
    }

    node merge(node a, node b){
        node c;
        c.sum = a.sum + b.sum;
        c.pref = max(a.pref, a.sum + b.pref);
        c.suff = max(b.suff, b.sum + a.suff);
        c.ans = max(max(a.ans, b.ans), a.suff + b.pref);
        return c;
    }

    void build(ll node, ll l, ll r, vector<ll>& a){
        if(l == r){
            t[node] = {a[l], a[l], a[l], a[l]};
            return;
        }
        ll mid = (l + r) >> 1;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        t[node] = merge(t[node * 2], t[node * 2 + 1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val){
        if(l > idx || r < idx) return;
        if(l == r && l == idx){
            t[node] = {val, val, val, val};
            return;
        }
        ll mid = (l + r) >> 1;
        update(node * 2, l, mid, idx, val);
        update(node * 2 + 1, mid + 1, r, idx, val);
        t[node] = merge(t[node*2], t[node*2 + 1]);
    }

    node query(ll node, ll l, ll r, ll ql, ll qr){
        if(r < ql || l > qr){
            return {0, 0, 0, 0};
        }
        if(ql >= l && qr <= r){
            return t[node];
        }

        ll mid = (l + r) >> 1;
        return merge(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    void update(ll idx, ll val){ // 1 based indexing for calling
        idx--;
        update(1, 0, sz - 1, idx, val);
    }

    node query(ll l, ll r){ // 1 based indexing for calling
        l--;
        r--;
        return query(1, 0, sz - 1, l, r);
    }

};
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    cin >> n;
    vector<ll> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    DynamicMaxSubarraySum sgt(ar);
    sgt.update(1, 0, n-1, 2, 1);
    cout << sgt.query(1, n).ans << endl;
    
    
    return 0;
}
