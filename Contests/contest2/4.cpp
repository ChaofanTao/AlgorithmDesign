#include <bits/stdc++.h>
using namespace std;

float n,L,v;

int main(){
	scanf("%f%f%f",&n,&L,&v);
	float a,h;
	float t[100010];
	int i=0;
	int times = n;
	while(times--){
		scanf("%f%f",&h,&a);
		t[i]=(L-h)/(v+a);
		i++;
	}
		
	float max=0.0,min=1000000000000.0;
	for(int i=0;i<n;i++){
		if(t[i]<min)
			min = t[i];
		if(t[i]>max)
			max = t[i];
	}
	printf("%.2f %.2f\n",min,max);
	
	return 0;
	
}
