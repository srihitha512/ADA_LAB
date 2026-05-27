#include<stdio.h>
#define max 10
#define inf 999
int parent[max]={0};
int find(int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}
int unionset(int i,int j)
{
    if(i !=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    int cost[10][10],u,v,i,j,mincost=0,ne=1,n,a,b,min;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=inf;
        }
    }
    printf("EDGE\tCOST\n");
    while(ne<n)
    {
        min=inf;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(unionset(u,v))
        {
            printf("%d->%d\t%d\n",a,b,min);
            mincost+=min;
            ne++;
        }
        cost[a][b] = cost[b][a] = inf;
    }

    printf("Minimum Cost = %d\n", mincost);
    return 0;

}

