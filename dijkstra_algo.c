#include<stdio.h>
#include<stdlib.h>
void dijkstra();
int main(){
	int i,j,n,s,cost[10][10],dist[10];
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
	printf("Enter source vertex:");
	scanf("%d",&s);
	dijkstra(n,cost,s,dist);
	printf("Shortest paths from vertex %d are:\n",s);
	for(i=1;i<=n;i++){
		if(s!=i)
			printf("%d -> %d : %d\n",s,i,dist[i]);
	}
	return 0;
}
void dijkstra(int n,int cost[10][10],int s,int dist[10]){
	int i,v,min,count=1,visit[10];
	for(i=1;i<=n;i++){
		visit[i]=0;
		dist[i]=cost[s][i];
	}
	visit[s]=1;
	dist[s]=0;
	while(count <= n){
		min = 999;
		for(i=1;i<n;i++)
			if(dist[i] < min && visit[i] == 0){
				min=dist[i];
				v=i;
			}
		visit[v]=1;
		count++;
		for(i=1;i<=n;i++)
			if(dist[i] > dist[v] + cost[v][i])
				dist[i] = dist[v] + cost[v][i];
	}
}
