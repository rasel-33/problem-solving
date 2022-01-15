//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400


#include<bits/stdc++.h>
#define tc()       int t_case;scanf("%d",&t_case);while(t_case--)
#define MX         1000006
#define ll         long long
#define BASE       263
#define M          1000000007


using namespace std;

int par[1000006];

int get_par(int u){
    if(par[u]==u) return u;
    return par[u] = get_par(par[u]);
}

void update(int u,int v){
    int pu = get_par(u);
    int pv = get_par(v);
    par[pu] = pv;
}


int main()
{
    int n;
    cin>>n;
    for(int kk=0;kk<n;kk++){
        for(int i=1;i<30;i++){
            par[i] = i;
        }
        char c;
        cin>>c;
        int t = c - 'A' + 1;
        string s;
        getline(cin,s);
        while(getline(cin,s)){
            if(s.size()==0) break;
            int u = s[0] - 'A' + 1;
            int v = s[1] - 'A' + 1;
            update(u,v);
        }
        set<int> st;
        for(int i=1;i<=t;i++){
            int xx = get_par(get_par(i));
            st.insert(xx);
        }
        if(kk!=0){
            cout<<endl;
        }
        cout<<st.size()<<endl;
    }

    return 0;
}
