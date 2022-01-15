#include<stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n],i,j;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	int x,temp;
	scanf("%d",&x);
	for(i=0;i<x;i++){
		scanf("%d",&temp);
		int res=0;
		for(j=n-1;j>=0;j--){
			if(arr[j]<temp){
				res = arr[j];
				break;
			}
		}
		if(res){
			printf("%d ",res);
		}
		else{
			printf("X ");
		}
		res = 0;
		for(j=0;j<n;j++){
			if(arr[j]>temp){
				res = arr[j];
				break;
			}
		}
		res?printf("%d\n",res):printf("X\n");
	}
	return 0;
}
