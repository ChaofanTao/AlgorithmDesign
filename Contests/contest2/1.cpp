#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main(){
int n,k;
int sum = 0;
scanf("%d%d",&n,&k);
for(int i=0; i<n;i++){
	scanf("%d",&a[i]);
	sum += a[i];
}
if(n*k>sum)
	printf("%d",n*k-sum);
else printf("%d",0);
return 0;
} 
