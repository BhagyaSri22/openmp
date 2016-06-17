/*
simple parallel bfs implentation using openmp
matrix input in the form of adjcency matrix
*/
#include <curses.h>
#include<stdio.h>
#include <omp.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v) {

#pragma opm for
{//parallel reg
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++]);
				}
}//parallel reg

}
main() {
	int v,count_vis=0;
double s,e;
	//clrscr();
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	visited[v]=1;
s= omp_get_wtime();
	bfs(v);
e= omp_get_wtime()-s;
printf("time to do - %lf\n",e);
	//printf("\n The node which are reachable are:\n");
	for (i=1;i<=n;i++)
	  if(visited[i])count_vis++;
	   //printf("%d\t",i); else 
	   if(count_vis!=n)printf("\n Bfs is not possible");
	else printf("Bfs done all nodes bisited\n");
	//getch();
}
