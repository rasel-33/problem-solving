#include <bits/stdc++.h>
using namespace std;

#define EPS      1E-9
#define PI       acos(-1)
#define N        1000006
#define M        1000000007
#define fast     ios::sync_with_stdio();cin.tie(0)
#define ll       long long
#define endl     "\n"
#define pb       push_back
#define base     179

int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};

int getINT(char ch){
    if(ch >= '0' && ch <= '9') return ch - '0';
    else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
    else return ch - 'a' + 36;
}

//aho corasick dictionary link
int trie[N][62], failure[N], sz = 1, str[N];
vector<int> endNode[N];

void insert(string s, int id){
    int cur = 0;
    for(int i = 0; i < s.size(); i++){
        int c = getINT(s[i]);
        if(trie[cur][c] == 0) trie[cur][c] = sz++;
        cur = trie[cur][c];
    }
    endNode[cur].pb(id);
}

void buildFailure(){
    queue<int> q;
    for(int i = 0; i < 62; i++){
        if(trie[0][i]){
            q.push(trie[0][i]);
            failure[trie[0][i]] = 0;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 62; i++){
            if(trie[u][i]){
                q.push(trie[u][i]);
                int v = failure[u];
                while(v && trie[v][i] == 0) v = failure[v];
                failure[trie[u][i]] = trie[v][i];
            }
        }
    }
}

vector<int> search(string s){
    int cur = 0;
    vector<int> ans;
    for(int i = 0; i < s.size(); i++){
        int c = getINT(s[i]);
        while(cur && trie[cur][c] == 0) cur = failure[cur];
        cur = trie[cur][c];
        for(int j = cur; j && endNode[j].size(); j = failure[j]){
            for(int k = 0; k < endNode[j].size(); k++){
                str[endNode[j][k]]=1;
            }
            endNode[j].clear();
        }
    }

    return ans;
}

int main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--){
        memset(trie, 0, sizeof trie);
        memset(failure, 0, sizeof failure);
        memset(endNode, 0, sizeof endNode);
        memset(str, 0, sizeof str);
        sz = 1;
        string text;
        cin >> text;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            insert(s, i);
        }

        buildFailure();

        vector<int> ans = search(text);
        for(int i = 1; i <= n; i++) {
            if (str[i]) cout << "y" << endl;
            else cout << "n" << endl;
        }

    }
    return 0;
}

