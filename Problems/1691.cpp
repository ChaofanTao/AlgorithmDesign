#include <bits/stdc++.h>
using namespace std;

int c[210],w[50010],p[50010];
int f[50010];

//没通过，没找到原因，和1691_#.cpp很像 
int main()
{
	int N,W;
	int i,j,k;
	scanf("%d %d",&N,&W);
	for(i=1;i<=N;i++){
		scanf("%d %d %d", &w[i],&p[i],&c[i]);
	}
	memset(f,0,sizeof(f));
	
	k=N+1;
	for(i=1;i<=N;i++){
		while(c[i]!=1){
			w[k]=w[i];
			p[k]=p[i];
			k++;
			c[i]--;
		}	
	} 
	
	for(i=1;1<=k;i++){//注意这里物品总数是k不是N 
		for(j=W;j>=w[i];j--){ 
			f[j] = max(f[j], f[j-w[i]]+p[i]);
		} 
	} 
	printf("%d\n",f[W]);
	return 0;
}

