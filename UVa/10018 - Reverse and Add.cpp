#include<bits/stdc++.h>

using namespace std;

//Function declaration and defination
long long reversed(long long x){

	int arr[100],i,cnt =0,sum =0;
	while(x>0){
		arr[cnt] = x%10;
		x /= 10;
		cnt++;
	}
	for(i=0;i<cnt;i++){
		sum *=10;
		sum += arr[i];
	}
	return sum;
}

int palindrome(long long x){

	int arr[100],i,cnt=0,j;

	while(x > 0){
		arr[cnt] = x%10;
		x /= 10;
		cnt++;
	}
	for(i=0,j=cnt-1;i<j;i++,j--){
		if(arr[i] == arr[j])
			continue;
		else
			return 0;
	}
	return 1;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		long long x,cnt =0;
		cin>>x;

		while(palindrome(x) != 1){
			cnt++;
			x += reversed(x);
		}

		cout<<cnt<<" "<<x<<endl;

		
	}
	
	return 0;
}
