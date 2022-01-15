#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int x,y,count=1;

	while(cin>>x>>y,x>0 && y>0){
		if(count>1)
			cout<<endl;

		int i,j,cnt ;

		vector<vector<char>> arr(x+2,vector<char>(y+2,'.'));

		for(i=1;i<=x;i++){
			for(j=1;j<=y;j++){
				cin>>arr[i][j];
			}
		}

		cout<<"Field #"<<count++<<":"<<endl;
		
		for(i=1;i<x+1;i++){
			for(j=1;j<y+1;j++){
				
				cnt =0;
				if(arr[i][j]=='*')
					cout<<arr[i][j];
				else{
					if(arr[i-1][j-1]=='*')
						cnt++;
					if(arr[i-1][j]=='*')
						cnt++;
					if(arr[i-1][j+1]=='*')
						cnt++;
					if(arr[i][j-1]=='*')
						cnt++;
					if(arr[i][j+1]=='*')
						cnt++;
					if(arr[i+1][j-1]=='*')
						cnt++;
					if(arr[i+1][j]=='*')
						cnt++;
					if(arr[i+1][j+1]=='*')
						cnt++;
					cout<<cnt;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
