#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
int main();
void booking();
void verify();
void view();
void exit();

// Implement file operation class
//fstream fout("Info.txt",ios::app);

// Temporary array for storing the data
int ids[10];
string names[10];
long phones[10];
int seats[10];
string priorities[10];
int amount[10];
string priority_array[]={"First class","Second class","Normal class"};

// Get current time

time_t now=time(0);
char* timestamp=ctime(&now);
/*
fstream times("Info.txt",ios::app);
times<<timestamp<<endl;
times.close();
*/
// structure of the details
struct detail
{
int id=0;
long phone;
string name;
int seat;
int priority;
};
struct detail person_1;

void booking()
{
fstream fout("Info.txt",ios::app);
cout<<"\t\t\tEnter your name :";
cin>>person_1.name;
cout<<"\t\t\tEnter phone :";
cin>>person_1.phone;
cout<<"\t\t\tNumber of seats :";
cin>>person_1.seat;
cout<<"\n\t\t\t********PRIORITY********\n\t\t\t1.First class\n\t\t\t2.Second class\n\t\t\t3.Normal class\n\t\t\t***********************\n\t\t\t:";
cin>>person_1.priority;

// insert into file
fout<<timestamp<<endl;

//flag for amount decision
int flag;
switch(person_1.priority-1){
case 0:
    flag=300;
    break;
case 1:
    flag=200;
    break;
case 3:
    flag=100;
    break;
}

fout<<"\n"<<++person_1.id<<"\t"<<person_1.name<<"\t"<<person_1.phone<<"\t"<<person_1.seat<<" seats"<<"\t"<<priority_array[person_1.priority-1]<<"\t"<<"Rs : "<<person_1.seat*flag<<"\n";

//temp array stored
ids[person_1.id]=person_1.id;
names[person_1.id]=person_1.name;
phones[person_1.id]=person_1.phone;
seats[person_1.id]=person_1.seat;
priorities[person_1.id]=person_1.priority;
amount[person_1.id]=person_1.seat*flag;

string totalString="\n\t\t\tTotal Amount is :";
cout<<"\n\t\t\tTicket is booked\n";

switch(person_1.priority-1){
case 0:
   cout<<"\n\t\t\tFirst Class : 300/-\n";
   cout<<totalString<<person_1.seat*flag<<endl;
   break;
case 1:
   cout<<"\n\t\t\tSecond Class : 200/-\n";
   cout<<totalString<<person_1.seat*flag<<endl;
   break;
case 2:
   cout<<"\n\t\t\tNoraml Class : 100/-\n";
   cout<<totalString<<person_1.seat*flag<<endl;
   break;
}


cout<<"\t\t\tPlease note your id :"<<person_1.id;

fout.close();

main();
}

void verify(){
string line;
fstream fin("Info.txt",ios::in);
//cout<<"| ID |"<<"| Name |"<<"| Phone |"<<"| Seats |"<<"| Priority |";
do
{
getline(fin,line);
cout<<line<<endl;

}while(fin);
fin.close();
main();
}


void view(){
int tempId;
cout<<"\n\t\t\tEnter the id number : ";
cin>>tempId;
if(ids[tempId]!=0){
cout<<"\n\t\t"<<ids[tempId]<<"\t"<<names[tempId]<<"\t"<<phones[tempId]<<"\t"<<seats[tempId]<<" seats"<<"\t"<<priority_array[tempId-1]<<"\t"<<amount[tempId]<<"/-\n";
}else{
cout<<"\t\t\tSorry entry not found..."<<endl;
}
main();
}


void exit()
{
cout<<"Train portal is exit\n";
}

int main()
{
int choice;
cout<<"\n\t\t\t1.Booking\n\t\t\t2.Total\n\t\t\t3.View\n\t\t\t4.Exit\n\t\t\t:";
cin>>choice;

//switch for choice
switch(choice)
{
case 1:
   booking();
   break;
case 2:
   verify();
   break;
case 3:
   view();
   break;
case 4:
   exit();
   break;
 
}
}
