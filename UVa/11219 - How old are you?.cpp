//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2160


#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t,i;
    string str;
    
    cin>>t;

    for(i=1;i<=t;i++){

    	getline(cin,str);

        char present_date[11],birth_date[11];
        
        cin>>present_date>>birth_date;
        
        int present_year,birth_year,present_month,birth_month,present_day,birth_day,year;

      	present_day=( (int)present_date[0] -48)*10 + (int)present_date[1] - 48;
        birth_day=( (int)birth_date[0] -48)*10 + (int)birth_date[1] - 48;
      	present_month = ((int )present_date[3] - 48)*10 + (int)present_date[4] - 48;
        birth_month = ((int )birth_date[3] - 48)*10 + (int)birth_date[4] - 48;
      	present_year = ((int)present_date[6] - 48)*1000 +((int)present_date[7] - 48)*100 + ((int)present_date[8] -48)*10 + ((int)present_date[9] -48);
        birth_year = ((int)birth_date[6] - 48)*1000 +((int)birth_date[7] - 48)*100 + ((int)birth_date[8] -48)*10 + ((int)birth_date[9] -48);

        year = present_year - birth_year -1;
        if(present_month==birth_month){
        	if(present_day >= birth_day)
        		year++;
        }
        else if(present_month>birth_month)
        	year++;
        
        if(year < 0){
        	cout<<"Case #"<<i<<": Invalid birth date"<<endl;
        }
        else if(year > 130){
        	cout<<"Case #"<<i<<": Check birth date"<<endl;
        }
        else{
        	cout<<"Case #"<<i<<": "<<year<<endl;
        }

    }
    return 0;
}
