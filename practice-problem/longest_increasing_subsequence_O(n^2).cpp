#include <bits/stdc++.h>
using namespace std;
#define N        1000005
ll arr[N];


void solve(int cs){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	int lis[n];
	int p[n];
	memset(p, -1, sizeof(p));

	for(int i=0;i<n;i++){
		int mx = 1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				if(lis[j]+1>mx){
					mx = lis[j]+1;
					p[i] = j;
				}
			}
		}
		lis[i] = mx;
	}
	int ans = -1;
	int idx;
	for(int i=0;i<n;i++){
		if(ans<lis[i]){
			ans = lis[i];
			idx = i;
		}
	}
	
	vector<int> vt;
	while(idx!=-1){
		vt.push_back(arr[idx]);
		idx = p[idx];
	}
	
	reverse(vt.begin(), vt.end());
	cout << ans << endl;
	for(int i=0;i<vt.size();i++){
		cout << vt[i] <<" ";
	}
	cout << endl;


}
 
 
int main(){
    
    int tc = 1,cs = 1;
    // cin >> tc;
    while(tc--){
        solve(cs);
        cs++;
    }
return 0;
}
