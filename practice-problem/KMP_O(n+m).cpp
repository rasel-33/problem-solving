#include <bits/stdc++.h>

using namespace std;
int failure[1000006];
bool ok;

void build_failure(string pattern){
	int m = pattern.size();
	int j = 0;
	failure[0] = 0;
	for(int i=1;i<m;i++){
		while(j>0 && pattern[j]!=pattern[i]){
			j = failure[j-1];
		}
		if(pattern[j]==pattern[i]){
			j++;
		}
		failure[i] = j;
	}
}


void KMP(string text, string pattern){
	int m = pattern.size();
	int j=0;
	for(int i=0;i<text.size();i++){
		while(j>0 && text[i]!=pattern[j]){
			j = failure[j-1];
		}
		if(text[i]==pattern[j]){
			j++;
		}
		if(j==m){
			ok = true;
			cout << i-m+1 << endl;
			j = failure[j-1];
		}
	}
}




int main(){
	// freopen("input.txt", "r", stdin);
	int n;
	
	while(cin >> n){
		ok = false;
		string pattern, text;
		cin >> pattern;
		cin >> text;
		build_failure(pattern);
		KMP(text, pattern);
		if(!ok){
			cout << endl;
		}
	}
}
