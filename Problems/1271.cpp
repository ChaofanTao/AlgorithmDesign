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
    scanf("%d%d",&n,&m);//地图的第1，2维 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);//a是地图，数字表示金币（可正可负）
			 
    //dp数组存放的是从（1,1）到当前所在坐标所搜集的金币的总和 
    memset(dp,-1,sizeof(dp));//初始化为-1，因为当dp值为0时，还可以继续往下走。-1则表示不能继续走的死点  
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
    for(int i=1; i<=n; i++)//找dp数组最大元素 
        for(int j=1; j<=m; j++)
            ans=max(ans,dp[i][j]);
    printf("%d\n", ans);
    return 0;
}

