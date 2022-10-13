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
	vector<int> arr(n+2, INT_MIN);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}

	int left[n+1];
	int right[n+1];
	int total[n+1];

	int lst = INT_MIN,cnt=0;

	for(int i=1;i<=n;i++){
		if(lst<arr[i]){
			lst = arr[i];
			cnt = 1;
		}
		else{
			lst = arr[i];
			cnt++;
		}
		left[i] = cnt;
	}
	lst = INT_MIN;
	cnt = 0;
	
	for(int i=n;i>=1;i--){
		if(lst<arr[i]){
			lst = arr[i];
			cnt = 1;
		}
		else{
			lst = arr[i];
			cnt++;
		}
		right[i] = cnt;
	}
	int mx = -1; 

	for(int i=1;i<=n;i++){
		total[i] = (left[i]+right[i]-1)*arr[i];
		mx = max(mx, total[i]);
	}

	cout << mx << endl;



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
