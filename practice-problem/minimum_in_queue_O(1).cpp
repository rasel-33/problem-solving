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
ll arr[N];


void solve(int cs){
	int n;
	cin >> n;
	queue<int> q;
	deque<int> min;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		q.push(arr[i]);
		while(!min.empty() && min.back()>arr[i])
			min.pop_back();
		min.push_back(arr[i]);
	}

	int qr;
	cin >> qr;
	// 0 -> adding
	// 1 -> removing
	// 2 -> minimum
	for(int i=0;i<qr;i++){
		int x; 
		cin >> x;
		if(x==0){
			int y;
			cin >> y;
			q.push(y);
			while(!min.empty() && min.back()>y)
				min.pop_back();
			min.push_back(y);
		}
		else if(x==1){
			int remove_ele = q.front();
			q.pop();
			if(min.front()==remove_ele){
				min.pop_front();
			}
		}
		else{
			cout << min.front() << endl;
		}
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
