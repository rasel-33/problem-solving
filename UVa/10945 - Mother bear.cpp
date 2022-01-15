#include <iostream>
#include <string.h>
#include <stdio.h>

//This is an example problem for which you have to use both stdio.h and string.h carefully
using namespace std;

int main()
{

    char sentence1[1000],sentence2[1000];
    while(gets(sentence1)){

        int i,j,k,x,cnt=0;
        if(!strcmp(sentence1,"DONE")){
            break;
        }
        for(i=0;sentence1[i]!='\0';i++){
            if((sentence1[i]>='a'&&sentence1[i]<='z'))
            {
                sentence1[cnt]=sentence1[i];
                cnt++;
            }
            else if(sentence1[i]>='A'&&sentence1[i]<='Z')
            {
                sentence1[cnt]=sentence1[i]+32;
                cnt++;

            }
        }
        sentence1[cnt] = '\0';
        for(i=0,j=cnt-1;sentence1[i]!='\0';i++,j--){
            sentence2[j] = sentence1[i];
        }
        sentence2[cnt] ='\0';

        x = strcmp(sentence1,sentence2);
        if(x==0){
            cout<<"You won't be eaten!"<<endl;
        }
        else{
            cout<<"Uh oh.."<<endl;
        }
    }
    return 0;
}
