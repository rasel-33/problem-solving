#include <bits/stdc++.h>
using namespace std;

vector<int> find_maximum_crossing_subarray(int arr[], int lo,int mid, int hi){
	int maxleft = INT_MIN;
	int leftsum = 0;
	int left_idx;

	for(int i=mid;i>=lo;i--){
		leftsum += arr[i];
		if(leftsum>maxleft){
			maxleft = leftsum;
			left_idx = i;
		}
	}

	int maxright = INT_MIN;
	int rightsum = 0;
	int right_idx;

	for(int i=mid+1;i<=hi;i++){
		rightsum += arr[i];
		if(rightsum>maxright){
			maxright = rightsum;
			right_idx = i;
		}
	}
	std::vector<int> vt;

	vt.push_back(maxleft+maxright);
	vt.push_back(left_idx);
	vt.push_back(right_idx);
	return vt;
}



vector<int> find_maximum_subarray(int arr[], int lo, int hi){
	if(lo==hi){
		vector<int> vt;
		vt.push_back(arr[lo]);
		vt.push_back(lo);
		vt.push_back(hi);
		return vt;
	}
	else{
		int mid = (lo+hi)/2;
		vector<int> ans1, ans2, ans3;
		ans1 = find_maximum_subarray(arr, lo, mid);
		ans2 = find_maximum_subarray(arr, mid+1, hi);
		ans3 = find_maximum_crossing_subarray(arr, lo, mid, hi);
		if(ans1[0]>=ans2[0] && ans1[0]>=ans3[0]){
			
			
			return ans1;
		}
		else if(ans2[0]>=ans1[0] && ans2[0]>=ans3[0]){
			
			return ans2;
		}
		else{
			return ans3;
		}
	}
}



int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	
	cin >> n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int left, right;
	vector<int> ans = find_maximum_subarray(arr, 0, n-1);

	cout << ans[0] << endl;

	cout << ans[1] <<" "<<ans[2] <<endl;

}
