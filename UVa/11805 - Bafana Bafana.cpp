//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2905


#include<bits/stdc++.h>

using namespace std;

int main(){
	int tc,i=1;

	cin>>tc;

	while(tc--){
		int man,position,pass,ball;
		cin>>man>>position>>pass;

		ball = (position + pass)%man;
		if(ball==0)
			ball = man;

		cout<<"Case "<<i++<<": "<<ball<<endl;
	}
	return 0;
}
