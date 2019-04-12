#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1000010],M[110];

int main() {
	int num=0;

	memset(M,0,sizeof(M));
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++ ) {
		scanf("%d",&a[i]);
		M[a[i]%m] += 1;//M[0]记录a中模m余0的个数
	}

	if(M[0]!=0)
		num += M[0]-1;
	for(int j=1; j<=m/2; j++) {
		if(M[j]==M[m-j] && j!=(m-j) && M[j]!=0 )
			num += 2*M[j]-1;
		else if(M[j]==M[m-j] && j==(m-j)) {
			if(M[j]!=0)
				{num += M[j]-1;}
		}
		else
			num += 2*min(M[j],M[m-j]);
	}
	printf("%d\n",num);

	return 0;
}
