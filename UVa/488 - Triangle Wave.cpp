//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&category=94&page=show_problem&problem=429


#include<iostream>

using namespace std;

int main(){

	int t,k;

	cin>>t;

	while(t--){

		int amplitute,frequency,i,j;
		
		cin>>amplitute>>frequency;

		while(frequency--){
			
			for(i=1;i<=amplitute;i++){
				for(j=1;j<=i;j++){
					cout<<i;
				}
				cout<<endl;
			}
			for(i=amplitute-1;i>=1;i--){
				for(j=1;j<=i;j++){
					cout<<i;
				}
				cout<<endl;
			}
			if(frequency == 0){

			}
			else{
				cout<<endl;
			}
			
		}
		
		if(t)
			cout<<endl;
	}

	return 0;
}
