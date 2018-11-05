#include <cstdio>

using namespace std;

int n,m,i,j;
bool a[10][3010];
int dx[]= {-1,-1,0,1,1,1,0,-1,-1};
int dy[]= {-1,0,-1,-1,0,1,1,1,0};

bool good(int i, int j)
{
    for (int k=0; k<8; k+=2)
    {
        bool allones=1;
        for (int K=k; K<=k+2; K++)
            if (a[i+dx[K]][j+dy[K]]==0)
                allones=0;
        if (allones)
            return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            char c;
            scanf("%d",&a[3][j]);
            //a[3][j]=c-'0';
        }
        for (j=1; j<=m; j++)
            if (a[2][j]==0)
            {
                if (!good(2,j))
                {
                    printf("No\n");
                    return 0;
                }
            }
        for (j=1; j<=m; j++)
            a[1][j]=a[2][j],a[2][j]=a[3][j];
    }
    for (i=1; i<=m; i++)
        a[3][i]=0;
    for (i=1; i<=m; i++)
        if (a[2][i]==0&&!good(2,i))
        {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
}
