#include<stdio.h>
#include<string.h> 
#include<algorithm>
using namespace std;
int map[1010][1010],dp[1010][1010],n,m,b[4]={1,0,1,2},d[4]={0,1,2,1};
int main()
//24 7644 ���Ӷ�0(n*m)  
{
	int i,j,tx,ty,k,ans;
	scanf("%d%d",&n,&m);	
	ans=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	  scanf("%d",&map[i][j]);
		if(map[1][1]<0)//�����Ϊ��ʱ��ֱ�����0,�˳���Ϸ 
		;
		else
		{
			memset(dp,-1,sizeof(dp));//��ʼ��Ϊ-1����Ϊ��dpֵΪ0ʱ�������Լ��������ߡ�-1���ʾ���ܼ����ߵ����� 
			dp[1][1]=ans=map[1][1];
			for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(dp[i][j]>=0)//ѡ�����ܺͲ�С��0�����꣬,���������� 
				{
					for(k=0;k<4;k++)
					{	
						tx=i+b[k];
						ty=j+d[k];
						if(tx>n||ty>m) continue ;
					//if(map[tx][ty]>=0)���ܼӸ����жϣ���Ȼ��ǰ����������Ϊ����
					//���ӣ�1,1������ǰ�������ܺ�ȴ��һ��С��0����˻��п��ܼ��������� 
							dp[tx][ty]=max(dp[tx][ty],dp[i][j]+map[tx][ty]);//������㵽��ǰ�������Ľ���ܺ� ,����õ�-1 
							ans=max(ans,dp[tx][ty]);//�������ֵ 
					}
				}
			}
		}
	printf("%d\n",ans);	
	return 0;
}

