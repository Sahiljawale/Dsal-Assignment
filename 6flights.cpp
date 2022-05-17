#include<iostream>
using namespace std;
class cn{
    public:
        string s;
};
int main(){
    int n,m,k,c1,c2;
    int a[20][20];
    cout<<"\n Enter number of cities: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    cn A[n];
    cout<<"\n Enter names of cities: ";
    for(int i=0;i<n;i++){
        cin>>A[i].s;
    }
    cout<<"\n Remember unique ids of the entered cities: \n";
    for(int i=0;i<n;i++){
        cout<<i<<"---->"<<A[i].s<<"\n";
    }
    cout<<"\n Enter number of edges: ";
    cin>>m;
    for(int i=0;i<m;i++){
        cout<<"\n Enter city numbers having edges in between: ";
        cin>>c1>>c2;
        cout<<"\n Enter weight of the edge: ";
        cin>>k;
        a[c1][c2]=k;
        a[c2][c1]=k;
    }
    cout<<"\n The Paths are:\n  ";
    for(int i=0;i<n;i++){
        cout<<"\t"<<A[i].s;
    }
    for(int i=0;i<n;i++){
        cout<<"\n"<<A[i].s<<"\t";
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
    }
    return 0;
}
