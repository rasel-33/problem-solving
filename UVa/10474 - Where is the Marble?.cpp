#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N,query,i,j,k,cnt=0;

	while(cin>>N>>query){
		if(N==0 && query ==0)
			break;

		int arr[N];
		int que[query];
		int position[10001];

		for(i=0;i<10001;i++){
			pos[i] =0;
		}

		for(i=0;i<N;i++){
			cin>>arr[i];
		}
		for(i=0;i<query;i++){
			cin>>que[i];
		}

		sort(arr,arr+N);

		pos[arr[0]] = 1;

		for(i=1;i<N;i++){
			if(arr[i-1] == arr[i]){
				continue;
			}
			else{
				pos[arr[i]] = i+1;
			}
		}
		cout<<"CASE# "<<++cnt<<":"<<endl;
		for(i=0;i<query;i++){
			if(pos[que[i]]!=0){
				cout<<que[i]<<" found at "<<position[que[i]]<<endl;
			}
			else{
				cout<<que[i]<<" not found"<<endl;
			}
		}

	}
	return 0;
}
