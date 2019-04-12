#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9+9;
/*共n张牌， 连续4张不同 = 总数4^n - 反例数res. res = dp1[n]+dp2[n]+dp3[n]+dp4[n]+dp5[n]
[dp1[n],dp2[n],dp3[n],dp4[n],dp5[n]] = [dp1[3],dp2[3],dp3[3],dp4[3],dp5[3]] * A^(n-3) 
转移矩阵 A 由题意算出 
4^n ,A^(n-3)分别用到了数，矩阵（需要重载符号*）的快速幂算法
注意 4^n很大，设置mod进行模运算  
*/ 
// ctrl+"+"+"/"来批量注释和取消注释 
LL powmod(LL a, LL n)//计算数的快速幂  
{
    LL res=1;
    while(n){
        if(n&1) res=((res%mod)*(a%mod))%mod;//注意每次乘法都取模 
        a=((a%mod)*(a%mod))%mod;
        n>>=1;
    }
    return res;
}
struct Matrix{
    LL a[5][5];
    void init(){
        memset(a,0,sizeof(a));//初始化，分配内存 
    }
    void init2(){
        memset(a,0,sizeof(a));
        for(int i=0; i<5; i++) a[i][i]=1;
    }
};
Matrix operator * (Matrix a, Matrix b){//重载* 
    Matrix res;
    res.init();
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0;k<5; k++){
                res.a[i][j]=(res.a[i][j]+(a.a[i][k]*b.a[k][j])%mod)%mod;//注意每次加法都取模 
            }
        }
    }
    return res;
}
Matrix ksm(Matrix a, LL n){//重载了*, 这里*表示矩阵乘法 
    Matrix res;
    res.init2();
    while(n){
        if(n&1) res=res*a;//矩阵的快速幂算法 
        a=a*a;
        n>>=1;
    }
    return res;
}
int main()
{
    LL n;
    scanf("%lld",&n);
    Matrix A,B;
    A.init();
    B.init();
    A.a[0][0]=1,A.a[0][1]=3,A.a[1][2]=1,A.a[1][3]=1,A.a[1][4]=2;
    A.a[2][2]=1;A.a[2][3]=1;A.a[2][4]=2;
    A.a[3][0]=1;A.a[3][1]=3;
    A.a[4][2]=1;A.a[4][3]=1;A.a[4][4]=1;
    B.a[0][0]=4;B.a[0][1]=12;B.a[0][2]=12;B.a[0][3]=12;B.a[0][4]=24;//用B的第一行指的是dp行向量，其余行设为0 
    Matrix ans=ksm(A,n-3);//ans=A^(n-3) 
//    for(int i=0; i<5; i++){
//        for(int j=0; j<5; j++){
//            printf("%d ",ans.a[i][j]);
//        }
//        printf("\n");
//    }
    ans=B*ans;//算出最终的dp 
//    for(int i=0; i<5; i++){
//        for(int j=0; j<5; j++){
//            printf("%d ",ans.a[i][j]);
//        }
//        printf("\n");
//    }
    LL ret = 0;
    for(int i=0; i<5; i++){
        ret=(ret+ans.a[0][i])%mod;       
    }
    ret = (powmod(4,n)-ret+mod)%mod;
    if(ret<0) ret+=mod;
    //ret = powmod(4,n)-ret;
    printf("%lld\n", ret);
    return 0;
}

