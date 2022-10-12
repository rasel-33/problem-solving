#include <bits/stdc++.h>
using namespace std;
#define N        1000005
#define M        1000000007
#define INF      1000000000
#define fast     ios::sync_with_stdio();cin.tie(0)
#define ll       long long
#define endl     "\n"
#define pb       push_back

int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};
ll arr[N];


void solve(int cs){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	vector<int> d(n+1, INF);
	d[0] = -INF;

	for(int i=0;i<n;i++){
		int j = upper_bound(d.begin(), d.end(),arr[i]) - d.begin();
		if(d[j-1]<arr[i] && arr[i]<d[j]){
			d[j] = arr[i];
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
	
		if(d[i]<INF)
			ans = i;
	}

	cout << ans << endl;

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
