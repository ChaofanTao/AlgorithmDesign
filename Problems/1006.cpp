#include<stdio.h>
#include<string.h> 

using namespace std;
//���� 
const int maxn = 1010;
int T,a[maxn],b[maxn],c[maxn];
int n,i,j,maxL,p;
//ע�ⲻ��Ҫ��������У�����Ҫ��С 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		a[i]=-1; 
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=1;//i��n������������� 
			c[i]=0;//i��������еĺ������ 
		}
		for(i=n-1;i>=0;i--){
			maxL=0;//��������󳤶� 
			p=0;
			for(j=i+1;j<=n;j++)
				if(a[i]<a[j] && b[j]>maxL){
					maxL=b[j];
					p=j;
				}
				else if(a[i]<a[j] && b[j]==maxL){
					if(a[p]>a[j]) p=j; //a[p],a[j]���������a[i]������������У���ʱ������С�������� 
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
		//��a[0]�����˱Ƚϣ�����ͳ�Ƴ��ȵ�ʱ���a[0]ȥ�� 
		printf("%d",maxL-1);
		p=c[p];
		while(p){
			printf(" %d",a[p]);//ע��ÿ������Ӧ��һ���ո�
			p=c[p];
		printf("\n");//����� ռһ��,���Ա��������� 
		} 
	}
	return 0; 
}
