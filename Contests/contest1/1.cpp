#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	if(n==1)
		printf("Wed.Strong\n");
	else {
		for(int i=0; i<n/2; i++) {
			printf("Wed.Strong");
		}
		printf("\n");
	}

	return 0;

}
