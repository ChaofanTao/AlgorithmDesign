#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1005;
int n, m, mask1, mask2;
int dp[maxn][1030];///dp[i][j]表示当前考虑第i行，j的前1~m位表示当前行的状态，后m+1~2*m位表示下一行的状态

int main()
{
    while(~scanf("%d%d",&n,&m)){
        mask1 = (1<<m)-1;
        mask2 = (1<<( m <<1))-1;
        memset(dp,0,sizeof(dp));
        dp[1][0]=1;
        for(int i=1; i<=n; i++){
            for(int k=0; k<m; k++){
                for(int j=0; j<=mask2; j++){
                    if((j&(1<<k))==0){
                        dp[i][j|(1<<k)|(1<<(k+m))]=(dp[i][j|(1<<k)|(1<<(k+m))]+dp[i][j])%mod;
                        if(k+1<m&&(j&(1<<(k+1)))==0){
                            dp[i][j|(1<<k)|(1<<(k+1))]=(dp[i][j|(1<<k)|(1<<(k+1))]+dp[i][j])%mod;
                        }
                    }
                }
            }
            for(int j=0; j<=mask2; j++){
                if((mask1&j)==mask1){
                    dp[i+1][j>>m]=dp[i][j];
                }
            }
        }
        printf("%d\n", dp[n][mask1]);
    }
    return 0;
}
