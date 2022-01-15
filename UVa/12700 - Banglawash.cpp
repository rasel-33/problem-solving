//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4438


#include<iostream>

using namespace std;

int main()
{
	int t;

	cin>>t;

	for(auto i=1;i<=t;i++){
		int matches,bangladesh=0,www=0,tie=0,abandoned=0,j;


		cin>>matches;

		char str[matches];

		cin>>str;
		for(j=0;j<matches;j++){
			if(str[j]=='B')
				bangladesh++;
			else if(str[j]=='W')
				www++;
			else if(str[j]=='T')
				tie++;
			else if(str[j]=='A')
				abandoned++;
		}
    
		int total = matches;
		matches -= abandoned;
    
		if(total==abandoned)
			cout<<"Case "<<i<<": ABANDONED";
		else if(matches==bangladesh)
			cout<<"Case "<<i<<": BANGLAWASH";
		else if(matches==www)
			cout<<"Case "<<i<<": WHITEWASH";
		else if(bangladesh>www)
			cout<<"Case "<<i<<": BANGLADESH "<<bangladesh<<" - "<<www;
		else if(www>bangladesh)
			cout<<"Case "<<i<<": WWW "<<www<<" - "<<bangladesh;
		else
			cout<<"Case "<<i<<": DRAW "<<bangladesh<<" "<<tie;
      
		cout<<endl;

	}
	return 0;
}
