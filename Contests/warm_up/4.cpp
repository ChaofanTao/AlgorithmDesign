#include<bits/stdc++.h>
using namespace std;
#define N 1000
int arr[N];
char str[N][N];
int main()
{
    int n, k;
    int ans;
    char ch;
    bool flag = false;
    memset(arr,0,sizeof(arr));
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n; i++) {
        scanf("%s",str[i]);
    } 
    for(int i = 0;i < n; i++) { 
        if(flag) break;
        arr[5]++;
        int len = strlen(str[i]);
        for(int j = 0;j < len; j++) {
            arr[str[i][j]-'A']++;
            if(arr[5]>=50) {
                ans = i;  
                ch = 'F';
                flag = true;
                break;
            }
            if(arr[str[i][j]-'A']>=50) {
                ans = i;
                ch = str[i][j];
                flag = true;
                break;
            }   
        }
        if(i == k-1)    break;
    }

    if(flag) printf("%d %c\n",ans+1,ch);
    else if(k>n) puts("AMNZ");
    else puts("Feizhou Yin");
return 0;
}

