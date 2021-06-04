
                                                        /*CALL REGISTER
                                                   DATA STRUCTURES LAB PACKAGE
                                            Done by 20pw01-Abishek and 20pw30-SaiDinesh*/

//INCLUSION OF NECESSARY HEADER FILES
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
fstream fp;

//To set console cursor position
COORD coord={0,0};
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class node          //class for creating nodes and associated functions
{
    private:
        string name,time,date;
        char type;
        node *fwd,*bwd;
        long long int phno;
    public :
        void initialm();
        void initialr();
        void initiald();
        void appendm(string ,long long int ,string ,string,char);
        void appendd(string ,long long int ,string ,string,char);
        void appendr(string ,long long int ,string ,string,char);
        void displaym();
        void displayd();
        void displayr();
        void searchcalls_by_name();
        void searchcalls_by_phno();
}*startm,*startr,*startd,*ptrm,*ptrr,*ptrd;

void node::initialm()   //INITIAL NODE FOR MISSED CALLS
{
    node *N =new node;
    N->name="";
    N->time="";
    N->date="";
    N->bwd=NULL;
    N->fwd=NULL;
    startm=N;
}
void node::initialr()   //INITIAL NODE FOR RECEIVED CALLS
{
    node *N =new node;
    N->name="";
    N->time="";
    N->date="";
    N->bwd=NULL;
    N->fwd=NULL;
    startr=N;
}
void node::initiald()   //INITIAL NODE FOR DIALLED CALLS
{
    node *N =new node;
    N->name="";
    N->time="";
    N->date="";
    N->bwd=NULL;
    N->fwd=NULL;
    startd=N;
}

void node::appendm(string name,long long int phno,string time,string date,char type)  //FUNCTION FOR ADDING MISSED CALLS TO THE LIST
{
    node *N=new node;
    N->name=name;
    fp<<"Name          : "<<name<<endl;
    N->phno=phno;
    fp<<"Phone Number  : "<<phno<<endl;
    N->time=time;
    N->type=type;
    fp<<"Time          : "<<time<<endl;
    N->date=date;
    fp<<"Date          : "<<date<<endl;
    ptrm=startm;
    fp<<"---------------------------------"<<endl;
    fp<<"---------------------------------"<<endl;
    while(ptrm!=NULL && ptrm->fwd!=NULL)
    {
        ptrm=ptrm->fwd;
    }
    N->fwd=NULL;
    N->bwd=ptrm;
    ptrm->fwd=N;
}
void node::appendr(string name,long long int phno,string time,string date,char type)    //FUNCTION FOR ADDING RECEIVED CALLS TO THE LIST
{
    node *N=new node;
    N->name=name;
    fp<<"Name          : "<<name<<endl;
    N->phno=phno;
    fp<<"Phone Number  : "<<phno<<endl;
    N->time=time;
    fp<<"Time          : "<<time<<endl;
    N->date=date;
    fp<<"Date          : "<<date<<endl;
    ptrr=startr;
    fp<<"---------------------------------"<<endl;
    fp<<"---------------------------------"<<endl;
    while(ptrr!=NULL && ptrr->fwd!=NULL)
    {
        ptrr=ptrr->fwd;
    }
    N->fwd=NULL;
    N->bwd=ptrr;
    ptrr->fwd=N;
}
void node::appendd(string name,long long int phno,string time,string date,char type)    //FUNCTION FOR ADDING DIALLED CALLS TO THE LIST
{
    node *N=new node;
    N->name=name;
    fp<<"Name          : "<<name<<endl;
    N->phno=phno;
    fp<<"Phone Number  : "<<phno<<endl;
    N->time=time;
    fp<<"Time          : "<<time<<endl;
    N->date=date;
    fp<<"Date          : "<<date<<endl;
    ptrd=startd;
    fp<<"---------------------------------"<<endl;
    fp<<"---------------------------------"<<endl;
    while(ptrd!=NULL && ptrd->fwd!=NULL)
    {
        ptrd=ptrd->fwd;
    }
    N->fwd=NULL;
    N->bwd=ptrd;
    ptrd->fwd=N;
}

void node::displaym()  //FUNCTION FOR DISPLAYING MISSED CALLS
{
    system("CLS");
    ptrm=startm->fwd;
    while(ptrm!=NULL )
    {
        cout<<"---------------------------------------"<<endl;
        cout<<"NAME         :"<<ptrm->name<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"PHONE NUMBER :"<<ptrm->phno<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"TIME         :"<<ptrm->time<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"DATE         :"<<ptrm->date<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"---------------------------------------\n"<<endl;
        ptrm=ptrm->fwd;
    }
    _cputs("* P R E S S   A N Y   K E Y   T O   C O N T I N U E *");
    _getch();
}
void node::displayr()  //FUNCTION FOR DISPLAYING RECEIVED MISSED CALLS
{
    system("CLS");
    ptrr=startr->fwd;
    while(ptrr!=NULL )
    {
        cout<<"---------------------------------------"<<endl;
        cout<<"NAME         :"<<ptrr->name<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"PHONE NUMBER :"<<ptrr->phno<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"TIME         :"<<ptrr->time<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"DATE         :"<<ptrr->date<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"---------------------------------------\n"<<endl;
        ptrr=ptrr->fwd;
    }
    _cputs("* P R E S S   A N Y   K E Y   T O   C O N T I N U E *");
    _getch();
}
void node::displayd()    //FUNCTION FOR DISPLAYING DIALLED CALLS
{
    system("CLS");
    ptrd=startd->fwd;
    while(ptrd!=NULL )
    {
        cout<<"---------------------------------------"<<endl;
        cout<<"NAME         :"<<ptrd->name<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"PHONE NUMBER :"<<ptrd->phno<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"TIME         :"<<ptrd->time<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"DATE         :"<<ptrd->date<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"---------------------------------------\n"<<endl;
        ptrd=ptrd->fwd;
    }
    _cputs("* P R E S S   A N Y   K E Y   T O   C O N T I N U E *");
    _getch();
}

void welcome()     //FUNCTION FOR MAIN MENU
{
    system("CLS");
    gotoxy(45,6);
    system("color 5F");
    _cputs("W E L C O M E");
    gotoxy(39,9);
    _cputs("C A L L   R E G I S T E R");
    gotoxy(25,12);
    _cputs("D O N E  B Y  : ");
    gotoxy(35,15);
    _cputs("A B I S H E K    A N D    S A I D I N E S H");
    gotoxy(28,18);
    _cputs("* P R E S S   A N Y   K E Y   T O   C O N T I N U E *");
    _getch();
}
void node::searchcalls_by_name()  //FUNCTION FOR SEARCHING CALLS BY NAME
{
    system("CLS");
    string sn;
    int x;
    gotoxy(40,12);
    fflush(stdin);
    cout<<"Enter the name: ";
    getline(cin,sn);
    fflush(stdin);
    ptrm=startm->fwd;
    ptrd=startd->fwd;
    ptrr=startr->fwd;
    int i=0;
    while(ptrm!=NULL)
    {
        if(sn==ptrm->name)
        {
            i++;
            cout<<"Name         : "<<ptrm->name<<endl;
            cout<<"Phone Number : "<<ptrm->phno<<endl;
            cout<<"Type of call : M"<<endl;
            cout<<"Date         : "<<ptrm->date<<endl;
            cout<<"Time         : "<<ptrm->time<<endl;
        }
        ptrm=ptrm->fwd;
    }
    while(ptrr!=NULL)
    {
        if(sn==ptrr->name)
        {
            i++;
            cout<<"Name         : "<<ptrr->name<<endl;
            cout<<"Phone Number : "<<ptrr->phno<<endl;
            cout<<"Type of call : R"<<endl;
            cout<<"Date         : "<<ptrr->date<<endl;
            cout<<"Time         : "<<ptrr->time<<endl;
        }
        ptrr=ptrr->fwd;
    }
    while(ptrd!=NULL)
    {
        if(sn==ptrd->name)
        {
            i++;
            cout<<"Name         : "<<ptrd->name<<endl;
            cout<<"Phone Number : "<<ptrd->phno<<endl;
            cout<<"Type of call : D"<<endl;
            cout<<"Date         : "<<ptrd->date<<endl;
            cout<<"Time         : "<<ptrd->time<<endl;
        }
        ptrd=ptrd->fwd;
    }
    if(i==0)
    {
        cout << "No such calls found" << endl;
    }
    _cputs("ENTER ANY TO CONTINUE");
    _getch();
}
void node::searchcalls_by_phno()    //FUNCTION FOR SEARCHING CALLS BY PHONE NUMBER
{
    system("CLS");
    long long int a;
    gotoxy(40,12);
    cout<<"Enter the Phone Number: ";
    cin>>a;
    ptrm=startm->fwd;
    ptrd=startd->fwd;
    ptrr=startr->fwd;
     while(ptrm!=NULL)
    {
        if(a==ptrm->phno)
        {
            cout<<"Name         : "<<ptrm->name<<endl;
            cout<<"Phone Number : "<<ptrm->phno<<endl;
            cout<<"Type of call : "<<ptrm->type<<endl;
            cout<<"Date         : "<<ptrm->date<<endl;
            cout<<"Time         : "<<ptrm->time<<endl;
        }
        else
        {
            cout<<"No such calls found"<<endl;
        }
        ptrm=ptrm->fwd;
    }
    while(ptrr!=NULL)
    {
        if(a==ptrr->phno)
        {
            cout<<"Name         : "<<ptrr->name<<endl;
            cout<<"Phone Number : "<<ptrr->phno<<endl;
            cout<<"Type of call : "<<ptrr->type<<endl;
            cout<<"Date         : "<<ptrr->date<<endl;
            cout<<"Time         : "<<ptrr->time<<endl;
        }
        else
        {
            cout<<"No such calls found"<<endl;
        }
        ptrr=ptrr->fwd;
    }
    while(ptrd!=NULL)
    {
        if(a==ptrd->phno)
        {
            cout<<"Name         : "<<ptrd->name<<endl;
            cout<<"Phone Number : "<<ptrd->phno<<endl;
            cout<<"Type of call : "<<ptrd->type<<endl;
            cout<<"Date         : "<<ptrd->date<<endl;
            cout<<"Time         : "<<ptrd->time<<endl;
        }
        else
        {
            cout<<"No such calls found"<<endl;
        }
        ptrd=ptrd->fwd;
    }
    _cputs("ENTER ANY TO CONTINUE");
    _getch();
}
int main()     //MAIN FUNCTION
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    welcome();
    node obj;
    string name,time,date,temp;
    long long int phno;
    int d,m,y;
    char type;
    int i;
    date=to_string(t.tm_mday)+"."+to_string(t.tm_mon+1)+"."+to_string(t.tm_year+1900); //GETS SYSTEM TIME
    time=to_string(t.tm_hour)+":"+to_string(t.tm_min)+":"+to_string(t.tm_sec);     //GETS SYSTEM DATE
    fp.open(date+".txt",ios::app);
    obj.initiald();
    obj.initialr();
    obj.initialm();
    system("CLS");
    do
    {
        system("CLS");
        system("color E4");
        gotoxy(40,6);
        cout<<"Enter your choice "<<endl;
        gotoxy(40,8);
        cout<<"0. To exit"<< endl;
        gotoxy(40,10);
        cout<<"1. Enter a call"<<endl;
        gotoxy(40,12);
        cout<<"2. Display Missed calls"<<endl;
        gotoxy(40,14);
        cout<<"3. Display Dialed calls "<<endl;
        gotoxy(40,16);
        cout<<"4. Display received calls "<<endl;
        gotoxy(40,18);
        cout<<"5. Search calls by name "<<endl;
        gotoxy(40,20);
        cout<<"6. Search calls by phone number "<<endl;
        gotoxy(40,22);
        cout<<"7. Open all calls of that day"<<endl;
        gotoxy(40,24);
        cout<<"ENTER YOUR INPUT HERE: ";
        cin>>i;
        if (i==1)
        {
            system("CLS");
            fflush(stdin);
            cout<<"Enter the name: ";
            getline(cin,name);
            fflush(stdin);
            cout<<"Enter the type: ";
            cin>>type;
            cout<<"Enter the ph. no: ";
            cin>>phno;
            if(type=='M' || type=='m')
            {
                obj.appendm(name,phno,time,date,type);
            }
             if(type=='R' || type=='r')
            {
                obj.appendr(name,phno,time,date,type);
            }
            if(type=='d' || type=='D')
            {
                obj.appendd(name,phno,time,date,type);
            }
        }
        else if(i==2)
        {
            obj.displaym();
        }
        else if(i==3)
        {
            obj.displayd();
        }
        else if(i==4)
        {
            obj.displayr();
        }
        else if(i==5)
        {
            obj.searchcalls_by_name();
        }
        else if(i==6)
        {
            obj.searchcalls_by_phno();
        }
        else if(i==7)   //MODULE TO DISPLAY CALL HISTORY OF PARTICULAR DAY
        {
            char chars;
            system("CLS");
            system("color DF");
            cout << "\n\n\t\tEnter the date: ";
            cin >> d >> m >> y;
            if(d>0 && d<=31 && m>0 && m<=12 && y>2000 && y<=int(t.tm_year+1900))
            {
                temp = to_string(d)+"."+to_string(m)+"."+to_string(y);
                fstream f;
                f.open(temp+".txt");
                if(!f)
                {
                    cout << "\t\tNo such records found";
                }
                else
                {
                    f.get(chars);
                    while(!f.eof())
                    {
                        cout << chars;
                        f.get(chars);
                    }
                    f.close();
                }
                _cputs("\n\t\t\tENTER ANY TO CONTINUE");
                _getch();
            }
            else
            {
                cout <<"\n\tInvalid date";
                _cputs("\n\t\t\tENTER ANY TO CONTINUE");
                _getch();
            }
        }
        else if(i==0)
        {
            exit(0);
        }
        else
        {
            cout<<"\n\t\tWrong choice re-enter your choice!";
            _cputs("\t\tEnter any to continue");
            _getch();
        }
    }while(i);
    fp.close();
    return 0;
}
