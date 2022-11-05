#include <bits/stdc++.h>
using namespace std;

#define EPS      1E-9
#define PI       acos(-1)
#define N        100005
#define M        1000000007
#define fast     ios::sync_with_stdio();cin.tie(0)
#define ll       long long
#define endl     "\n"
#define pb       push_back
#define base     179
int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};

int trie[N][65];
int triecnt[N];
int strno[N];
int cnt[N];
int failure[N];
int output[N];
int root = 0;
int node;

int getINT(char ch){
    if(ch>='0' && ch<='9') return ch-'0';
    else if(ch>='A' && ch<='Z') return ch - 'A' + 10;
    else return ch - 'a' + 36;
}

void insert(string& s, int strNo){
    int cur = root;
    for(int i=0;i<s.size();i++){
        int id = getINT(s[i]);
        if(trie[cur][id]==-1)
            trie[cur][id] = ++node;
        cur = trie[cur][id];
    }
    strno[cur] = strNo;
}

void build_failure(){
    queue<int> q;
    for(int i = 0; i < 65; i++){
        if(trie[root][i] != -1){
            q.push(trie[root][i]);
            failure[trie[root][i]] = root;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 65; i++){
            if(trie[u][i] != -1){
                int v = trie[u][i];
                q.push(v);
                int f = failure[u];
                while(f != root && trie[f][i] == -1){
                    f = failure[f];
                }
                if(trie[f][i] != -1){
                    f = trie[f][i];
                }
                failure[v] = f;
                output[v] |= output[f];
            }
        }
        
    }
}


void search(string& s){
    int cur = root;
    for(int i=0;i<s.size();i++){
        int ch = getINT(s[i]);
        if(trie[cur][ch]!=-1){
            cur = trie[cur][ch];
            if(strno[cur]>-1){
                cnt[strno[cur]]++;
            }

            int temp = output[cur];

            while(temp!=-1 && temp!=root){
                
            }
        }else{

        }
    }
}




void solve(int cs){
    memset(trie, -1, sizeof(trie));
    memset(triecnt, -1, sizeof(triecnt));
    memset(strno, -1, sizeof(strno));
    memset(cnt, 0, sizeof(cnt));
    memset(failure, -1, sizeof(failure));
    memset(output, -1, sizeof(output));
    node = root;

    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        insert(x, i+1);
    }
    build_failure();
    search(s);

    for(int i=1;i<=node;i++){
        cout << cnt[i] <<" ";
    }
    cout << endl;

    bool status[node+1];
    memset(status, 0, sizeof(status));

   

    

    
}

int main(){
    #ifdef RASEL_DEFINED
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int start_time = clock();
    #endif
    fast;

    int tc = 1,cs = 1;
    cin >> tc;
    while(tc--){
        solve(cs);
        cs++;
    }
    #ifdef RASEL_DEFINED
        int end_time = clock();
        printf("\nTT = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
return 0;
}
