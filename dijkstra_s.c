#include<stdio.h>
#include<limits.h>
#include<ctype.h>
int n,graph[50][50],dist[50],visit[50]={0},seq[50];
int min(int dist[],int visit[]){
int i,index,min=INT_MAX;
for(i=0;i<n;i++){
if( visit[i]==0 && dist[i] <=min){
min=dist[i];
index=i;
}}return index;
}
void dijkstra(int graph[50][50],int st){
int i,u,v;
for(i=0;i<n;i++)
dist[i]=INT_MAX;
dist[st]=0;
for(i=0;i<n;i++){
u=min(dist,visit);
visit[u]=1;
for(v=0;v<n;v++){
if(!visit[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
seq[v]=u;
dist[v]=dist[u]+graph[u][v];
}}}
}
int main(){
int i,j,vertex,k,t,s_no=1;
char vtx,path[50];;
printf("Enter the number of vertex :");
scanf("%d",&n);
printf("Enter the cost matrix(%d x %d)\n",n,n);
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&graph[i][j]);
}}
fflush(stdin);
printf("Enter the source vertex (A-%c) :",n-1+'A');
scanf("%c",&vtx);
vertex=toupper(vtx)-'A';
dijkstra(graph,vertex);
printf("-----------------<- SHORTEST PATH ->-------------------");
for(i=0;i<n;i++){
if(i==vertex)
continue;
printf("\n%d. \t%c -> %c \t cost= %d\n",s_no++,vertex+'A',i+'A',dist[i]);
k=0;
j=seq[i];
path[k++]=(char)i+'A';
while(j!=vertex){
path[k++]=(char)j+'A';
j=seq[j];
}
printf("\tpath : %c",vertex+'A');
for(t=k-1;t>=0;t--)
printf("-> %c",path[t]);
printf("\n--------------------------------------------------------\n");
}}
