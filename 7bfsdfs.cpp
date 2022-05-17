#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void DFS(int mat[10][10],int n){
  int visted[100];
  int start;
  stack<int> s;
  for(int i=0;i<n;i++){ //mark all vertices as un-visted
    visted[i]=0;
  }
  start=0;
  s.push(start);
  while(!s.empty()){ //while stack is ot empty
    start=s.top();
    s.pop();
    if(visted[start]==0){ //if not visted
      cout<<start<<" "; //print
      visted[start]=1; //mark as visted
      for(int ad=n;ad>0;ad--){ // get all adjancent vertices
        if(mat[start][ad]==1){ //if edge is there
          s.push(ad); //push into stack 
        }
      }
    }
  }
}

void BFS(int mat[10][10],int n){
  int visted[100];
  int start;
  queue<int> que;
  for(int i=0;i<n;i++){
    visted[i]=0;
  }
  start=0;
  que.push(start);
  visted[start]=1;
  while(!que.empty()){
    start=que.front();
    que.pop();
    cout<<start<<" ";
    for(int ad=0;ad<n;ad++){
      if(mat[start][ad]==1 && visted[ad]==0){
        que.push(ad);
        visted[ad]=1;
      }
    }
  }
}

int main(){
    int cost[10][10];
    int n,m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j]=0;        
            }
    }
    cout << "\nEDGES :\n";
    for (int k = 1; k <= m; k++){
        int v1,v2;
        cin>>v1>>v2;
        cost[v1][v2] = 1;
        cost[v2][v1] = 1;
    }
    cout << "The adjacency matrix of the graph is : " << endl;
    for(int i=0;i<n;i++){
        cout<<"\t"<<i;
    }
    for(int i=0;i<n;i++){
        cout<<"\n"<<i<<"\t";
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<<"\t";
        }
    }
    cout << "\n\nDFS is: " << endl;
    DFS(cost,n);
    cout<<"\n\nBFS is: "<<endl;
    BFS(cost,n);

    return 0;
}
