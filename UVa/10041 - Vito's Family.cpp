#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;

	cin>>t;

	while(t--){
		int relatives,mid,sum = 0;

		cin>>relatives;

		int arr[relatives];

		for(auto i=0;i<relatives;i++){
			cin>>arr[i];
		}

		sort(arr,arr+relatives);
		if(relatives%2==0){
			mid = (relatives/2) -1;
		}
		else{
			mid = relatives/2;
		}
		for(auto i=0;i<relatives;i++){
			sum += abs(arr[i] - arr[mid]); 
		}
		cout<<sum<<endl;

	}
	return 0;
}
