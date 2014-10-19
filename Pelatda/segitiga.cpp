#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
#define RV(i,_a,_b) for(int i=int(_a); i>=int(_b); i--)

const int INF = 2000111222;
int n, num, a[200000], m[400][400];
int kasus;

int main() {
    memset(m,-1,sizeof m);
    scanf("Kasus #%d", &kasus);
    scanf("%d", &n);
    
    num = n*(n+1)/2;
    R(i,0,num) scanf("%d", &a[i]);
    
    sort(a, a+num);
    int now = num-1;
    RV(i,n-1,2) {
        m[i][i] = a[now--];
    }
    m[0][0] = a[now--];
    int na=0, selmin = INF;
    
    RV(i,now-1,0) if(a[i+1]-a[i] < selmin) selmin = a[i+1]-a[i],na=i;
    
    m[1][0] = a[na+1];
    m[1][1] = a[na];
    a[na]=-1, a[na+1]=-1;
    
    now = 0;
    RV(i,n-1,2) {
        while(a[now]==-1) now++;
        m[i][1] = a[now++];
        m[i][0] = a[now++];
    }
    
    R(i,0,n) {
        R(j,0,i+1)
          if(m[i][j]==-1) {
            while(a[now]==-1) now++;
              m[i][j]=a[now++];
          }
    }
    R(i,0,n) {
        R(j,0,i+1) printf("%d%c", m[i][j],j==i?'\n':' ');
    }
    return 0;
}
