#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
using namespace std;
  
#define MAX_ROW 1005
#define MAX_STATUS 32
long long DP[MAX_ROW][MAX_STATUS];
const int mod = 1e9+7;
long long int g_Width, g_Height;

/*如果上一行的某个状态DP(i-1,k) 可以达到 DP(i, j) 我们认为这两个状态是兼容的，
如果DP(i-1,k)和DP(i, j)兼容并且 DP(i-1, k)有S中铺设方案，那么DP(i, j)就可以从DP(i-1, k)
这条路径中获得S个方案。 
k的取值可以是 0 ~~~~ 2^(M-1)-1种取值

ps:本算法的枚举方式中，算到DP(i,j)是假设对第i行，前i-1个都已经兼容了（否则就return false弹出函数了）
所以只考虑(i,j)以及i行j后的列的情况。 才有下面的关系，比如第一行i处是1，则i+1处必为1； 竖着的两个11的右边必是两个11； 
*/ 
bool TestFirstLine(int nStatus)  //test the first line
{	int i = 0; 
	while( i < g_Width)
	{   if(nStatus & (1 << i))
		{   if( i == g_Width -1 || (nStatus & (1 << (i+1))) == 0)
				return false;
			i += 2;
		}
		else i++;
	}
	return true;
}
 
bool CompatablityTest(int nStatusA, int nStatusB) // test if status (i, nStatusA) and (i-1, nStatusB) is compatable.
{	int i = 0;
	while( i < g_Width)
	{	if( (nStatusA & (1 << i))  == 0)
		{	if((nStatusB & (1 << i)) == 0)
				return false;
			i++;
		}
		else
			{if((nStatusB & (1 << i)) == 0 )
				i++;
			//注意竖着的两个11的右边两边，必为11 
			else if( (i == g_Width - 1) || ! ( (nStatusA & (1 << (i+1))) && (nStatusB & (1 << (i+1)))) )
				return false;
			else
				i += 2;
			}
	}
	return true;
}
int main()
{	int i,j;
	int k;
	while(scanf("%lld%lld", &g_Height, &g_Width) != EOF )
	{	if(g_Width == 0 && g_Height == 0)
			{break;} 
		if(g_Width > g_Height)
			{swap(g_Width, g_Height);}
 
		int nAllStatus = 1 << g_Width;
		memset(DP, 0, sizeof(DP));
		for( j = 0; j < nAllStatus; j++)
		{if(TestFirstLine(j))
			{DP[0][j] = 1;}
		}
 
		for( i = 1; i < g_Height; i++)
		{    for( j = 0; j < nAllStatus; j++)// iterate all status for line i
			{	for( k = 0; k < nAllStatus; k++) // iterate all status for line i-1
				{if(CompatablityTest(j, k))
					{DP[i][j] = (DP[i][j]+DP[i-1][k])%mod;}
				}
			}
		}
		printf("%lld\n", DP[g_Height-1][nAllStatus-1]);
	}
	return 0;
}

