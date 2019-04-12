#include <bits/stdc++.h>
using namespace std;

/*½¥±ä×Ö·û´®*/
int main() {
	int n,q=0,num[30]= {0};
	char  arr[1002];
	scanf("%d",&n);
	scanf("%s",arr);
	for (int i=0; i<n; i++) {
		int k;
		k=arr[i]-'a'+1;
		num[k]++;
	}
	while (n!=0) {
		int i=1;
		while (num[i]==0) i++;
		int m=i;
		while(num[m]!=0) {
			num[m]--;
			m++;
		}
		q++;
		n-=m-i;
	}
	printf("%d\n",q);
	return 0;
}
