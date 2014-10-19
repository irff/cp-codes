#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int main (){
        int N,T,X,Y;
        scanf ( "%d", &N );
        scanf("%d", &T);
        char irfan[N][N];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                irfan[i][j]='.';
        while(T--){
            scanf("%d%d", &X,&Y);
            irfan[X-1][Y-1]='#';
        }
        char Land[N];
        int Sol = 0, DP[N][N];
        memset ( DP, 0, sizeof ( DP ) );
        for ( int i = 0; i < N; i++ ){
            for(int j=0; j < N; j++) Land[j]=irfan[i][j];
            for ( int j = 0; j < N; j++ ){
                if ( Land[j] == '#' ) continue;
                int A = 0, B = 0, C = 0;
                if ( j ) A = DP[i][j - 1];
                if ( i ) B = DP[i - 1][j];
                if ( ( i ) && ( j ) ) C = DP[i - 1][j - 1];
                DP[i][j] = min ( min ( A, B ), C ) + 1;
                Sol = max ( DP[i][j], Sol );
            }
        }
        printf ( "%d\n", Sol );
    return 0;
}
