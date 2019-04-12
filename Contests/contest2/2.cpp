#include <bits/stdc++.h>
using namespace std;

int main(){
	int first;
	int n;
	int i=1, path = 0, t = 1;
	scanf("%d",&n);
	while(n>>i) {	
		path += t; 
		t *= 2;
		i++;
	}
	path += pow(2,i-1);
	printf("%d\n",path);
	
	first = n^((1<<i)-1);
	printf("%d ",first);
	
	for(int j=0;j<n;j++){
		if(j!=(first))
			printf("%d ",j);
	}
	printf("%d\n",n);
	
	return 0;
}
