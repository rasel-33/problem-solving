//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=515


#include<bits/stdc++.h>
#define tc()       int t_case;scanf("%d",&t_case);while(t_case--)
#define MX         100005
#define ll         long long
#define BASE       263
#define M          1000000007


using namespace std;


int mm[1000006];
std::vector<int> v,ans;
int n,arr[100],cnt;
set<int> st,bt;

void generatesum(int rem,int start){
    if(rem==0){
        int res = 1;
        for(int i=0;i<v.size();i++){
            res = (res * (v[i] + 1005))%1000000007;
            
        }
        
        if(st.count(res)==0){
            cnt++;
            cout<<v[0];
            for(int i=1;i<v.size();i++){
                cout<<"+"<<v[i];
            }
            cout<<endl;
            st.insert(res);
        }
        return;
    }

    for(int i=start;i<n;i++){
        if((rem-arr[i])>=0 ){
            v.push_back(arr[i]);
            generatesum(rem-arr[i],i+1);
            v.pop_back();
        }
    }
}

int main()
{
    int tot;
    while(scanf("%d %d",&tot,&n)){
        if(tot==0 && n==0) break;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"Sums of "<<tot<<":\n";
        cnt = 0;
        generatesum(tot,0);
        if(cnt==0){
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}
