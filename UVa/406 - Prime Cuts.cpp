//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=347


#include <bits/stdc++.h>
#include <bitset>
#include <iterator>

using namespace std;


int main()
{
	int n,c,i,j;
	int arr[1001];
	
	for(i=0;i<1001;i++){
		arr[i] = 0;
	}
	for(i=4;i<1001;i+=2){
		arr[i] = 1;
	}
	for(i=3;i*i<1001;i+=2){
		if(arr[i]==0){
			for(j=i+i;j<1001;j+=i){
				arr[j] = 1;
			}
		}
	}
	while(cin>>n>>c){
		vector<int> prime;
		vector<int>::iterator it;
		int count=0;
		for(i=1;i<=n;i++){
			if(arr[i]==0){
				prime.push_back(i);
				count++;
			}
		}
		int carr[count],center_left,center_right,center;
		i=0;
		for(it=prime.begin();it!=prime.end();it++){
			carr[i] = *it;
			i++;
		}
		center = count/2;
		cout<<n<<" "<<c<<":";
		if(count%2==0){
			
			center_left = center;
			center_right = center_left+1;
			for(i=center_left-c;i<=center_left;i++){
				if(i<0){
					continue;
				}
				else{
					cout<<" "<<carr[i];
				}
				
			}
			for(i=center_right;i<=center_right+c-2;i++){
				if(i>=count){
					continue;
				}
				else{
					cout<<" "<<carr[i];
				}
			}
			cout<<endl<<endl;

		}
		else{
			for(i=center-c+1;i<=center;i++){
				if(i<0){
					continue;
				}
				else{
					cout<<" "<<carr[i];
				}
			}
			for(i=center+1;i<=center+c-1;i++){
				if(i>=count){
					continue;
				}
				else{
					cout<<" "<<carr[i];
				}
			}
			cout<<endl<<endl;
		}


	}
	return 0;
}
