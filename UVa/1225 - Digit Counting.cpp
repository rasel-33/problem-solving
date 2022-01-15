//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3666


#include<iostream>
#define ll long long

using namespace std;

int main()
{
	int t,k;

	cin>>t;

	for(k=0;k<t;k++){

		ll coin,i,x,digit,one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0,zero=0;

		cin>>x;
		for(i=1;i<=x;i++){
			coin = i;
			while(coin>0){
				digit = coin%10;
				coin /= 10;
				if(digit==0)
					zero++;
				else if(digit==1)
					one++;
				else if(digit==2)
					two++;
				else if(digit==3)
					three++;
				else if(digit==4)
					four++;
				else if(digit==5)
					five++;
				else if(digit==6)
					six++;
				else if(digit==7)
					seven++;
				else if(digit==8)
					eight++;
				else
					nine++;

			}
		}

			
	cout<<zero<<" "<<one<<" "<<two<<" "<<three<<" "<<four<<" "<<five<<" "<<six<<" "<<seven<<" "<<eight<<" "<<nine<<endl;
	}
	return 0;
}
