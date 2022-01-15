//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3947


#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()

{
    int t;

    cin>>t;

    while(t--){
        int N,i,cnt =0,x;

        cin>>N;
        int arr[N+1];

        string command;
        
        for(i=0;i<N;i++){
            
            cin>>command;
            
            if(command[0]=='L'){
                cnt -= 1;
                arr[i] = -1;
            }
            else if(command[0]=='R'){
                cnt +=1;
                arr[i] = 1;
            }
            else{
                
                cin>>command>>x;
                arr[i] = arr[x-1];
                cnt += arr[x-1];
            }

        }

        cout<<cnt<<endl;

    }

    return 0;

}
