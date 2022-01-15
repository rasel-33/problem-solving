#include <bits/stdc++.h>

#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--)
#define pi             acos(-1)

using namespace std;

ll i,j,temp,k,arr[1000001],n;

int main()
{_

	int n;
	while(cin>>n){
        int arr[n];
        bool diff[n],flag = true;
        for(i=0;i<n;i++){
            diff[i] = false;
        }

        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        for(i=1;i<n;i++){
            temp = abs(arr[i] - arr[i-1]);
            diff[temp] = true;
        }
        for(i=1;i<n;i++){
            if(diff[i]==false){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Jolly"<<endl;
        }
        else{
            cout<<"Not jolly"<<endl;
        }
	}

return 0;
}
