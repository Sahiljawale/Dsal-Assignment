#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Dict{
    string w;
    string m;
};
class Hash{
    public:
        string word;
        string mean;
        int ch=-1;
};
Hash h[10];
int asciical(string s){
    int a=0;
    for(int i=0;s[i]!='\0';i++){
        a+=s[i];
    }
    return a;
}

void insert(){
    Dict a;
    cout<<"\nEnter word: ";
    cin>>a.w;
    cout<<"\nEnter meaning: ";
    cin>>a.m;
    int k=asciical(a.w);
    int c;
    k=k%10;
    if(h[k].word=="NULL"){
        h[k].word=a.w;
        h[k].mean=a.m;
    }
    else{
        cout<<"\nCollision Occured!\nChaining";
        c=k;
        for(int i=1;i<10;i++){
            c=k;
            c=(c+i)%10;
            if(h[c].word=="NULL"){
                h[c].word=a.w;
                h[c].mean=a.m;
                while(k!=-1){
                    if(h[k].ch==-1){
                        h[k].ch=c;
                        break;
                    }
                    k=h[k].ch;
                }
                break;
            }
        }
    }
    
}
void show(){
    cout<<"\nWORD--->MEANING\n";
    for(int i=0;i<10;i++){
        cout<<h[i].word<<"--->"<<h[i].mean<<endl;
    }
}
void search(){
    string k;
    int f=0;
    cout<<"\nEnter the word to be searched: ";
    cin>>k;
    int c=asciical(k);
    c=c%10;
    while(c!=-1){
        if(h[c].word==k){
            cout<<"\n WORD FOUND at position "<<c<<"\n Word:-"<<h[c].word<<"\n Meaning:-"<<h[c].mean;
            f=1;
            cout<<endl<<h[c].ch;
            break;
        }
        c=h[c].ch;
    }
    if(f==0){
        cout<<"\n WORD NOT FOUND";
    }
}
void del(){
    string k;
    int f=0;
    cout<<"\nEnter the word to be deleted: ";
    cin>>k;
    for(int i=0;i<10;i++){
        if(h[i].word==k){
            cout<<"\nWORD DELETED";
            h[i].word="NULL";
            h[i].mean="NULL";
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<"\n WORD NOT FOUND";
    }  
}
int main(){
    int c;
    for(int i=0;i<10;i++){
        h[i].word="NULL";
        h[i].mean="NULL";
    }
    while(true){
        cout<<"\n1. Insert\n2. Search\n3. Delete\n4. Show\n5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c){
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                del();
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}
