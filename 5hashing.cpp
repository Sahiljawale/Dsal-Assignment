#include<bits/stdc++.h>
using namespace std;

class telephone{
  int address,no;
  long long tele[10],key;
  string name[10];
  public:
  telephone(){
    for(int i=0;i<10;i++){
      tele[i]=0;
      name[i]="-";
    }
  }
  void insert();
  void display();
  int hashfunc(long long key);
  void collison_linear(long long tele[],string name[],long long key);
  void collison_qduadratic(long long tele[],string name[],long long key);
  
};

void telephone::insert(){
  cout<<"Enter No of records u want to enter: ";
  cin>>no;
  cout<<endl;
  cout << "Which Collision handling technique do you want to use"<< endl << "1. Linear Probing" << endl << "2. Quadratic Probing" << endl;
		int flag;
		cout << "Enter your Choice :- ";
		cin >> flag;
		cout << endl;
  while(no--){
      cout<<"Enter telephone no: ";
      cin>>key;
      address=hashfunc(key);
      if(tele[address]==0){
        tele[address]=key;
        cout<<"Enter Name: ";
        cin>>name[address];
      }
      else if(flag==1)
        collison_linear(tele,name,key);
      
      else if(flag==2)
        collison_qduadratic(tele,name,key);
  }

}

void telephone::collison_linear( long long tele[],string name[],long long key){
  int adr=hashfunc(key);
  while(tele[adr%10]!=0){
    adr++;
  }
  tele[adr % 10] = key;
  cout << "Enter name: ";
  cin >> name[adr % 10];
}

void telephone::collison_qduadratic(long long tele[],string name[],long long key){
  int adr=hashfunc(key);
  int i=1;
  while(tele[adr%10]!=0){
    adr+=i*i;
    i++;
  }
  tele[adr % 10] = key;
  cout << "Enter name of the person :- ";
  cin >> name[adr % 10];
}

void telephone::display(){
  cout<<"INDEX\tNAME\tNUMBER\n";
  for (int i = 0; i < 10; i++)
      cout << i << "\t" << name[i] << "\t" << tele[i] << endl;
  
}

int telephone::hashfunc(long long key){
    return key%10;
}

int main()
{

    telephone t1;

    int choice;
    char ch;

    do
    {
        cout << "****Telephone Directory****" << endl;
        cout << "1. Insert record in Directory" << endl;
        cout << "2. Display Telephone Directory" << endl;
        cout << "3. Exit" << endl;
       
        cout<< endl;
        cout<<"Enter your choice :- ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            t1.insert();
            break;
        case 2:
            t1.display();
            break;
        }
    } while (choice < 3);

    cout << "Thanks for Using My software" << endl;

    return 0;
}
