#include<bits/stdc++.h>
#define ll   long long

using namespace std;

int main()
{
	
	int ar,br,ac,bc;
	printf("Enter the row and column number of the matrix A\n");

	scanf("%d %d",&ar,&ac);
	printf("Enter the row and column number of the matrix B\n");
	scanf("%d %d",&br,&bc);

	if(ac == br){
		int A[ar][ac];
		int B[br][bc];
		int cr = ar, cc = bc;
		int C[cr][cc];
		printf("Enter the matrix A\n");
		for(int i=0;i<ar;i++){
			for(int j=0;j<ac;j++){
				scanf("%d",&A[i][j]);
			}
		}
		printf("Enter the matrix B\n");

		for(int i=0;i<br;i++){
			for(int j=0;j<bc;j++){
				scanf("%d",&B[i][j]);
			}
		}

		for(int i=0;i<ar;i++){
			for(int j=0;j<bc;j++){
				C[i][j] = 0;
				for(int k=0;k<br;k++){
					C[i][j] += (A[i][k] * B[k][j]);
				}
				printf("%d ",C[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("Matrix multiplication is not possible\n");
	}
}
