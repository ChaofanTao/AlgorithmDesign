#include <bits/stdc++.h>
using namespace std;

//状态压缩+记忆化搜索 
int n, dp[1<<21], p[22][22][22];
int dfs(int s){
    if(dp[s]!=-1) return dp[s];
    int i,j,k;
    for(i=0; i<n-2; i++){
        if(s&(1<<i))//如果第i(从0计数)个人没被选 
         	break;
	}
	    for(j=i+1;j<n-1;j++){ 
	        if(s&(1<<j))
	        for(k=j+1;k<n;k++)
	            if(s&(1<<k))//遍历所有 n中人中，3个没被选的人i,j,k 的情况 
	            //(1<<i)^(1<<j)^(1<<k) 0001001010, i,j,k不会相同，再和s取异或，
				//s中没选（1）的保持没选状态。因为i,j,k位没选，则被选中（1变为0； 
				//利用递归dfs, 枚举出s=1<<n-1时的最优解。 
	                dp[s]=max(dp[s],dfs(s^(1<<i)^(1<<j)^(1<<k))+p[i][j][k]);
    	}
    return dp[s];
	
}	

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n*(n-1)*(n-2)/6; i++){
            int a,b,c,d;
            scanf("%d %d %d %d", &a,&b,&c,&d);
            p[a-1][b-1][c-1]=d;//记录矩阵从0开始计数 
        }
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        int ans = dfs((1<<n)-1);//(1<<n)-1对应的二进制是n个1 
        printf("%d\n", ans);
    }
    return 0;
}

