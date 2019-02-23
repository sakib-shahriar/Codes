#include<bits/stdc++.h>
using namespace std;
struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist node;
node *graph[100];
int visitedList[100];
void bfs(int ver)
{
    queue<int> que;
    que.push(graph[0]->data);
    visitedList[graph[0]->data]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        cout<<u<<" ";
        node *temp=graph[u]->next;
        while(temp!=NULL){
            if(visitedList[temp->data]==0){
                que.push(temp->data);
                visitedList[temp->data]=1;
            }
            temp=temp->next;
        }
    }
}
int main()
{
    int edge,ver;
    cout<<"Enter number of edge & vertices"<<endl;
    cin>>edge>>ver;
    for(int i=0;i<ver;i++){
        graph[i]=new node();
        graph[i]->data=i;
        graph[i]->next=NULL;
    }
    cout<<"Enter the graph"<<endl;
    for(int i=0;i<edge;i++){
        int vertex1,vertex2;
        cin>>vertex1>>vertex2;
        node *temp=graph[vertex1];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node();
        temp->next->data=vertex2;
        temp->next->next=NULL;
    }
    bfs(ver);
    return 0;
}
