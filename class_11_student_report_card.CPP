
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


/* this act as blue print for the fields to be included in the report card*/

struct report
 {
    char name[50];
    int roll;
    int admn;
    int english;                 // these variables act as fields
    int physics;
    int chemistry;
    int math;
    int computer;
    float cgpa;
 };
int n=0,delcounter=0;           // declaring global variables
report r[50];                    // declaring global structural variable



void loading()                  // function to create load effect
  {
    clrscr();
    cout<<"\n\n\n\n\n\n";
    cout<<"\n                                                                      ";
    cout<<"\n             LOADING NECESSARY INFORMATIONS ON THE REPORT CARD.          ";
    cout<<"\n                                                                      ";
    cout<<"\n                                PLEASE WAIT !!!!                        ";
    cout<<"\n                                                                      ";
    cout<<"\n\n\n  ";
      for(int i=0;i<76;i++)
	 {
	    for(long int i=0;i<999999;i++);   // creating blank loop for time gap
	    cout<<"I";
	 }
    cout<<"\n\n\n             ALL INFORMATIONS LOADED IN THE REPORT CARD.             ";
 }

 /* function to advice user to be acution while giving inputs */


    void warning()
     {
       cout<<"________________________________________________________________________";
       cout<<"\n|                                                                       |";
       cout<<"\n|           WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!         |";
       cout<<"\n|                                                                       |";
       cout<<"\n|YOUR REST OF INPUTS MUST BE IN NUMBERS,OTHERWISE THE PROGRAM WILL HANG.|";
       cout<<"\n|                                                                       |";
       cout<<"\n|                                                                       |";
       cout<<"\n|______________________________________________________________________ |";
     }


void comment(float cgpa)       // function to give comments
   {
     randomize();
     if(cgpa>=8)
       cout<<"EXCELLENT";
     else
     {
       switch(random(5))
	{             // switch...case statement initialised
	  case 0:cout<<"needs improvement";
		break;
	  case 1:cout<<"very notorious";
		break;
	  case 2:cout<<"very informative.";
		break;
	  case 3:cout<<"can do better";
		break;
	  default:cout<<"work hard";
		break;
	}
     }
}


float gp(int marks)  // function to create grade points of a subject
   {
     float gp;
      if(marks>90)
	 gp=10;
      else if(marks>80)
	 gp=9;
      else if(marks>70)
	 gp=8;
      else if(marks>60)
	 gp=7;
      else if(marks>50)
	 gp=6;
      else if(marks>40)
	 gp=5;
      else if(marks>30)
	 gp=4;
      else if(marks>20)
	 gp=3;
      else if(marks>10)
	 gp=2;
      else
	 gp=1;
  return gp;
}

 /* function to calculate cgpa of the student */

 float cgpa(int phy,int chem,int math,int comp,int eng)
  {
    float cgpa;
    cgpa=(gp(phy)+gp(chem)+gp(math)+gp(comp)+gp(eng))/5;
    return cgpa;
  }


void getval(report &s)     // function to accept input by the user
  {
    cout<<"\nenter the name of student:";
    gets(s.name);
    clrscr();
    warning();
    cout<<"\n\n\nenter the roll number:";
    cin>>s.roll;
    cout<<"\nenter the admission number:";
    cin>>s.admn;
    cout<<"\nenter the marks in english:";
    cin>>s.english;
    cout<<"\nenter the marks in math:";
    cin>>s.math;
    cout<<"\nenter the marks in physics:";
    cin>>s.physics;
    cout<<"\nenter the marks in chemistry:";
    cin>>s.chemistry;
    cout<<"\nenter the marks in computer:";
    cin>>s.computer;
    s.cgpa=cgpa(s.physics,s.chemistry,s.math,s.computer,s.english);
    cout<<"\n\n\n\n";
  }


void result(float cgpa)    // function to declare PASS or FAIL
 {
   if(cgpa>=4)
     cout<<"PASS";
   else
     cout<<"FAIL!";
 }


void reportcard(report r)      // function to create report card
{
  clrscr();
  cout<<"___________________________________________________________________________";
  cout<<"\n|                                     |                                    |";
  cout<<"\n|  <<<<<<< STUDENT DETAILS >>>>>>>>>  |	            <<<RESUME>>>           |";
  cout<<"\n|                                     |                                    |";
  cout<<"\n|                                                                           ";
  cout<<"\n| NAME:"<<r.name<<"      CLASS:XI                                           ";
  cout<<"\n|                                               CGPA: "<<r.cgpa<<"            ";
  cout<<"\n|                                                                           ";
  cout<<"\n| ROLL:"<<r.roll<<"      ADMN:"<<r.admn<<"                                  ";
  cout<<"\n|                                     |                                    |";
  cout<<"\n|                                     |                                    |";
  cout<<"\n|-------------------------------------|------------------------------------|";
  cout<<"\n|..........ACADEMIC REPORT............|            TEACHERS' VIEWS         |";
  cout<<"\n|                                     |                                    |";
  cout<<"\n|                                                                           ";
  cout<<"\n| ENGLISH  :"<<r.english<<"                                  COMMENTS:";
  comment(r.cgpa);
  cout<<"\n|                                                                           ";
  cout<<"\n|  MATHS   :"<<r.math<<"                                                    ";
  cout<<"\n|                                             RESULT:";
  result(r.cgpa);
  cout<<"\n| CHEMISTRY:"<<r.chemistry<<"                                               ";
  cout<<"\n|                                                                           ";
  cout<<"\n| PHYSICS  :"<<r.physics<<"                                                 ";
  cout<<"\n|                                     |                                    |";
  cout<<"\n| COMPUTER :"<<r.computer<<"                        |         BEST OF LUCK..........     |";
  cout<<"\n|_____________________________________|____________________________________| ";
}


void show(report s)     // function to show a particular record
 {
   clrscr();
   loading();          // calling loading function
   clrscr();
   reportcard(s);
 }


void create()         // function to create fresh records
 {
   ///n=n+delcounter;
   char choice;
   do{
       cout<<"this is the details of student no."<<(n+1);
       getval(r[n]);
       clrscr();
       n++;
       cout<<"\n Do you want to continue";
       cin>>choice;
      }while(choice=='y' || choice=='Y');
 }


void displaym(int &n)     // function to show the modified records
  {
    clrscr();
    loading();
    clrscr();
    for(int p=0;p<n;p++)
      {
       clrscr();
       reportcard(r[p]);     // calling reportcard function
       getch();
      }
  }


void display()              // function to create existing records
  {
    clrscr();
    loading();
    clrscr();
    for(int p=0;p<n;p++)
      {
       clrscr();
       reportcard(r[p]);
       getch();
      }
  }


void del(report r[],int &n)     // function to delete records
   {
     int sk;
     report temp;
     char found,choice;
     cout<<"enter the admission number:";
     cin>>sk;
     for(int m=0;m<n;m++)
       if(r[m].admn==sk)
	 {
	   found='t';
	   temp=r[m];
	   r[m]=r[m+1];
	   r[m+1]=temp;
	 }
       else
	   found='f';
       if(found=='t')
	 {
	   n=n-1;
	   delcounter=delcounter+1;
	   cout<<"RECORD DELETED.";
	   cout<<"\n\ndo you want to see the record again? [y/n]";
	   cin>>choice;
	   if(choice=='y' || choice=='Y')
	     displaym(n);
	 }
       else
	   cout<<"records not found!!!!!";
  }


void search()             // function to search a record
{
  int admno;
  char st[20],found='f';
  cout<<"by which critertia do you like to search?  [name/admn]";
  gets(st);
  if(strcmpi((st),"name"))
    {
      cout<<"enter the admission number:";
      cin>>admno;
      for(int k=0;k<n;k++)
	if(r[k].admn==admno)
	  {
	    show(r[k]);
	    getch();
	    found='t';
	  }
	   if(found=='f')
	      {
	       cout<<"record not found!!!!!!!";
	       getch();
	      }
   }

else
   {
     char stname[20];
     cout<<"enter the name of the student:";
     gets(stname);
     for(int x=0;x<n;x++)
       {
	 if(!strcmpi(r[x].name,stname))
	   {
	     show(r[x]);
	     getch();
	     found='t';
	   }
       }
	 if(found=='f')
	   {
	     cout<<"record not found!!!";
	     getch();
	   }
   }
}


report getvalm()     // function to accept details to replace the orignal one
  {
    report temp;
    cout<<"enter the name:";
    gets(temp.name);
    cout<<"\n enter the roll numebr:";
    cin>>temp.roll;
    cout<<"\n enter the admn. number:";
    cin>>temp.admn;
    cout<<"\nenter the marks in math:";
    cin>>temp.math;
    cout<<"\nenter the marks in computer:";
    cin>>temp.computer;
    cout<<"\nenter the marks in physics:";
    cin>>temp.physics;
    cout<<"\nenetr the marks in chemistry:";
    cin>>temp.chemistry;
    cout<<"\nenter the marks in english:";
    cin>>temp.english;
    temp.cgpa=cgpa(temp.physics,temp.chemistry,temp.math,temp.computer,temp.english);
    return temp;
  }


void modify()       // function to make changes in the records
  {
    char found='f',choice;
    int sk;
    cout<<"enter the admission number:";
    cin>>sk;
    for(int z=0;z<n;z++)
      if(r[z].admn==sk)
	{
	 show(r[z]);
	 found='t';
	 cout<<"\n do you wnat to modify?  [y/n]";
	 cin>>choice;
	 if(choice=='y' || choice=='Y')
	 r[z]=getvalm();
	 clrscr();
	 cout<<"\n\n\n\n\n\ YOUR RECORDS HAVE BEEN SUCCESSFULLY MODIFIED";
	}
     if(found=='f')
	{
	  cout<<"record not found!!!!";
	  cout<<"\n no modification made..";
	  getch();
	}
 }



 void arrange(report r[],int n)         // function to arrange records rank wise
   {
     int a=1;
     report temp;
     for(int i=0;i<n;i++)
       for(int j=n-1;j>=i;j--)         // nesting of loops
	 if(r[j].cgpa<r[j-1].cgpa)
	   {
	     temp=r[j];
	     r[j]=r[j-1];
	     r[j-1]=temp;
	   }
     cout<<"\n                   NAME              CGPA";
     for(int k=n-1;k>=0;k--)
	cout<<"\n               "<<a++<<". "<<r[k].name<<"           "<<r[k].cgpa;
	getch();
   }



void menu()                     // function to create task menu information
{
clrscr();
cout<<"  ______________________________________________________________________";
cout<<"\n  VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
cout<<"\n(|                                                                      |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|     <<<<<<<<<      TATA DAV PUBLIC SCHOOL,WBC     >>>>>>>>>          |)";
cout<<"\n(|                        ghatotand,Ramgarh                             |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|                 ACEDEMIC PERFORMANCE REPORT FILE                     |)";
cout<<"\n(|                        SESSION=>2013-2014                            |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|    CLASS TEACHER:Mr. S.K Verma                 CLASS- XI \"A\"[sc]     |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|                                                                      |)";
cout<<"\n(|                         TOTAL STRENGTH:"<<n<<"                             |)";
cout<<"\n(|                                                                      |)";

cout<<"\n(|                      principal:-Mrs. Kiran Yadav                     |)";
cout<<"\n(|______________________________________________________________________|)";
cout<<"\n  VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";

cout<<"\n\n              PRESS ENTER TO ACCESS IN THE ACADEMIC FILE.";
getch();
  clrscr();
  int ans;
  do
   {
    clrscr();
    cout<<"\nwhat type of task do you want to do?";
    cout<<"\n___________________________________________________________________";
    cout<<"\n|1.CREATE report card.                                              |";
    cout<<"\n|-------------------------------------------------------------------|";
    cout<<"\n|2.SEE a particular report card                                     |";
    cout<<"\n|-------------------------------------------------------------------|";
    cout<<"\n|3.MODIFY a particular report card                                  |";
    cout<<"\n|-------------------------------------------------------------------|";
    cout<<"\n|4.DISPLAY all report card                                          |";
    cout<<"\n|-------------------------------------------------------------------|";
    cout<<"\n|5.DELETE a particular report card                                  |";
    cout<<"\n|-------------------------------------------------------------------|";
    cout<<"\n|6.see report RANK WISE                                             |";
    cout<<"\n|-------------------------------------------------------------------|";
    cout<<"\n|7.EXIT from result menu.                                           |";
    cout<<"\n_____________________________________________________________________";
    cout<<"\n\n ENETR CHOICE  [1...7]:"; cin>>ans;
    clrscr();
	   switch(ans)
	    {
	      case 1:create();
		     break;
	      case 2:search();
		     break;
	      case 3:modify();
		     break;
	      case 4:display();
		     break;
	      case 5:del(r,n);
		     break;
	      case 6:arrange(r,n);
		     break;
	      case 7:cout<<"thanks for using the program.";
		     cout<<"\n the program will now exit!!!!!!!";
		     cout<<"enter any key";
		     break;
	      default:cout<<"invalid input,try again!!!!!!";
		      getch();
	      clrscr();
	    }
  }while(ans!=7);
    getch();
}


void main()                    // main section
  {
     clrscr();
     menu();
  }