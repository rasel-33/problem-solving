//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=614

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string str;
		getline(cin,str);
		int len = str.size();
		stack<char> st;
		for(int i=0;i<len;i++){
			if(str[i]=='[' || str[i]=='('){
				st.push(str[i]);
			}
			else{
				if(str[i]==')' && (st.empty() || st.top()!='(')){
					st.push('a');
					break;
				}
				if(str[i]==']' && (st.empty() || st.top()!='[')){
					st.push('a');
					break;
				}
				st.pop();
			}
		}
		
		st.empty()||str[0]==' '?printf("Yes\n"):printf("No\n");	
	} 
return 0;
}
