#include <bits/stdc++.h>
using namespace std;

//״̬ѹ��+���仯���� 
int n, dp[1<<21], p[22][22][22];
int dfs(int s){
    if(dp[s]!=-1) return dp[s];
    int i,j,k;
    for(i=0; i<n-2; i++){
        if(s&(1<<i))//�����i(��0����)����û��ѡ 
         	break;
	}
	    for(j=i+1;j<n-1;j++){ 
	        if(s&(1<<j))
	        for(k=j+1;k<n;k++)
	            if(s&(1<<k))//�������� n�����У�3��û��ѡ����i,j,k ����� 
	            //(1<<i)^(1<<j)^(1<<k) 0001001010, i,j,k������ͬ���ٺ�sȡ���
				//s��ûѡ��1���ı���ûѡ״̬����Ϊi,j,kλûѡ����ѡ�У�1��Ϊ0�� 
				//���õݹ�dfs, ö�ٳ�s=1<<n-1ʱ�����Ž⡣ 
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
            p[a-1][b-1][c-1]=d;//��¼�����0��ʼ���� 
        }
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        int ans = dfs((1<<n)-1);//(1<<n)-1��Ӧ�Ķ�������n��1 
        printf("%d\n", ans);
    }
    return 0;
}

