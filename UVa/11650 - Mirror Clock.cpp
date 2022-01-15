//Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2697


#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--){

		char a,b,c,d,e,s[6];

		int A,B,D,E,mirror_time,real_time,late;

		scanf("%s",s);
		A = (int)s[0] -48;
		B = (int)s[1] -48;
		D = (int)s[3] -48;
		E = (int)s[4] -48;
		c = s[2];

		mirror_time = A*600 + B*60 + D*10 + E;
		late = 720 - mirror_time;


		if(mirror_time == 720){
			cout<<"12:00"<<endl;
		}
		else if(mirror_time > 720){
			
			real_time = 1440 - mirror_time;
			a = (char)(real_time/600) + 48;
			real_time %= 600;
			b = (char)(real_time/60) + 48;
			real_time %= 60;
			d = (char)(real_time/10) + 48;
			real_time %= 10;
			e = (char)real_time + 48;

			printf("%c%c%c%c%c\n",a,b,c,d,e);

		}
		else if(mirror_time>=661 && mirror_time<=719){
			late = 720 - mirror_time;
			mirror_time = late + 720;
			real_time = 720 + late;
			a = (char)(real_time/600) + 48;
			real_time %= 600;
			b = (char)(real_time/60) + 48;
			real_time %= 60;
			d = (char)(real_time/10) + 48;
			real_time %= 10;
			e = (char)real_time + 48;

			printf("%c%c%c%c%c\n",a,b,c,d,e);
		}
		else{
			real_time = 720 - mirror_time;
			a = (char)(real_time/600) + 48;
			real_time %= 600;
			b = (char)(real_time/60) + 48;
			real_time %= 60;
			d = (char)(real_time/10) + 48;
			real_time %= 10;
			e = (char)real_time + 48;

			printf("%c%c%c%c%c\n",a,b,c,d,e);

		}
	}
	return 0;
}
