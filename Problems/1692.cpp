#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
typedef long long LL;
int n, m, b, a[maxn];
LL dp[maxn][maxn], mod;//由于方案数可能很多，所以数组dp的元素也是 longlong型 
//背包问题的求总方案问题
 
//dp[i][j][k]表示前i个队员，写了j行代码，存在k个bug的方案数。队员bug-物体重量； 写的行数-物体个数； 总bug-总载重 
//类似无穷背包问题。 因为每个队员可以写的行数j不是定值（j<总行数就可以）
int main()
{
    scanf("%d %d %d %lld", &n,&m,&b,&mod);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    dp[0][0]=1;
    for(int i=1; i<=n; i++){//n个队员 
        for(int j=1; j<=m; j++){//要写m行代码 
            for(int k=0; k<=b; k++){// bug上限（总载重） 
                if(k-a[i]>=0){
                	//dp[i][j][k]=(dp[i-1][j][k]+dp[i][j-1][k-a[i]])%mod; 
                	//方案数：  i人j行k错= i-1人j行k错 + 加入第i人后新增方案 （i人j-1行k-a[i]错，这时方案中必有第i人参于）
					//这里的递推类似无穷背包，所以考虑了一人可以写多行的情况 。且总行数(0~b)要用顺序循环来省略i这一维度 
                    dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
                }
            }
        }
    }
    LL ans=0;
    for(int k=0; k<=b; k++) //因为b是上限，小于等于b的方案都满足 
		ans=(ans+dp[m][k])%mod;
    printf("%lld\n", ans);
    return 0;
}
