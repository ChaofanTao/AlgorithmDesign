#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, ans, a[maxn][maxn], dp[4][maxn][maxn];
//ֱ��Ԥ��������ĸ��ǵ�ÿ��������øжȣ�Ȼ��ö�����ĸ������������´𰸼��ɡ� 
//ע����2����� 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
        	//��[i-1,j]��[i,j-1]�����������һ����[i,j] 
            dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j]+a[i][j]);
            dp[0][i][j]=max(dp[0][i][j],dp[0][i][j-1]+a[i][j]);
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=1; j<=m; j++){
            dp[1][i][j]=max(dp[1][i][j],dp[1][i+1][j]+a[i][j]);
            dp[1][i][j]=max(dp[1][i][j],dp[1][i][j-1]+a[i][j]);
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=m; j>=1; j--){
            dp[2][i][j]=max(dp[2][i][j], dp[2][i+1][j]+a[i][j]);
            dp[2][i][j]=max(dp[2][i][j], dp[2][i][j+1]+a[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            dp[3][i][j]=max(dp[3][i][j],dp[3][i-1][j]+a[i][j]);
            dp[3][i][j]=max(dp[3][i][j],dp[3][i][j+1]+a[i][j]);
        }
    }
    for(int i=2; i<n; i++){//����������λ���Ǵ�(2,2)��(n-1,m-1)�ľ������� 
        for(int j=2; j<m; j++){
            ans = max(ans, dp[0][i-1][j]+dp[2][i+1][j]+dp[1][i][j-1]+dp[3][i][j+1]);
            ans = max(ans, dp[0][i][j-1]+dp[2][i][j+1]+dp[1][i+1][j]+dp[3][i-1][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
