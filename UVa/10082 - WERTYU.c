#include<stdio.h>
#include<string.h>

int main(){
	
	char str[48] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char ch;
	while(scanf("%c",&ch)==1){
		if(ch=='\n' || ch == ' '){
			printf("%c",ch);
		}
		else{
			int index=0,i;
			for(i=0;i<48;i++){
				if(str[i]==ch){
					index = i;
					break;
				}
			}
			printf("%c",str[index-1]);
		}
	}
return 0;
}
