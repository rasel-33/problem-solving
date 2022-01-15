//Problme Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1474


#include <bits/stdc++.h>
 
 
#define LL                  long long
#define IOS                    ios::sync_with_stdio();cin.tie(0);
#define tc()                int tc;scanf("%d",&tc);while(tc--)
#define endl                "\n"
#define FLOAT_COM(a,b)      if(abs(a-b)==1e-9)
#define LOOP(a,b)           for(i=a;i<b;i++)
#define VI                  vector<int>
#define VLL                 vector<long long>
#define PB                  push_back
#define MP                  make_pair
 
 
 
using namespace std;
 

bitset<1000006> st;
bitset<1000006> status;
int st_max[1000006];
 
void shomoy(){
    #ifndef ONLINE_JUDGE
        cerr<<"\nTime  :"<<1.0*clock()/CLOCKS_PER_SEC<<"  s\n";
    #endif
 
}

void seive(){
    //0 means prime and 1 means not prime

    int i, k, j;
    st[0] = st[1] = 1;
    st[2] = 0;
    for(i=4;i<1000006;i+=2){
        st[i] = 1;
    }
    for(i=3;i*i<1000006;i++){
        if(!st[i]){
            for(j=i+i;j<1000006;j+=i){
                st[j] = 1;
            }
        }
    }
    
}

void make_status(){
    seive();
    int temp,count,i;
    for(i=1;i<1000006;i++){
        if(st[i]==0){
            
            temp = i;
            count = 0;
            
            while(temp>0){
                count += (temp%10);
                temp /= 10;
            }
            if(st[count] == 0){
                status[i] = 1;
                
            }
        }
    }

}

void make_stmx(){
    make_status();
    int count =0,i;
    for(i=0;i<1000006;i++){
        if(status[i]==1){
            count++;
            st_max[i] = count;
        }
        else{
            st_max[i] = count;
        }
    }
}

 
bool isprime(int n){
    int f;
    for(f=2;f*f<=n;f++){
        if(n%f==0)
            return false;
    }
    return true;
}
 
 
                      /*Driver Code Startes Here*/
int main(){IOS
    LL n,i,j,k,temp,count =0,min=100000,index,len,count1=0,count2=0,count3=0,total=0,temp1,temp2,temp3;

    make_stmx();
    tc(){
        int x,y;
        count1 =0;
        cin>>x>>y;
        if(x==y){
            if(status[x]==1){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            cout<<st_max[y] - st_max[x-1] <<endl;
        }
        
    }
shomoy();
return 0;
}
