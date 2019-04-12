#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n,m,a[maxn][maxn], dp[maxn][maxn];
bool check(int x, int y){
    if(x>=1&&x<=n&&y>=1&&y<=m) return 1;
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);//��ͼ�ĵ�1��2ά 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);//a�ǵ�ͼ�����ֱ�ʾ��ң������ɸ���
			 
    //dp�����ŵ��Ǵӣ�1,1������ǰ�����������Ѽ��Ľ�ҵ��ܺ� 
    memset(dp,-1,sizeof(dp));//��ʼ��Ϊ-1����Ϊ��dpֵΪ0ʱ�������Լ��������ߡ�-1���ʾ���ܼ����ߵ�����  
    dp[1][1]=a[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1&&j==1) continue;
            int mx = -100000000;
            if(check(i-1,j)) mx=max(mx,dp[i-1][j]);
            if(check(i,j-1)) mx=max(mx,dp[i][j-1]);
            if(check(i-1,j-2)) mx=max(mx,dp[i-1][j-2]);
            if(check(i-2,j-1)) mx=max(mx,dp[i-2][j-1]);
            if(mx>=0){
                dp[i][j]=mx+a[i][j];
            }
            else{
                dp[i][j]=-1;
            }
        }
    }
    int ans=-1000000;
    for(int i=1; i<=n; i++)//��dp�������Ԫ�� 
        for(int j=1; j<=m; j++)
            ans=max(ans,dp[i][j]);
    printf("%d\n", ans);
    return 0;
}

