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

struct node{
    int flag;
    node* next[26]={NULL};
};

node* root = new node;

void insert(string word){
    node* it = root;
    for(int i=0;i<word.size();i++){
        if(it->next[word[i]-'a']==NULL)
            it->next[word[i]-'a'] = new node;
        it = it->next[word[i]-'a'];
    }
    it->flag ++;
}

bool search(string word){
    node* it = root;
    for(int i=0;i<word.size();i++){
        if(it->next[word[i]-'a']==NULL)
            return false;
        it = it->next[word[i]-'a'];
    }
    if(it->flag)
        return true;
    return false;
}

void solve(int cs){
    int n;
    root = new node;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        insert(s);
    }
    cout <<search("rasel")<<endl;
}

int main(){
    #ifdef RASEL_DEFINED
        freopen("input.txt","r",stdin);
        int start_time = clock();
    #endif
    int tc = 1,cs = 1;
    // cin >> tc;
    while(tc--){
        solve(cs);
        cs++;
    }
    
    #ifdef RASEL_DEFINED
        int end_time = clock();
        printf("\nTime taken = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
return 0;
}
