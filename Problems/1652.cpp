#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;
int m, k, n, p, a, b, kk[maxn];//m������n���k���ϰ� ��p��ʼ�������������� 
double dp[2][maxn];//��¼��ǰ����һ�����г�����ȫ�ĸ���  
bool pos[1010][maxn];//���룬������ ����¼�ϰ���λ�� 
int now=0,pre=1;
int main()
{
    scanf("%d %d %d", &m,&k,&n);
    scanf("%d", &p);
    bool flag = 1;
    for(int i=1; i<=k; i++){
        scanf("%d %d", &a,&b);
        if(b<=n){ 
//            int pos=(b-1)*m+a;
//            kk[i]=pos;
            pos[b][a] = 1;
            flag = 0;
        }
    }
    if(m == 1){
        if(!flag){//flag=0�����ϰ���1����������ײ�� 
            puts("0.000000");
        }
        else{
            puts("1.000000");
        }
        return 0;
    }
    
    dp[now][p]=1;//������1��ʼ���� �������ֵ 
    for(int i=1; i<=n; i++){//n�������n�� 
    //˳�Ʒ���
	//1����i-1�������ϰ���ʱ��Ӱ��1��2����i-1~i����İ�ȫ����  
	//m����i-1�������ϰ���ʱ��Ӱ��m-1��m����i-1~i����İ�ȫ���� 
	//j��(2<=j<=m-1) �ĵ�i-1�������ϰ���ʱ�� Ӱ��j-1,j,j+1�� i-1~i����İ�ȫ���� 
        swap(now, pre);
        memset(dp[now],0,sizeof(dp[now]));//ÿ��1���pre��new��ֵ��new������.dp[new]�Ǹ������� 
        for(int k=1; k<=2; k++){
            if(!pos[i-1][1]){//�����1��i-1����û�ϰ� 
                dp[now][k]+=dp[pre][1]/2.0; 
            }//������ϰ���dp[now][k]��ͻ���0 
        }
        for(int k=m-1; k<=m; k++){
            if(!pos[i-1][m]){ 
                dp[now][k]+=dp[pre][m]/2.0;
            }
        }
        for(int j=2; j<=m-1; j++){
            for(int k=j-1; k<=j+1; k++){//k=1,2,3; 2,3,4; ...; m-2,m-1,m 
                if(!pos[i-1][j]){
                    dp[now][k]+=dp[pre][j]/3.0;
                }
            }
        }
    }
    double ans=0;
    for(int j=1; j<=m; j++){
        if(!pos[n][j]){
            ans+=dp[now][j];
        }
    }
    printf("%.6f\n", ans);
    return 0;
}

