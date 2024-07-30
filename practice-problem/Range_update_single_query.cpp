#include<bits/stdc++.h>
using namespace std;

#define              ll   long long
#define             MOD   1000000007
#define             inf   1e18
#define             EPS   1e-9
 
ll n, x, y, k, q, m, l , r, h;
string  s, sa;

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


 
int main(){
    
    cin >> n >> q;
    vector<ll> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    vector<ll> diff(n); // difference array
    diff[0] = ar[0];
    for(int i = 1; i < n; i++){
        diff[i] = ar[i] - ar[i-1];
    }

    BIT bits(diff);

    while(q--){
        ll type;
        cin >> type;
        if(type == 1){
            ll val;
            cin >> x >> y >> val;
            bits.increase(x, val);
            bits.increase(y+1, -val);
        }
        else{
            cin >> x;
            cout << bits.sum(1, x) << endl;
        }
    }
    return 0;
}
