//Assignment No 12
/*
Department maintains a student information. The file contains roll number, name, division, and address. Allow user to add, delete information of student. 
Display information of particular employee. 
If record of student does
not exist an appropriate message is displayed. If it is, then the 
system displays the student details. Use sequential file to main
the data.
*/
#include<iostream>
#include<fstream>
using namespace std;

class student{
       int admno;
       char div[10];
       char name[20];
       char addr[30];
       public:
       void setData(){
              cout << "\nEnter Roll NO: ";
              cin>>admno;
              cout << "Enter name: ";
              cin>>name;
              cout<<"Enter Div: ";
              cin>>div;
              cout<<"Enter Address: ";
              cin>>addr;
       }
       void showData(){
              cout << "\n*Student Roll No : " << admno;
              cout << "\n*Student Name : " << name;
              cout<<"\n*Student Div: "<<div;
              cout<<"\n*Address: "<<addr;
              cout<<endl;
       }
       int retAdmno(){
              return admno;
       }
};
void write_record(){
       ofstream outFile;
       outFile.open("student.dat", ios::binary | ios::app);
       student obj;
       obj.setData();
       outFile.write((char*)&obj, sizeof(obj));
       outFile.close();
}
void display(){
       ifstream inFile;
       inFile.open("student.dat", ios::binary);
       student obj;
       while(inFile.read((char*)&obj, sizeof(obj))){
              obj.showData();
       }
       inFile.close();
}
void search(int n){
       ifstream inFile;
       inFile.open("student.dat", ios::binary);
       int flag=0;
       student obj;
       while(inFile.read((char*)&obj, sizeof(obj))){
              if(obj.retAdmno() == n){
                     obj.showData();
                     flag=1;
                     break;
              }
       }
       if(flag==0)
              cout<<"\n\n Record Not Found\n";
       inFile.close();
}
void delete_record(int n){
       student obj;
       ifstream inFile;
       inFile.open("student.dat", ios::binary);
       ofstream outFile;
       outFile.open("temp.dat", ios::out | ios::binary);
       while(inFile.read((char*)&obj, sizeof(obj))){
              if(obj.retAdmno() != n){
                     outFile.write((char*)&obj, sizeof(obj));
              }
       }
       inFile.close();
       outFile.close();
       remove("student.dat");
       rename("temp.dat", "student.dat");
}
int main(){
       int ch;
       do{
              cout<<"\n**************"<<endl;
              cout<<"FILE OPERATION"<<endl;
              cout<<"**************"<<endl;
              cout<<"1. Write \n2. Display \n3. Search \n4. Delete \n5 .Exit"<<endl;
              cout<<"Enter Ur Choice: ";
              cin>>ch;
              switch(ch){
                     case 1: 
                            cout<<"Enter number of records: ";
                            int n;
                            cin>>n;
                            for(int i = 0; i <n; i++)
                                   write_record();
                            break;
                     case 2:
                            cout << "\nList of records:\n";
                            display();
                            break;
                     case 3:
                            cout<<"Enter Student Roll No: ";
                            int s;
                            cin>>s;
                            search(s);
                            break;
                     case 4:
                            cout<<"Enter no to be deleted: ";
                            int d;
                            cin>>d;
                            delete_record(d);
                            cout << "\nRecord Deleted\n";
                            break;
                     case 5:
                            exit(0);
              }
       }while(ch!=5);
       return 0;
}
