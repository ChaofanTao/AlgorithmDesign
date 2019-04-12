#include<stdio.h>
#include<string.h> 
#include<algorithm>
using namespace std;
int map[1010][1010],dp[1010][1010],n,m,b[4]={1,0,1,2},d[4]={0,1,2,1};
int main()
//24 7644 复杂度0(n*m)  
{
	int i,j,tx,ty,k,ans;
	scanf("%d%d",&n,&m);	
	ans=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	  scanf("%d",&map[i][j]);
		if(map[1][1]<0)//当起点为负时，直接输出0,退出游戏 
		;
		else
		{
			memset(dp,-1,sizeof(dp));//初始化为-1，因为当dp值为0时，还可以继续往下走。-1则表示不能继续走的死点 
			dp[1][1]=ans=map[1][1];
			for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(dp[i][j]>=0)//选择金币总和不小于0的坐标，,继续往下走 
				{
					for(k=0;k<4;k++)
					{	
						tx=i+b[k];
						ty=j+d[k];
						if(tx>n||ty>m) continue ;
					//if(map[tx][ty]>=0)不能加该条判断，虽然当前坐标自身金币为负，
					//但从（1,1）到当前坐标金币总和却不一定小于0，因此还有可能继续往下走 
							dp[tx][ty]=max(dp[tx][ty],dp[i][j]+map[tx][ty]);//更新起点到当前点的坐标的金币总和 ,死点得到-1 
							ans=max(ans,dp[tx][ty]);//更新最大值 
					}
				}
			}
		}
	printf("%d\n",ans);	
	return 0;
}

