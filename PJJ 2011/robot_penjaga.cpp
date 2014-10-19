#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb push_back
#define fs first
#define sc second
#define diem 0
#define naik 1
#define kanan 2
#define turun 3
#define kiri 4
typedef vector<int> VI;

typedef struct {
    int a, b, arah;
} pjg;

typedef vector<pjg> VVI;

typedef struct {
    int a, b, c;
    VVI p;
} qyu;

queue<qyu> q;

int bar, kol, njaga, langkah=-1;
int ax, ay, bx, by;
char m[20][20];
bool udah[120][120][120];
void try_walk(int a, int b, int c, VVI p, int arah) {
    if( a>=0 and a<bar and b>=0 and b<kol and m[a][b]!='#') {
        //printf("%d %d %d\n", a, b, c); 
        if(udah[a][b][c]) {
            //printf("%d %d %d\n", a, b, c); 
            return;
        }
        bool bisa = 1;
        R(i,0,njaga) {
          // kasus tabrakan
          
          if(p[i].arah==1) {
              if(p[i].b  == bar-1 ) {
                  p[i].b--; p[i].arah=-1;
              } else if( m[ p[i].a ][ p[i].b+1 ]=='#' and m[ p[i].a ][ p[i].b-1 ]=='#') {
                  //diem
              } else if( m[ p[i].a ][ p[i].b+1 ]=='#' ) {
                  p[i].b--; p[i].arah=-1;
              } else p[i].b++;
          } else {
              if(p[i].b == 0) {
                  p[i].b++; p[i].arah = 1;
              } else if(m[ p[i].a ][ p[i].b-1] == '#' and m[ p[i].a ][ p[i].b+1 ]=='#') {
                  //diem
              } else if(m[ p[i].a ][ p[i].b-1] == '#') {
                  p[i].b++; p[i].arah = 1;
              } else p[i].b--;
          }
          if( a == p[i].a and b-1 == p[i].b and p[i].arah==-1 and arah == kanan) bisa=0;
          if( a == p[i].a and b+1 == p[i].b and p[i].arah== 1 and arah == kiri) bisa=0;
          
          // di tempat sama
          if( a == p[i].a and b == p[i].b) bisa=0;
        }
        if(bisa) {
            qyu tmp; tmp.a = a; tmp.b = b; tmp.c = c; tmp.p = p;
            q.push(tmp);
            udah[a][b][c]=1;
        }
    }
}

void bfs(int a, int b, VVI p) {
    qyu tmp; tmp.a=a; tmp.b=b; tmp.p=p; tmp.c=0;
    q.push(tmp);
    while(q.front().c <= 150 and !q.empty()) {
        qyu t = q.front();
        //printf("a=%d, b=%d, c=%d\n", t.a, t.b, t.c);
        if(t.a == bx and t.b == by) {
            langkah = t.c;
            return ;
        }
        q.pop();
        //atas
        try_walk(t.a-1, t.b, t.c+1, t.p, naik);
        try_walk(t.a, t.b+1, t.c+1, t.p, kanan);
        try_walk(t.a+1, t.b, t.c+1, t.p, turun);
        try_walk(t.a, t.b-1, t.c+1, t.p, kiri);
        try_walk(t.a, t.b, t.c+1, t.p, diem);
    }
}

int main() {
    scanf("%d", &bar); kol = bar;
    R(i,0,bar) scanf("%s", m[i]);
    VVI penjaga;
    
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j]=='X') { 
                pjg tmp; tmp.a = i, tmp.b = j, tmp.arah = 1;
                penjaga.pb(tmp);
            }
            if(m[i][j]=='S') ax=i,ay=j;
            if(m[i][j]=='T') bx=i,by=j;
        }
    }
    njaga = penjaga.size();
    bfs(ax,ay,penjaga);
    while(!q.empty() ){
        qyu t = q.front(); q.pop();
        //printf("a=%d, b=%d, c=%d\n", t.a, t.b, t.c);
    }
    printf("%d\n", langkah);
    return 0;
}
