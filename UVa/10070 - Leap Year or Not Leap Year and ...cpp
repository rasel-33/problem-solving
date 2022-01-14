//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1011

#include<stdio.h>
#include<string.h>

int main(){
	char str[10001];
	int kok=0;
	while(scanf("%s",str)==1){
		if(kok!=0){
			printf("\n");
		}
		int n = strlen(str);
		int k11=0,k3=0;
		int x =0;
		bool div11=false,div5=false,div4=false,div100=false,div400=false,div3=false,leap = false;
		bool huluculu=false,bulukulu=false;
		for(int i=0;i<n;i++){
			if(i%2){
				k11-=(str[i]-'0');
			}
			else{
				k11+=(str[i]-'0');
			}
			k3+=(str[i]-'0');
		}
		if(k3%3==0){
			div3 = true;
		}
		if(str[n-1]=='0'||str[n-1]=='5'){
			div5 = true;
		}
		if(str[n-1]=='0' && str[n-2]=='0'){
			div100 = true;
		}
		if(k11%11==0){
			div11=true;
		}
		x = str[n-1]+str[n-2]*10;
		if(x%4==0){
			div4=true;
		}
		x = str[n-3]+str[n-4]*10;
		if(x%4==0 && div100){
			div400 = true;
		}
		if(div400 || (div100==false &&div4)){
			leap = true;
			printf("This is leap year.\n");
		
		}
		if(div5 && div3){
			huluculu = true;
			printf("This is huluculu festival year.\n");
		}
		if(div11 && div5 && leap){
			printf("This is bulukulu festival year.\n");
		}
		if(!huluculu &&!leap){
			printf("This is an ordinary year.\n");
		}
		kok=1;
	}
	return 0;
}
