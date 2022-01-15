//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=318


#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int sum_of_divisors(int x){
	int i,cnt=1;
	if(x==1)
		return 0;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0){
			if(i==(x/i))
				cnt = cnt+i;
			else{
				cnt =cnt+i+x/i;
			}
			
		}
	}
	return cnt;

}

int main()
{
	int t,i;
	int arr[100],cnt=0;
	while(cin>>t){
		if(t==0)
			break;
		arr[cnt]=t;
		cnt++;
	}
	cout<<"PERFECTION OUTPUT"<<endl;

	for(i=0;i<cnt;i++){
		
		if(sum_of_divisors(arr[i])==arr[i]){
			printf("%5d  PERFECT\n",arr[i]);
		}
		else if(sum_of_divisors(arr[i])>arr[i])
			printf("%5d  ABUNDANT\n",arr[i]);
		else if(sum_of_divisors(arr[i])<arr[i])
			printf("%5d  DEFICIENT\n",arr[i]);
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
