//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4761


#include <bits/stdc++.h>
#define loop(i,n)   for(i=0;i<n;i++)
#define ll          long long
#define MAX         10000001
#define pi          acos(-1)
#define _           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll i,j,k,cnt,sum;
 
using namespace std;

bitset<MAX> prime;



//Code Starts Here//
int main(){_
	
	int t;
	char ch;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int arr[n],press[n];

		loop(i,n){
			cin>>arr[i];
		}
		loop(i,n){
			cin>>press[i];
		}
		loop(i,n){
			if(arr[i]==0){
				if(press[i]==1){
					cout<<" ";
				}
			}
			else if(arr[i]==2){
				if(press[i]==1){
					cout<<'a';
				}
				else if(press[i]==2){
					cout<<'b';
				}
				else if(press[i]==3){
					cout<<'c';
				}
			}
			else if(arr[i]==3){
				if(press[i]==1){
					cout<<'d';
				}
				else if(press[i]==2){
					cout<<'e';
				}
				else if(press[i]==3){
					cout<<'f';
				}
			}
			else if(arr[i]==4){
				if(press[i]==1){
					cout<<'g';
				}
				else if(press[i]==2){
					cout<<'h';
				}
				else if(press[i]==3){
					cout<<'i';
				}
			}
			else if(arr[i]==5){
				if(press[i]==1){
					cout<<'j';
				}
				else if(press[i]==2){
					cout<<'k';
				}
				else if(press[i]==3){
					cout<<'l';
				}
			}
			else if(arr[i]==6){
				if(press[i]==1){
					cout<<'m';
				}
				else if(press[i]==2){
					cout<<'n';
				}
				else if(press[i]==3){
					cout<<'o';
				}
			}
			else if(arr[i]==7){
				if(press[i]==1){
					cout<<'p';
				}
				else if(press[i]==2){
					cout<<'q';
				}
				else if(press[i]==3){
					cout<<'r';
				}
				else if(press[i]==4){
					cout<<'s';
				}
			}
			else if(arr[i]==8){
				if(press[i]==1){
					cout<<'t';
				}
				else if(press[i]==2){
					cout<<'u';
				}
				else if(press[i]==3){
					cout<<'v';
				}
			}
			else if(arr[i]==9){
				if(press[i]==1){
					cout<<'w';
				}
				else if(press[i]==2){
					cout<<'x';
				}
				else if(press[i]==3){
					cout<<'y';
				}
				else if(press[i]==4){
					cout<<'z';
				}
			}
			else if(arr[i]==1){
				if(press[i]==1){
					ch = '.';
				}
				else if(press[i]==2){
					ch = ',';
				}
				else if(press[i]==3){
					ch = '?';
				}
				else if(press[i]==4){
					ch = '"';
				}
				cout<<ch;
			}
			
			//printf("%c",ch+press[i]);
		}
		cout<<endl;

	}

	return 0;
}
