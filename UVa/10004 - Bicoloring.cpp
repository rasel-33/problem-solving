#include<bits/stdc++.h>

using namespace std;

int main(){
	int node;
	while(scanf("%d",&node)){
		if(node==0)
			break;
		bool vis[node+1];
		bool bipartite = true;
		for(int i=0;i<node+1;i++){
			vis[i] = false;
		}
		vector<int> arr[node];
		int n;
		scanf("%d",&n);
		int a,b;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		queue<int> q;
		int color[node];
		for(int i=0;i<node;i++){
			color[i] = -1;
		}
		q.push(0);
		color[0] = 1;
		while(!q.empty()){
			int temp = q.front();
			if(vis[temp]==true){
				q.pop();
			}
			else{
				q.pop();
				vis[temp] = true;
				for(int i=0;i<arr[temp].size();i++){
					q.push(arr[temp][i]);
					if(color[arr[temp][i]]==-1){
						color[arr[temp][i]] = !color[temp];
					}
					else{
						if(color[arr[temp][i]]==color[temp]){
							bipartite = false;
							break;
						}
					}
				}
			}
				
		}
		if(bipartite){
			printf("BICOLORABLE.\n");
		}
		else{
			printf("NOT BICOLORABLE.\n");
		}

	}
	return 0;
}
