#include<bits/stdc++.h>


using namespace std;

void heapify(int arr[],int n,int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[l] > arr[largest]){
		largest = l;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}


void heapSort(int arr[],int n){
	for(int i = n/2 - 1 ;i>=0;i--){
		heapify(arr,n,i);
	}

	for(int i = n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);


    int n;
    scanf("%d",&n);

    int arr[n];
    
    for(int i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }

    heapSort(arr,n);
    printf("The Sorted Array is \n");
    printArray(arr,n);

}
