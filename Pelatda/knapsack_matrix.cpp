#include <cstdio>
#include <algorithm>
using namespace std;

int n, duit, v[100],w[100];
int m[1000][1000];
int main() {
    scanf("%d%d", &n, &duit);
    for(int i=1; i<=n; i++) {
        m[i][0] = 0;
        scanf("%d%d", &w[i], &v[i]);
    }
    for(int i=0; i<=duit; i++) {
        m[0][i] = 0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=duit; j++) {
            if( w[i] <= j) {
                if( v[i] + m[i-1][j-w[i]] > m[i-1][j]) {
                  m[i][j] = v[i] + m[i-1][j-w[i]];
                } else m[i][j] = m[i-1][j];
            } else m[i][j] = m[i-1][j];
        }
    }
    for(int i=0; i<=n; i++) {
      for(int j=0; j<=duit; j++) printf("%d ", m[i][j]);
      printf("\n");
    }
    printf("%d\n", m[n][duit]);
    return 0;
}
