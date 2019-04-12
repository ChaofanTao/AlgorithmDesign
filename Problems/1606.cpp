#include <bits/stdc++.h>
using namespace std;
//n个（2种）饮料，阈值k 
//时间复杂度 O(n*k),空间复杂度 O(k)
const int maxn = 40010;
int n, k;
int dp[maxn], t[maxn], a[maxn], b[maxn];
int main()
{
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d", &t[i],&a[i],&b[i]);
    }
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        if(t[i]==1){//喝水，完全背包 
            for(int j=0; j<=k; j++){
                if(j-b[i]>=0){
                    dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
                }
            }
        }
        else{//饮料，01背包 
            for(int j=k; j>=0; j--){
                if(j-b[i]>=0){
                    dp[j]=max(dp[j], dp[j-b[i]]+a[i]);
                }
            }
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}
