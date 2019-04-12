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

/*�����һ�е�ĳ��״̬DP(i-1,k) ���Դﵽ DP(i, j) ������Ϊ������״̬�Ǽ��ݵģ�
���DP(i-1,k)��DP(i, j)���ݲ��� DP(i-1, k)��S�����跽������ôDP(i, j)�Ϳ��Դ�DP(i-1, k)
����·���л��S�������� 
k��ȡֵ������ 0 ~~~~ 2^(M-1)-1��ȡֵ

ps:���㷨��ö�ٷ�ʽ�У��㵽DP(i,j)�Ǽ���Ե�i�У�ǰi-1�����Ѿ������ˣ������return false���������ˣ�
����ֻ����(i,j)�Լ�i��j����е������ ��������Ĺ�ϵ�������һ��i����1����i+1����Ϊ1�� ���ŵ�����11���ұ߱�������11�� 
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
			//ע�����ŵ�����11���ұ����ߣ���Ϊ11 
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

