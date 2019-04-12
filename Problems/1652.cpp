#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;
int m, k, n, p, a, b, kk[maxn];//m车道，n公里，k个障碍 ，p初始车道（从左数） 
double dp[2][maxn];//记录当前、下一步所有车道安全的概率  
bool pos[1010][maxn];//距离，车道数 。记录障碍的位置 
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
        if(!flag){//flag=0即有障碍，1个车道，必撞车 
            puts("0.000000");
        }
        else{
            puts("1.000000");
        }
        return 0;
    }
    
    dp[now][p]=1;//车道从1开始计数 ，代入初值 
    for(int i=1; i<=n; i++){//n公里，换道n次 
    //顺推法。
	//1道第i-1公里无障碍的时候，影响1，2道的i-1~i公里的安全概率  
	//m道第i-1公里无障碍的时候，影响m-1，m道的i-1~i公里的安全概率 
	//j道(2<=j<=m-1) 的第i-1公里无障碍的时候， 影响j-1,j,j+1道 i-1~i公里的安全概率 
        swap(now, pre);
        memset(dp[now],0,sizeof(dp[now]));//每过1公里，pre被new赋值，new被清零.dp[new]是个行向量 
        for(int k=1; k<=2; k++){
            if(!pos[i-1][1]){//如果第1道i-1公里没障碍 
                dp[now][k]+=dp[pre][1]/2.0; 
            }//如果有障碍，dp[now][k]这就还是0 
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

