//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3986


#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

struct friends{
	char name[20];
	long long date;
};

int main()

{
    ll t,date,month,year,i;

    cin>>t;
    ll arr[t];

    friends bondhu[t];

    for(i=0;i<t;i++){
    
    	cin>>bondhu[i].name;
    	cin>>date;
    	cin>>month;
    	cin>>year;
    	bondhu[i].date = date + month*30 + year*365;

    	arr[i] = bondhu[i].date;
    }

    sort(arr,arr+t);
    
    for(i=0;i<t;i++){
    	if(arr[t-1] == bondhu[i].date){
    		cout<<bondhu[i].name<<endl;
    	}
    }
    for(i=0;i<t;i++){
    	if(arr[0] == bondhu[i].date){
    		cout<<bondhu[i].name<<endl;
    	}
    }
    return 0;

}
