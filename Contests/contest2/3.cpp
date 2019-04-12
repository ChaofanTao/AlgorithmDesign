#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
int i;
int sum;
sum=1;
for(i=1;i<=n;i++)
{
sum=sum*i;
}
return sum;
}


int huajian(int a,int b)
{	
	int t;
	int orgina = a;
	int orginb = b; 
	while(b != 0){
		t = a%b;
		a = b;
		b = t;
	}
	return a;
	}

int T;
int main(){
	int l,t,m,i, gongyin;
	int a[110],b[110];
	int x,y;
	//int fenzi, fenmu;

	scanf("%d",&T);
	i = 0;
	
	while(T--){
		scanf("%d%d",&t,&m);
		m = abs(m);
		if(!((t+m)%2))
		{
		l = (t+m)/2;
		x = fact(t);
		y = fact(t-l)*fact(l)*pow(2,t);
		gongyin = huajian(x,y);
		a[i] = x/gongyin;
		b[i] = y/gongyin;		
		}
		else {
			a[i]=0;b[i]=0;
		}
		i++;
	}	
	for(int j=0;j<i;j++)
		{if(a[j]!=0)
			printf("%d/%d\n",a[j],b[j]);
		}
	return 0;
	
}
