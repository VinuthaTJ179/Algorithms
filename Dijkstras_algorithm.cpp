//Dijkstra's algorithm
#include <iostream>
#define SIZE 10
using namespace std;
void Dijkstra(int arr[SIZE][SIZE],int n,int src)
{
    int distance[n],visited[n]={0},i,j,mindistance,nextnode,count=0;
    for(i=0;i<n;i++)
    {
        distance[i] = arr[src][i];
    }
    distance[src]=0;
    visited[src]=1;
    count = 1;
    while(count<(n-1))
    {
        mindistance=999;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindistance && visited[i]==0)
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                if((mindistance + arr[nextnode][i])<distance[i])
                {
                    distance[i] = mindistance + arr[nextnode][i];
                }
            }
        }
        count++;
    }
    for(i=0;i<n;i++)
    {
        if(i!=src)
        {
            cout<<"Distance from source to: "<<i<<" is "<<distance[i]<<endl;
        }
    }
    return;
}
int main(){
    int n,i,j;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>n;
    int arr[SIZE][SIZE],src=0;
    cout<<"Enter the cost adjacency matrix: "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter the source vertex: "<<endl;
    cin>>src;
    Dijkstra(arr,n,src);
    return 0;
}
