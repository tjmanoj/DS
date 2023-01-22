#include<stdio.h>
#include<stdlib.h>
void prims();
int main(){
	int i,j,n,s,cost[50][50];
	printf("Enter number of nodes:");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j]=999;
		}
	}
	prims(n,cost);
}
void prims(int n,int cost[50][50]){
	int i,j,u,v,min,mincost=0,visit[50],ne=1;
	for(i=0;i<=n;i++)
		visit[i] = 0;
	printf("S.no\tEdge\tWeight\n");
	visit[1]=1;
	while(ne < n){
		min=999;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j] < min ){
					if(visit[i] == 0)
						continue;
					else{
						min = cost[i][j];
						u=i;
						v=j;
					}
				}
		if(visit[u] == 0 || visit[v] == 0){
			printf("%d\t%d->%d\t%d\n",ne++,u,v,min);
			mincost+=min;
			visit[v]=1;
		}
		cost[u][v] = cost[v][u]=999;
	}
	printf("Mininum cost:%d",mincost);
}
