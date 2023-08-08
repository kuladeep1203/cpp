#include<iostream>
#include<stdlib.h>
using namespace std;
class time1
{
	int hours;
	int minutes;
	int seconds;
	public:
	    time1(int x,int y,int z)
	    {
	    hours=x;
		minutes=y;
		seconds=z;
		 }
void printstandardtime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	if(thours>12 && thours<24)
	{
		thours=thours-12;
	}
	cout<<"the time in ST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}
void printuniversaltime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	cout<<"the time in UST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}
void printindianstandardtime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	thours=thours+5;
	tminutes=tminutes+30;
	if(tminutes>60)
	{
		tminutes=tminutes%60;
		thours++;
	}
	if(thours>24)
	thours=thours%24;
	cout<<"the time in IST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
		
}
void printpacificstandardtime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	thours=thours-8;
	if(thours<0)
	thours=thours+24;
	cout<<"the time in PST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}
};
int main()
{
	int choice,x,y,z;
	time1 t1;
	while(6)
	{
		cout<<"1.Set Time\n2.Print Standard Time (AM or PM)\n3.Print Universal Time (24 hours)\n4.Print Indian Start Time (24 hours)\n5.Print Pacific Standard Time (AM or PM)\n6.Exit\n";
		cout<<"enter the choice\n";
		cin>>choice;
		
		if(choice==2){
		
			t1.printstandardtime();
			cout<<"\n";
		}
			if(choice==3){
			t1.printuniversaltime();
			cout<<"\n";
		}
		if(choice==4){
		
			t1.printindianstandardtime();
			cout<<"\n";
	}
		if(choice==5){
		
			t1.printpacificstandardtime();
		cout<<"\n";
		}	if(choice==6)
			exit(1);
			if(choice==1){
		cout<<"enter the hours in 24 hours format\n";
		cin>>x;
		cout<<"enter the minutes in 24 hours format\n";
		cin>>y;
		cout<<"enter the seconds in 24 hours format\n";
		cin>>z;
		time1 t2(x,y,z);
	}	
		}
		return 0;
	}
	
/*
void printstandardtime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	if(thours>12 && thours<24)
	{
		thours=thours-12;
	}
	cout<<"the time in ST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}
void printuniversaltime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	cout<<"the time in UST\n"
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}
void printindianstandardtime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	thours=thours+5;
	tminutes=tminutes+30;
	if(tminutes>60)
	{
		tminutes=tminutes%60;
		thours++;
	}
	if(thours>24)
	thours=thours%24;
	cout<<"the time in IST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
		
}
void printpacificstandardtime()
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	thours=thours-8;
	if(thours<0)
	thours=thours+24;
	cout<<"the time in PST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}*/













