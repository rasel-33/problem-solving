#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[],int n){
	int max = *max_element(arr,arr+n);
	int min = *min_element(arr,arr+n);
	int range = max-min+1;

	int count[range];
	for(int i=0;i<range;i++){
		count[i] = 0;
	}

	for(int i=0;i<n;i++){
		count[arr[i]-min]++;
	}

	for(int i=1;i<range;i++){
		count[i] += count[i-1];
	}

	vector<int> sorted(n);

	for(int i=n-1;i>=0;i--){
		sorted[count[arr[i] - min]-1] = arr[i];
		count[arr[i]-min]--;
	}
	for(int i=0;i<n;i++){
		arr[i] = sorted[i];
	}
}




int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	counting_sort(arr, n);

	for(int i=0;i<n;i++){
		cout << arr[i] <<" ";
	}
	cout << endl;

}
