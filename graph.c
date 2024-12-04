#include<stdio.h>
#define MAX 5
void bfs(int adj[][MAX],int visited[],int start)
{
    int q[MAX],front=-1,rear=-1,i;
    for(i=0;i<MAX;i++)
        visited[i]=0;
    q[++rear]=start;
    ++front;
    visited[start]=1;
    while(rear>=front)
    {
        start=q[front++];
        printf("%c -> ",start+'A');
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]&&visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }
    for(i=0;i<MAX;i++)
        {
            if(visited[i]==0)
            {
                printf("\nGraph is disconnected\n");
                return;
            }
        }
        printf("\nGraph is connected\n");
}
void dfs(int adj[][MAX],int visited[],int start)
{
    int s[MAX],top=-1,i;
    int first=start;
    for(i=0;i<MAX;i++)
        visited[i]=0;
    s[++top]=start;
    visited[start]=1;
    while(top!=-1)
    {
        start=s[top--];
        printf("%c -> ",start+'A');
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]&&visited[i]==0)
            {
                s[++top]=i;
                visited[i]=1;
                break;
            }
        }
    }
    for(i=0;i<MAX;i++)
    {
        if(visited[i]==1)
        {
            printf("its  a cycle");
            break;
        }
        if(start==first)
        {
            printf("\nIt is a cycle\n");
        }
    }

}
int main()
{
    int adj[MAX][MAX],visited[MAX],i,j;
    printf("Enter the adjacency matrix\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nDFS\n");
    dfs(adj,visited,1);
    printf("\nBFS\n");
    bfs(adj,visited,0);
    return 0;
}
