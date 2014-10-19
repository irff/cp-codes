#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define x first
#define y second
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

bool udah[60][60][1010],laser[60][60][1010];
list<PIII> q;

char sign[20], m[60][60];
int id=0,bar,kol,nsign;
int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) scanf("%s", m[i]);
    int ax,ay;
    R(i,0,bar) R(j,0,kol)
        if(m[i][j]=='*') ax=i,ay=j;
    
    m[ax][ay]='.';
    q.push_front(PIII(0,PII(ax,ay)));
    scanf("%d", &nsign);
    R(k,0,nsign) {
        id++;
        scanf("%s", sign);
        while(!q.empty() and q.front().x < id) {
          PIII t=q.front(); q.pop_front();
          if(!laser[t.y.x][t.y.y][t.x]) {
            laser[t.y.x][t.y.y][t.x]=1;
            
            if(strcmp(sign,"NORTH")==0) {
              for(int i=t.y.x-1; i>=0 and m[i][t.y.y]!='X'; i--) {
                PIII tmp=PIII(id,PII(i,t.y.y));
                if(!udah[i][t.y.y][id]) udah[i][t.y.y][id]=1,q.push_back(tmp);
              }
            } else if(strcmp(sign,"EAST")==0) {
              for(int j=t.y.y+1; j<kol and m[t.y.x][j]!='X'; j++) {
                PIII tmp=PIII(id,PII(t.y.x,j));
                if(!udah[t.y.x][j][id]) udah[t.y.x][j][id]=1,q.push_back(tmp);
              }
            } else if(strcmp(sign, "SOUTH")==0) {
              for(int i=t.y.x+1; i<bar and m[i][t.y.y]!='X'; i++) {
                PIII tmp=PIII(id,PII(i,t.y.y));
                if(!udah[i][t.y.y][id]) udah[i][t.y.y][id]=1,q.push_back(tmp);
              }
            } else {
              for(int j=t.y.y-1; j>=0 and m[t.y.x][j]!='X'; j--) {
                PIII tmp=PIII(id,PII(t.y.x,j));
                if(!udah[t.y.x][j][id]) udah[t.y.x][j][id]=1,q.push_back(tmp);
              }
            }
          }    
        }
    }
    
    q.sort(); q.unique();
    for(list<PIII>::iterator it=q.begin(); it!=q.end(); it++)
        m[it->y.x][it->y.y]='*';
        
    R(i,0,bar) printf("%s\n", m[i]);
        
    return 0;
}
