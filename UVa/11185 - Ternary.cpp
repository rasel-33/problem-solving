//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2126


#include<iostream>
#define ll long long

using namespace std;


int main(){

	ll number;
	while(cin>>number){
		if(number < 0)
			break;

		if(number == 0)
			cout<<0;

		else{
			int arr[100],cnt =0;

			while(number > 0){

				arr[cnt] = number % 3;
				number /= 3;
				cnt++;
			}
			while(cnt--){
				
				cout<<arr[cnt];
			}
		}
			
		cout<<endl;
	}

	return 0;
}
