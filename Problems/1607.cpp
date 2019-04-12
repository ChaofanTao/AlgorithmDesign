#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, a[maxn][2];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n/2;i++){//第一维(轮次)从1计数 
            a[i][0]=i;
            a[i][1]=n+1-i;
        }
        int t;
        for(int i=1; i<n; i++){
            for(int j=1; j<=n/2; j++){
                if(j!=1) putchar(' ');//注意比赛和比赛之间要输出空格 
                printf("%d %d", a[j][0],a[j][1]);
            }
            putchar('\n');
            //固定a[1][0] ，其他的数顺时针（也可以逆时针）旋转 
            t = a[2][0];
            for(int j=2; j<n/2; j++){
                a[j][0]=a[j+1][0];
            }
            a[n/2][0]=a[n/2][1];
            for(int j=n/2; j>=2; j--){
                a[j][1]=a[j-1][1];
            }
            a[1][1]=t;
        }
    }
    return 0;
}

