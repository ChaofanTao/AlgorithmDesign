#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000010;
int T;
long long int n, m, L, R, a, b, c, d;


int main() {
	scanf("%d",&T);
	while(T--!=0) {
		scanf("%d%d%d%d%d%d%d%d",&n,&m,&L,&R,&a,&b,&c,&d);
		int step = 0;
		if(abs(a-c)!=0) {
			if(L<b&&b<R && L<d&&d<R)
				step = abs(a-c) + min(b+d-L-L, R+R-b-d);
			else
				step = abs(a-c) + abs(b-d);

			printf("%d\n",step);
		} 
		else {
			step = abs(b-d);
			printf("%d\n",step);
		}
	}
	return 0;
}

