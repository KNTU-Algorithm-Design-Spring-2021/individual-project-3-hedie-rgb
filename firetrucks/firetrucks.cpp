#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k, n, m, ans, maxn;
bool Map[50][50];
bool vis[50];
int e[30];
bool isSafe(int x, int y)
{
    return (x>0 && y>0 && x<= maxn && y <= maxn && Map[x][y]);
}
void find(int x, int d)
{
    if(x == k)
    {
        printf("1");
        for(int i = 1; i < d - 1; i++)
        {
            printf(" %d",e[i]);
        }
        printf(" %d\n",k);
        ans++;
        return;
    }
    for(int i = 1; i <= maxn; i++)
    {
        if(i == x)continue;
        if(!vis[i] && isSafe(x, i))
        {
            e[d] = i;
            vis[i] = 1;
            find(i, d + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    int cases = 0;
    while(scanf("%d",&k) != EOF)
    {
        int a, b;
        maxn = 0;
        memset(Map, 0, sizeof(Map));
        memset(vis, 0, sizeof(vis));
        while(scanf("%d%d", &a, &b) && (a || b))
        {
            Map[a][b] = Map[b][a] = 1;
            maxn = max(maxn, max(a, b));
        }
        ans = 0;
        vis[1] = 1;
        printf("CASE %d:\n",++cases);
        find(1, 1);
        printf("There are %d routes from the firestation to streetcorner %d.\n", ans, k);
    }
    return 0;
}
