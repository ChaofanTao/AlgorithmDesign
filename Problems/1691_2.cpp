#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int n,V,w[maxn],p[maxn],c[maxn],dp[110][maxn];
 
int main()
{
    scanf("%d %d", &n,&V);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d", &w[i],&p[i],&c[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int k=0; k<=c[i]; k++){
            for(int j=V; j>=0; j--){
                if((j-k*w[i])>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*p[i]);
                    //dp[j]=max(dp[j],dp[j-k*w[i]]+k*p[i]);��һά�����еĴ𰸲�ͨ������֪��ԭ�� 
                }
                else break;
            }
        }
    }
    printf("%d\n",dp[n][V]);
    return 0;
}

