#include<bits/stdc++.h>
using namespace std;
char s[1010];
int a[1010];
int main() {
	scanf("%s",&s);
	int nl = strlen(s);
	for(int i = 0; i < nl; i++)
		a[i] = s[i] - '0';
	sort(a,a + nl);
	for(int i = 0; i < nl; i++)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}
