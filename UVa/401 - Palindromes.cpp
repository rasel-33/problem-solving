//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=342


#include<bits/stdc++.h>
 
#define ll                  int64_t
#define tc()                int tc;scanf("%d",&tc);while(tc--)
#define fast                ios::sync_with_stdio();cin.tie(0)
#define endl                "\n"
#define pi                  2*acos(0)
#define yes                 "Yes"
#define no                  "No"
using namespace std;
 
bool ismir(char x,char y){
    if(x=='A' && y=='A')
        return true;
    else if((x=='E' && y=='3')||(x=='3' && y=='E'))
        return true;
    else if(x=='H' && y=='H')
        return true;
    else if(x=='I' && y=='I')
        return true;
    else if((x=='J' && y=='L')||(x=='L' && y=='J'))
        return true;
    else if(x=='M' && y=='M')
        return true;
    else if(x=='O' && y=='O')
        return true;
    else if((x=='S' && y=='2') || (x=='2' && y=='S'))
        return true;
    else if(x=='T' && y=='T')
        return true;
    else if(x=='U' && y == 'U')
        return true;
    else if(x=='V' && y=='V')
        return true;
    else if(x=='W' && y =='W')
        return true;
    else if(x=='X' && y=='X')
        return true;
    else if(x=='Y' && y=='Y')
        return true;
    else if((x=='Z' && y=='5')||(x=='5' && y=='Z'))
        return true;
    else if(x=='1' && y=='1')
        return true;
    else if(x=='8' && y=='8')
        return true;
    else
        return false;
}

bool ispalindrome(char str[]){
    int n=strlen(str);
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--){
        if(str[i]!=str[j])
            return false;
    }
    return true;
}
bool ismirror(char str[]){
    int n= strlen(str);
    int i,j;
    for(i=0,j=n-1;i<=j;i++,j--){
        if(!ismir(str[i],str[j]))
            return false;
    }
    return true;
}

int main(){
    
    char s[101];
    while(scanf("%s",s)!=EOF){
        if(!ispalindrome(s) && !ismirror(s)){
            printf("%s -- is not a palindrome.\n",s);
        }
        else if(ispalindrome(s) && !ismirror(s)){
            printf("%s -- is a regular palindrome.\n",s);
        }
        else if(!ispalindrome(s) && ismirror(s)){
            printf("%s -- is a mirrored string.\n",s);
        }
        else{
            printf("%s -- is a mirrored palindrome.\n",s);
        }
        cout<<endl;
    }
return 0;
}
