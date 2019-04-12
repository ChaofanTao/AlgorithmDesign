#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9+9;
/*��n���ƣ� ����4�Ų�ͬ = ����4^n - ������res. res = dp1[n]+dp2[n]+dp3[n]+dp4[n]+dp5[n]
[dp1[n],dp2[n],dp3[n],dp4[n],dp5[n]] = [dp1[3],dp2[3],dp3[3],dp4[3],dp5[3]] * A^(n-3) 
ת�ƾ��� A ��������� 
4^n ,A^(n-3)�ֱ��õ�������������Ҫ���ط���*���Ŀ������㷨
ע�� 4^n�ܴ�����mod����ģ����  
*/ 
// ctrl+"+"+"/"������ע�ͺ�ȡ��ע�� 
LL powmod(LL a, LL n)//�������Ŀ�����  
{
    LL res=1;
    while(n){
        if(n&1) res=((res%mod)*(a%mod))%mod;//ע��ÿ�γ˷���ȡģ 
        a=((a%mod)*(a%mod))%mod;
        n>>=1;
    }
    return res;
}
struct Matrix{
    LL a[5][5];
    void init(){
        memset(a,0,sizeof(a));//��ʼ���������ڴ� 
    }
    void init2(){
        memset(a,0,sizeof(a));
        for(int i=0; i<5; i++) a[i][i]=1;
    }
};
Matrix operator * (Matrix a, Matrix b){//����* 
    Matrix res;
    res.init();
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0;k<5; k++){
                res.a[i][j]=(res.a[i][j]+(a.a[i][k]*b.a[k][j])%mod)%mod;//ע��ÿ�μӷ���ȡģ 
            }
        }
    }
    return res;
}
Matrix ksm(Matrix a, LL n){//������*, ����*��ʾ����˷� 
    Matrix res;
    res.init2();
    while(n){
        if(n&1) res=res*a;//����Ŀ������㷨 
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
    B.a[0][0]=4;B.a[0][1]=12;B.a[0][2]=12;B.a[0][3]=12;B.a[0][4]=24;//��B�ĵ�һ��ָ����dp����������������Ϊ0 
    Matrix ans=ksm(A,n-3);//ans=A^(n-3) 
//    for(int i=0; i<5; i++){
//        for(int j=0; j<5; j++){
//            printf("%d ",ans.a[i][j]);
//        }
//        printf("\n");
//    }
    ans=B*ans;//������յ�dp 
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

