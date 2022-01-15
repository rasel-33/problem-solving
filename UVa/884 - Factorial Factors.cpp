//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=825

#include<bits/stdc++.h>

#define tc()                int tc;scanf("%d",&tc);while(tc--)
#define endl                "\n"
#define ll                  long long
#define M                   1000000007
#define MX                  1000005
double pi =                 2 * acos(0);
long long inf = 1e18;
ll dr[] = {-1, 1, 0, 0, -1, 1, -1, 1};
ll dc[] = {0, 0, -1, 1, -1, -1, 1, 1};

using namespace std;


bool is_comp[MX];
vector<int> prime;
void seive(){
    for(int i=2;i*i<=MX;i++){
        if(!is_comp[i]){
            for(int j=i*i;j<MX;j+=i){
                is_comp[j] = 1;
                
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<MX;i+=2){
        if(!is_comp[i]){
            prime.push_back(i);
        }
    }
}




int nod(int n){
    int tot =0;
    for(int i=0;prime[i]*prime[i]<=n;i++){
        int cnt=0;
        while(n%prime[i]==0){
            n /= prime[i];
            cnt++;
        }
        tot += cnt;
    }
    if(n>=2){
        tot ++;
    }
    return tot;
}

int factors[1000006];

void factor(){
	factors[1] = 0;
	for(int i=2;i<1000001;i++){
		factors[i] = factors[i-1] + nod(i);
	}
}

int main()
{
    seive();   
    factor();
    int x;
    while(scanf("%d",&x)!=EOF){
    	printf("%d\n",factors[x]);
    }
       
return 0;
}
