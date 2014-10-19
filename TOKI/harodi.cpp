#include<stdio.h>
#include<string.h>
#define MAXD 110
#define MAXL 210
#define INF 1000000000
int L, N, f[MAXD][MAXL], d[MAXD], m[MAXD];
char b[100];
void init()
{
    gets(b);
    sscanf(b, "%d", &L);
    N = 0;
    d[0] = 0;
    while(gets(b) != NULL)
    {
        if(b[0] == '\0')
            break;
        ++ N;
        sscanf(b, "%d%d", &d[N], &m[N]);
        if(d[N] < 0 || d[N] > L)
            -- N;
    }
}
void solve()
{
    int i, j, k, temp, dis;
    for(i = 0; i <= N; i ++)
        for(j = 0; j <= 200; j ++)
            f[i][j] = INF;
 
    f[0][100] = 0;
    
    // dari toko 1 ke toko N
    for(i = 1; i <= N; i ++)
    {
        //jarak toko 1 ke toko N
        dis = d[i] - d[i - 1];
        
        //beli sebanyak j di toko ini
        for(j = 0; j + dis <= 200; j ++)
            //cari yang minimum, agar bisa ke sekarang
            if(f[i - 1][j + dis] < f[i][j])
                f[i][j] = f[i - 1][j + dis];
        
        temp = INF;
        for(j = 0; j <= 200; j ++)
        {
            if(f[i][j] - m[i] * j < temp)
                temp = f[i][j] - m[i] * j;
            if(temp + m[i] * j < f[i][j])
                f[i][j] = temp + m[i] * j;
        }
    }
    if(L - d[N] > 100 || f[N][100 + L - d[N]] == INF)
        printf("Impossible\n");
    else
        printf("%d\n", f[N][100 + L - d[N]]);
}
int main()
{
    int t;
    gets(b);
    sscanf(b, "%d", &t);
    gets(b);
    while(t --)
    {
        init();
        solve();
        if(t)
            printf("\n");
    }
    return 0;
}
