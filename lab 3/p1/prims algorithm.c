#include<stdio.h>
#define inf 999
int main()
{
    int visited[10]={0};
    int i,j,u=0,v=0,n,min,mincost=0,ne=1;
    int cost[10][10];
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix: \n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=inf;
        }
    }
    visited[1]=1;
    while(ne<n)
    {
        min=inf;
        for(int i=1;i<=n;i++)
        {
            if(visited[i])
            {
                for(j=1;j<=n;j++)
                {
                    if(!visited[j] && cost[i][j]<min)
                    {
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        printf("Edge %d: (%d -> %d) Cost: %d\n", ne, u, v, min);
        mincost+=min;
        visited[v]=1;
        ne++;
    }
    printf("Minimum Cost = %d\n", mincost);

    return 0;
}
