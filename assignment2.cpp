#include<iostream>
#include<stdlib.h>
using namespace std;
class time1
{
	int hours;
	int minutes;
	int seconds;
	public:
		void set(int hr,int min,int sec)
		{
		hours=hr;
		minutes=min;
		seconds=sec;	
		}
		time1()
		{
		hours=0;
		minutes=0;
		seconds=0;
		}
	   void get(int *hr,int *min,int *sec)
	    {
	    *hr=hours;
	    *min=minutes;
	    *sec=seconds;
		 }
		 time1(int hr,int min,int sec)
		 {
		hours=hr;
		minutes=min;
		seconds=sec;
		 }
		 ~time1()
		 {
		 	
		 }

};
void printstandardtime(int hours,int minutes,int seconds)
{
	int thours=hours;
	 int tminutes=minutes;
	 int tseconds=seconds;
	if(thours>12 && thours<=24)
	{
		if(thours==24)
	    thours=0;
	 else
		thours=thours-12;
		cout<<"the time in ST\n";
		cout<<thours<<":"<<tminutes<<":"<<tseconds<<"PM";
	}
	else if(thours<=24){
	cout<<"the time in ST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds<<"AM";
}
      else
      cout<<"invalid\n";
}
void printuniversaltime(int hours,int minutes,int seconds)
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	if(thours<=24 && tminutes<60 && tseconds<60)
	{
	cout<<"the time in UST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}
else
cout<<"invalid\n";

}
void printindianstandardtime(int hours,int minutes,int seconds)
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;
	thours=thours+5;
	tminutes=tminutes+30;
	if(tminutes>=60)
	{
		tminutes=tminutes%60;
		thours++;
	}
	if(thours>24)
	thours=thours%24;
	if(thours<24 && tminutes<60 && tseconds<60){
	cout<<"the time in IST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds;
}
}
void printpacificstandardtime(int hours,int minutes,int seconds)
{
	int thours=hours;
	int tminutes=minutes;
	int tseconds=seconds;                        
	thours=thours-8;
	thours=thours%24;
	if(thours<0)
	thours=thours+24;
	if(thours>12)
	{
		thours=thours-12;
		cout<<"the time in ST\n";
		cout<<thours<<":"<<tminutes<<":"<<tseconds<<"PM";
	}
	else if(thours<=24){
	cout<<"the time in ST\n";
	cout<<thours<<":"<<tminutes<<":"<<tseconds<<"AM";
}
      else
      cout<<"invalid\n";
}
void menulist(time1 t2)
	 {
	 	int choice,x,y,z;
	while(6)
	{
		cout<<"menu \n1.Set Time\n2.Print Standard Time (AM or PM)\n3.Print Universal Time (24 hours)\n4.Print Indian Start Time (24 hours)\n5.Print Pacific Standard Time (AM or PM)\n6.Exit\n";
		cout<<"enter the choice\n";
		cin>>choice;
		if(choice==1){
		cout<<"enter the hours in 24 hours format\n";
		cin>>x;
		cout<<"enter the minutes in 24 hours format\n";
		cin>>y;
		cout<<"enter the seconds in 24 hours format\n";
		cin>>z;
		if(x>24 || y>60 || z>60){
		cout<<"invalid\n";
		break;
	}
		else
		t2.set(x,y,z);
	}
		if(choice==2){
		t2.get(&x,&y,&z);
			printstandardtime(x,y,z);
			cout<<"\n";
		}
			if(choice==3){
			t2.get(&x,&y,&z);
			printuniversaltime(x,y,z);
			cout<<"\n";
		}
		if(choice==4){
		t2.get(&x,&y,&z);
		printindianstandardtime(x,y,z);
		cout<<"\n";
	}
		if(choice==5){
		t2.get(&x,&y,&z);
			printpacificstandardtime(x,y,z);
		cout<<"\n";
		}	if(choice==6)
		{
		  
			exit(1);	
		}
		}
	}
int main()
{
	int choice,hou,min,sec,choice1=0;
	while(choice1!=1&&choice1!=2){
	 cout<<"1.create\n2.create and set\n";
	 cin>>choice1;
	 if(choice1==1)
	 {
	 time1 t1;
	 menulist(t1);
}
	  if (choice1==2)
	 {
	 	cout<<"enter the hours in 24 hours format\n";
		cin>>hou;
		cout<<"enter the minutes in 24 hours format\n";
		cin>>min;
		cout<<"enter the seconds in 24 hours format\n";
		cin>>sec;
		if(hou>24 || min>60 || sec>60)
		cout<<"invalid\n";
		else{
		time1 t1(hou,min,sec);
		menulist(t1);
	}
	 }
}
	 return 0;
}
 













