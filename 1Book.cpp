/**
A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space requirements 
of your method.
**/

//ASSIGNMENT NO -1
#include <iostream>
using namespace std;

struct node{
    char name[20];
    int child_ele;
    node *child[20];
}*root;  //object pointer of type node

class Book{
    public:
    void create_tree();
    void display(node *r1);
    Book(){
        root==NULL;
    }
};

void Book::create_tree(){
    int books,chapters;
    root=new node;
    cout<<"Enter name for book : ";
    cin>>root->name;
    
    cout<<"Enter number of chapters in book : ";
    cin>>chapters;
    root->child_ele=chapters;
    
    for(int i=0;i<chapters;i++){
        root->child[i]=new node;
        cout<<"Enter name of chapter : ";
        cin>>root->child[i]->name;
        cout<<"Enter number of sections in the chapters : ";
        cin>>root->child[i]->child_ele;

        for(int j=0;j<root->child[i]->child_ele;j++){
            root->child[i]->child[j]=new node;
            cout<<"Enter name for section : ";
            cin>>root->child[i]->child[j]->name;
            cout<<"Enter number of subsections for the section : ";
            cin>>root->child[i]->child[j]->child_ele;
            
            for(int k=0;k<root->child[i]->child[j]->child_ele;k++){
                root->child[i]->child[j]->child[k]=new node;
                cout<<"Enter name for subsection : ";
                cin>>root->child[i]->child[j]->child[k]->name;
            }
        }
    }
    
}

void Book::display(node *r1){
    int chapters;
    if(r1 != NULL){
        cout<<"*********"<<endl;
        cout<<"BOOK DATA"<<endl;
        cout<<"*********"<<endl;
        cout<<"Book name : "<<r1->name<<endl;
        chapters=r1->child_ele;
        for(int i=0;i<chapters;i++){
            cout<<" Chapter "<<i+1<<" : ";
            cout<<r1->child[i]->name<<endl;
            for(int j=0;j<r1->child[i]->child_ele;j++){
                cout<<"  Sections: ";
                cout<<r1->child[i]->child[j]->name<<endl;
                for(int k=0;k<r1->child[i]->child[j]->child_ele;k++){
                    cout<<"   Subsections: ";
                    cout<<r1->child[i]->child[j]->child[k]->name<<endl;
                }
            }
        }
        
    }
}
int main(){
    int choice;
    Book b1;
    while(1){
        cout<<"\n--------------------"<<endl;
        cout<<" BOOK TREE CREATION"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : 
                b1.create_tree();
                break;
            case 2 : 
                b1.display(root);
                break;
            case 3 : 
                exit(0);
            default:
                cout<<"Wrong choice";
        }
    }
    return 0;
}

/***
chapters  O(n)
sections  O(n*m)
sub sections  O(n*m*k)

space-  O(n*m*k)
**/
