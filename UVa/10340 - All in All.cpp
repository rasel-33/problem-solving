#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char  word1[100000] ,word2[100000];

	while(scanf("%s %s",word1,word2)!=EOF){

		int len1,len2,i=0,j=0,cnt =0;

		len1 = strlen(word1);
		len2 = strlen(word2);

		for(i=0;i<len2;i++){
			if(word1[j]==word2[i]){
				j++;
				if(j==(len1)){
					cnt = 1;
					break;
				}
			}
		}
		if(cnt==0){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;

}
