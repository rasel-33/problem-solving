#include <bits/stdc++.h>
using namespace std;
#define N        1000005
#define M        1000000007
#define fast     ios::sync_with_stdio();cin.tie(0)
#define ll       long long
#define endl     "\n"
#define pb       push_back
 
int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};
 
 
 
 
void solve(int cs){
	int n;
	cin >> n;
	int k = log2(n);
	ll st[n+1][k+1];
	ll arr[n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
		st[i][0] = arr[i];
	}

	for(int j=1;j<=k;j++){
		for(int i=0;i+(1<<j)<=n;i++){
			st[i][j] = min(st[i][j-1] , st[i+(1<<(j-1))][j-1]);
		}
	}

	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int j = log2(r-l+1);
		cout << min(st[l][j], st[r-(1<<j)+1][j])<<endl;;

	}

	

}
 
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
    fast;
    
    int tc = 1,cs = 1;
    // cin >> tc;
    while(tc--){
        solve(cs);
        cs++;
    }
return 0;
}
