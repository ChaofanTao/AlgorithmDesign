#include <bits/stdc++.h>
using namespace std;
/*
保护果实
只要最长的那条边的长度大于其它的边，那么就可以围成一个多边形，
求当前的i条边中最长的那条边长度和其它边的长度和就好了
*/
int a[1000005];
int main() {
	int n;
	scanf("%d",&n);
	if(n<3){
		puts("-1");
		return 0;
	}
	bool flag = false;
	int k;
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	int sum = 0;
	int max = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > max)
			max = a[i];
		sum += a[i];
		if(sum-max>max) {
			flag = true;
			k = i;
			break;
		}
	}
	if(flag) printf("%d\n",k+1);
	else puts("-1");
	return 0;
}
