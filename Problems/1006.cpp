#include<stdio.h>
#include<string.h> 

using namespace std;
//逆推 
const int maxn = 1010;
int T,a[maxn],b[maxn],c[maxn];
int n,i,j,maxL,p;
//注意不仅要求最长升子列，还需要最小 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		a[i]=-1; 
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=1;//i到n的最长的上升子列 
			c[i]=0;//i的最长升子列的后继坐标 
		}
		for(i=n-1;i>=0;i--){
			maxL=0;//子序列最大长度 
			p=0;
			for(j=i+1;j<=n;j++)
				if(a[i]<a[j] && b[j]>maxL){
					maxL=b[j];
					p=j;
				}
				else if(a[i]<a[j] && b[j]==maxL){
					if(a[p]>a[j]) p=j; //a[p],a[j]都满足跟在a[i]后是最长的升序列，此时保留最小的子序列 
				}
				if(p){
					b[i]=b[p]+1;
					c[i]=p;
				} 
		}
		maxL=p=0;
		for(i=0;i<=n;i++){
			if(b[i]>maxL){
				maxL=b[i];
				p=i;
			}
		}
		//把a[0]加入了比较，所以统计长度的时候把a[0]去掉 
		printf("%d",maxL-1);
		p=c[p];
		while(p){
			printf(" %d",a[p]);//注意每个数后应有一个空格
			p=c[p];
		printf("\n");//题干有 占一行,所以必须有这行 
		} 
	}
	return 0; 
}
