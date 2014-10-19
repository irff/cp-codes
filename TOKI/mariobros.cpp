#include <cstdio>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define P2 pair<int,int>
#define P4 pair<P2,P2>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(v,it) for(deque<P4>::iterator it=(v).begin();it!=(v).end();it++)
int teskes,bar,kol;
int pea,peb,psa,psb,nbom;
P4 tmp;
deque<P4> bm;
char m[200][200];
void dodfs(int a,int b){
    if(a>=0 and a<bar and b>=0 and b<kol and m[a][b]!='E' and m[a][b]!='X' and m[a][b]!='#'){
        m[a][b]='X';
        dodfs(a-1,b);
        dodfs(a,b+1);
        dodfs(a+1,b);
        dodfs(a,b-1);
    }
}
bool reachable(int a,int b){
    if(a>0 and m[a-1][b]=='X') return 1;
    if(b>0 and m[a][b-1]=='X') return 1;
    if(a<bar-1 and m[a+1][b]=='X') return 1;
    if(b<kol-1 and m[a][b+1]=='X') return 1;
    return 0;
}

int allswitch(){
    int c=0;
    RV(bm,it){
       if(it->x.x!=-1 and m[it->x.x][it->x.y]=='X') {c=it-bm.begin(); return c;}
//       printf("%d %d\n",it->x.x,it->x.y);
    }
    return -1;
}

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        bool ketemu=0;
        bm.clear();
        scanf("%d%d", &bar, &kol);
        R(i,0,bar) scanf("%s", &m[i]);
        scanf("%d", &nbom);
        R(i,0,nbom) { 
            scanf("%d%d%d%d", &tmp.x.x,&tmp.x.y,&tmp.y.x,&tmp.y.y);
            tmp.x.x--;tmp.x.y--;tmp.y.x--;tmp.y.y--;
            bm.push_back(tmp);
        }
        R(i,0,bar) R(j,0,kol) { if(m[i][j]=='S') psa=i,psb=j; if(m[i][j]=='E') pea=i,peb=j; }
        dodfs(psa,psb);
        if(reachable(pea,peb)) ketemu=1;
        else while(allswitch()!=-1){
            int c = allswitch();
//            printf("%d\n", c);
            m[ bm[c].y.x ][ bm[c].y.y ] ='.';
            if(reachable(bm[c].y.x,bm[c].y.y)){
                dodfs(bm[c].y.x,bm[c].y.y);
                if(reachable(pea,peb)) { ketemu=1; break; }
            }
            bm[c]=P4(P2(-1,-1),P2(-1,-1));
        }
        //R(i,0,bar) printf("%s\n", m[i]);
        printf("%s\n", ketemu?"Yes":"No");
    }
    return 0;
}
