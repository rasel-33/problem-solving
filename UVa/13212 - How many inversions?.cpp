//Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5135


#include<bits/stdc++.h>
#define tc()       int t_case;scanf("%d",&t_case);while(t_case--)
#define MX         1000006
#define ll         long long
#define BASE       263
#define M          1000000007
 
 
using namespace std;
ll cnt;

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1,n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[i+l];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[i+m+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            cnt += (n1-i);
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = R[j];
        k++;
        j++;
    }
}


void mergesort(int arr[],int l,int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
 
 
int main()
{
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        cnt = 0;
        mergesort(arr,0,n-1);
        printf("%lld\n",cnt);
    }
    return 0;
}
