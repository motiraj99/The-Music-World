#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <iomanip.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <fstream.h>

void password();
void Manage();
void Menu();
void Purchase();
void readcd();
void writecd();
void appendcd();
void findcd();
void delcd();

class CD
  {
      int cdno;
      char name[20];
      char Artist[20];
      char Comp[20];
      char Lang[10];
      char Type[10];
      double price;
   public:
      void getcd()
      {
	cout<<"\n         CD/DVD No        :  ";
	cin>>cdno;
	cout<<"\n         Enter CD Name    : ";
	gets(name);
	cin.getline(name,20);
	cout<<"\n         Enter Artist Name : ";
	//gets(Artist);
	cin.getline(Artist,20);
	cout<<"\n         Enter Company Name: ";
	//gets(Comp);
	cin.getline(Comp,20);
	cout<<"\n         Enter Language    :";
	cin.getline(Lang,10);
	cout<<"\n         Enter Type CD/DVD :";
	cin.getline(Type,10);
	cout<<"\n         Enter Price of CE : ";
	cin>>price;
      }
     void dispcd()
      {

	 cout<<"\n"<<cdno<<"\t"<<name<<"\t"<<Artist<<"\t"<<Comp<<"\t"<<Lang<<"\t"<<Type<<"\t"<<price;
      }

     int getcdno()
      {
	 return cdno;
      }

 };

void readcd()
      {
	CD cd;
	ifstream fin;
	fin.open("cd.dat",ios::in|ios::binary);
	while(fin.read((char *)&cd,sizeof(cd)))
	{
	   cd.dispcd();
	}
	fin.close();
	getch();
      }

void writecd()
      {
	CD cd;
	ofstream fout;
	fout.open("cd.dat",ios::out|ios::binary);
	char ch;
	do
	{
	  cd.getcd();
	  fout.write((char * ) &cd,sizeof(cd));
	  cout<<"\nDO YOU WANT TO CONTINUE Y/N =";
	  cin>>ch;
	}while(ch!='N' && ch !='n');
		fout.close();
      }
void appendcd()
     {
	CD cd;
	ofstream fout;
	fout.open("cd.dat",ios::app|ios::binary);
	char ch;
	do
	{
	  cd.getcd();
	  fout.write((char * ) &cd,sizeof(cd));
	  cout<<"\nDO YOU WANT TO CONTINUE Y/N =";
	  cin>>ch;
	}while(ch!='N' && ch !='n');
	fout.close();
   }

void findcd()
   {

	CD cd;
	ifstream fin;
	fin.open("cd.dat",ios::in|ios::binary);
	cout<<"Enter the No. of the CD/DVD =";
	int cno;
	cin>>cno;

	int i=1;
	while(fin.read((char *)&cd,sizeof(cd)))
	{
	  if(cno==cd.getcdno())
	  {
	     cout<<"\nReord Found at Position = "<<i<<"\n";
	     cd.dispcd();
	  }
	  i++;
	}
	if(i==1)
	  cout<<"\nRecord Not Found =";
		fin.close();
	getch();
   }
void delcd()
{
  CD cd;
  fstream file1,file2;
  int cno;
  file1.open("cd.dat",ios::in|ios::binary);
  file2.open("temp.dat",ios::out|ios::binary);
  cout<<"Enter cd no which you want delete =";
  cin>>cno;
  char found='n',conf;

  while(file1.read((char *) &cd,sizeof(cd)))
  {
       if(cd.getcdno() == cno)
       {
	 cd.dispcd();
	 found='t';
	 cout<<"\nAre you sure, you want to delete this record? (y/n)..\n";
	 cin>>conf;
	 if (conf=='n'||conf=='N')
	   file2.write((char *) &cd,sizeof(cd));
       }
       else
	   file2.write((char *) &cd,sizeof(cd));
  }
  if (found=='f')
   cout<<"record not found!!\n";

  file1.close();
  file2.close();
  remove("cd.dat");
  rename("temp.dat","cd.dat");
  cout<<"RECORD DELETED"<<endl;
  readcd();
  getch();
}

//***********************************************************************

void main()
{
	clrscr();
	password();

	getch();
}
//************************************************************************

void password()
{
	char pass[10];
	for(int k=0;k<10;++k)
	{
	  pass[k]='\0';
	}
	cout<<"\n           Welcome to Music World Customer\n";
	cout<<"\n           Press y/Y to login\n";
	char ch;
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
	  for(int i=0;i<3;++i)
	  {
	    cout<<"\n       Enter Password \n";

	    for(int j=0;j<10;++j)
	    {
	      char chk;
	      chk=getch();
	      if(chk!='\r')
	      {
		cout<<"*";
		pass[j]=chk;
	      }
	      else
		break;
	    }
	    if(strcmp(pass,"cpp"))
	      {
		clrscr();
		cout<<"\n\n   Sorry Invalid Password !!!!";
		for(int k=0;k<10;++k)
		{
		  pass[k]='\0';
		}

	      }
	  else
	     {
		clrscr();
		cout<<"\n\nWelcome to the Successful Login............";
		Menu();
		break;
	     }
	  }
	}
	else
	  cout<<"\nYou don't want to login ok.....Bye\n";
	  getch();
	  exit(0);
}
//*********************************************************************

void Menu()
{
    clrscr();
    cout<<"                        MUSIC WORLD\n\n";
    cout<<"			   1.To Purchase a CD/DVD\n";
    cout<<"			   2.To Manage CD/DVD Store\n";
    cout<<"			   3.To Exit\n";
    cout<<"			   4.To Logout\n";
    cout<<"			   Select your choice....!\n";
    int ch2;
    cin>>ch2;
    switch(ch2)
    {
       case 1: cout<<"\n\n";
	       Purchase();
	       Menu();
       case 2: cout<<"\n";
	       Manage();
	       Menu();
       case 3: exit(0);
       case 4: password();
       default:cout<<"Entered wrong choice\n";
	       password();

    }

}

void Manage()
{
    clrscr();
    CD cd;
    cout<<"                        Music World\n\n";
    cout<<"                        1.To see All CD's/DVD's\n";
    cout<<"                        2.To Write a CD/DVD\n";
    cout<<"                        3.To Add a CD/DVD\n";
    cout<<"                        4.To Search a CD/DVD by No.          \n";
    cout<<"                        5.To Delete a CD/DVD\n";
    cout<<"                        6.Go back to Main menu\n";
    cout<<"                        Select your choice....!\n";
    //**********************************************************************
    int ch4;
    cin>>ch4;
    switch(ch4)
    {
       case 1: cout<<"List of all CD's/DVD's available in this store\n";
	       cout<<"**********************************************\n";
	       cout<<"CD No. Name   Artist  Comp  Lang  Type   Price\n";
	       cout<<"**********************************************\n";
	       readcd();
	       Menu();
       case 2: writecd();
	       Menu();
       case 3: appendcd();
	       Menu();
       case 4: findcd();
	       Menu();
       case 5: delcd();
	       Menu();
       case 6: Menu();

       default: cout<<"Entered wrong choice\n";
		Menu();

    }

}
void Purchase()
{
 clrscr();
 CD cd,cd1;
 char Cname[20];
 cout<<"\nHello Warm welcome to Music World kindly enter your name\n";
 gets(Cname);
 fstream fcus,fcd;
 fcd.open("cd.dat",ios::in|ios::binary);
 fcus.open(strcat(Cname,".dat"),ios::out|ios::binary);
 char conf;
 do
 {
      int cno;char f='f';
      cout<<"\nkindly enter cd No. you want to purchase :";
      cin>>cno;
      while(fcd.read((char *) &cd1,sizeof(cd1)))
      {
	   if(cd1.getcdno() == cno)
	   {
	    cd1.dispcd();
	    f='t';
	    cout<<"\nYou have selected this CD/DVD to purchase..... (y/n)..\n";
	    char ch;
	    cin>>ch;
	    if (ch=='y'||ch=='Y')
	      fcus.write((char *) &cd1,sizeof(cd1));
	   }

       }
       if(f=='f')
       cout<<"CD/DVD not found!!....\n";
       cout<<"\nDO YOU WANT TO ADD another CD/DVD... Y/N =";
       cin>>conf;
  }while(conf!='N' && conf!='n');
  fcd.close();
  fcus.close();
  fcus.open(strcat(Cname,".dat"),ios::in|ios::binary);
  cout<<"\nYour selected List of CD/DVDs\n\n";
  while(fcus.read((char *) &cd1,sizeof(cd1)));
  {
    cd1.dispcd();
  }
  fcus.close();

  getch();
}


