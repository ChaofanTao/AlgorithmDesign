#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
typedef long long LL;
int n, m, b, a[maxn];
LL dp[maxn][maxn], mod;//���ڷ��������ܺܶ࣬��������dp��Ԫ��Ҳ�� longlong�� 
//������������ܷ�������
 
//dp[i][j][k]��ʾǰi����Ա��д��j�д��룬����k��bug�ķ���������Աbug-���������� д������-��������� ��bug-������ 
//������������⡣ ��Ϊÿ����Ա����д������j���Ƕ�ֵ��j<�������Ϳ��ԣ�
int main()
{
    scanf("%d %d %d %lld", &n,&m,&b,&mod);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    dp[0][0]=1;
    for(int i=1; i<=n; i++){//n����Ա 
        for(int j=1; j<=m; j++){//Ҫдm�д��� 
            for(int k=0; k<=b; k++){// bug���ޣ������أ� 
                if(k-a[i]>=0){
                	//dp[i][j][k]=(dp[i-1][j][k]+dp[i][j-1][k-a[i]])%mod; 
                	//��������  i��j��k��= i-1��j��k�� + �����i�˺��������� ��i��j-1��k-a[i]����ʱ�����б��е�i�˲��ڣ�
					//����ĵ�����������������Կ�����һ�˿���д���е���� ����������(0~b)Ҫ��˳��ѭ����ʡ��i��һά�� 
                    dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
                }
            }
        }
    }
    LL ans=0;
    for(int k=0; k<=b; k++) //��Ϊb�����ޣ�С�ڵ���b�ķ��������� 
		ans=(ans+dp[m][k])%mod;
    printf("%lld\n", ans);
    return 0;
}
