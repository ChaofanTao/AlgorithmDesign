#include <stdio.h>
//这个算法的时间复杂度是O(N2)。其中每次找到离1号顶点最近的顶点的时间复杂度是O(N)，
//这里我们可以用“堆”（以后再说）来优化，使得这一部分的时间复杂度降低到O(logN)。
int main()
{
    int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
    int inf=99999999; //用inf(infinity的缩写)存储一个我们认为的正无穷值
    //读入n和m，n表示顶点个数，m表示边的条数
    scanf("%d %d",&n,&m);
                                                                  
    //初始化，从1计数 
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) e[i][j]=0;//对角元设0，只是起点-起点距离为0，对起点-其他点的最小距离无影响 
              else e[i][j]=inf;
                                                                            
    //读入边
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }
    //初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
    for(i=1;i<=n;i++)
        dis[i]=e[1][i];
    //book数组初始化
    for(i=1;i<=n;i++)
        book[i]=0;
    book[1]=1;//book=1表示起点（下标1）进入“确定点”集合S 
                                                                  
    //Dijkstra算法核心语句
    for(i=1;i<=n-1;i++)
    {
        //通过dis[], 找到离顶点最近的顶点,把该点加入“确定集” 
        min=inf;
        for(j=1;j<=n;j++)
        {
            if(book[j]==0 && dis[j]<min)//从“非确定集”中选到起点最小距离的点 
            {
                min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        //printf("add v%d to S, the shortest distance v-vstart is %d\n", u,dis[u]);
		 
        //遍历 所有 点，利用新加入确定集的点来“松弛”数组dis 
        for(v=1;v<=n;v++)
        {
            if(e[u][v]<inf && dis[v]>dis[u]+e[u][v])
                dis[v]=dis[u]+e[u][v];
        }
    }
                                                                  
    //输出最终的结果
    for(i=1;i<=n;i++)
        printf("%d ",dis[i]);
        
    return 0;
}
