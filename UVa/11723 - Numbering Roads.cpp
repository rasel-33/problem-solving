//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2823


#include<iostream>

using namespace std;

int returned(int x,int n){
	
	int i;
	for(i=1;i<=26;i++){
		if(((i+1)*n)>=x)
			return i;
	}
	return 0;
}

int main(){
	int road,numbers,cnt,count=1;

	while(cin>>road>>numbers){
		if(road==0 && numbers==0)
			break;
		cnt =0;
		if(road<=numbers)
			cout<<"Case "<<count<<": "<<cnt<<endl;
		else if(returned(road,numbers)==0){
			cout<<"Case "<<count<<": impossible"<<endl;
		}
		else{
			cnt = returned(road,numbers);
			cout<<"Case "<<count<<": "<<cnt<<endl;
		}
		count++;
	}
	return 0;
} 
