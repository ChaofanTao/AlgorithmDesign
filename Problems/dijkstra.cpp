#include <stdio.h>
//����㷨��ʱ�临�Ӷ���O(N2)������ÿ���ҵ���1�Ŷ�������Ķ����ʱ�临�Ӷ���O(N)��
//�������ǿ����á��ѡ����Ժ���˵�����Ż���ʹ����һ���ֵ�ʱ�临�ӶȽ��͵�O(logN)��
int main()
{
    int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
    int inf=99999999; //��inf(infinity����д)�洢һ��������Ϊ��������ֵ
    //����n��m��n��ʾ���������m��ʾ�ߵ�����
    scanf("%d %d",&n,&m);
                                                                  
    //��ʼ������1���� 
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) e[i][j]=0;//�Խ�Ԫ��0��ֻ�����-������Ϊ0�������-���������С������Ӱ�� 
              else e[i][j]=inf;
                                                                            
    //�����
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }
    //��ʼ��dis���飬������1�Ŷ��㵽�����������ĳ�ʼ·��
    for(i=1;i<=n;i++)
        dis[i]=e[1][i];
    //book�����ʼ��
    for(i=1;i<=n;i++)
        book[i]=0;
    book[1]=1;//book=1��ʾ��㣨�±�1�����롰ȷ���㡱����S 
                                                                  
    //Dijkstra�㷨�������
    for(i=1;i<=n-1;i++)
    {
        //ͨ��dis[], �ҵ��붥������Ķ���,�Ѹõ���롰ȷ������ 
        min=inf;
        for(j=1;j<=n;j++)
        {
            if(book[j]==0 && dis[j]<min)//�ӡ���ȷ��������ѡ�������С����ĵ� 
            {
                min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        //printf("add v%d to S, the shortest distance v-vstart is %d\n", u,dis[u]);
		 
        //���� ���� �㣬�����¼���ȷ�����ĵ������ɳڡ�����dis 
        for(v=1;v<=n;v++)
        {
            if(e[u][v]<inf && dis[v]>dis[u]+e[u][v])
                dis[v]=dis[u]+e[u][v];
        }
    }
                                                                  
    //������յĽ��
    for(i=1;i<=n;i++)
        printf("%d ",dis[i]);
        
    return 0;
}
