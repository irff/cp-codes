#include <cstdio>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define x first
#define y second

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

bool udah[202][202][22],laser[202][202][22];
list<PIII> q;
int bar,kol,homex=-1,homey=-1,n;
int arah=1,id=0;
char m[300][300];
string s;

int detect(string s) {
    if(s=="LURUS") return 0;
    if(s=="KIRI") return 1;
    return 2;
}

void move() {
    while(!q.empty() and q.front().x<id){
        PIII t=q.front(); q.pop_front();
        if(!laser[t.y.x][t.y.y][t.x]) {
          laser[t.y.x][t.y.y][t.x]=1;
          if(arah==1) 
            for(int i=t.y.x-1; i>=0 and m[i][t.y.y]!='X'; i--) {
                PIII tmp=PIII(id,PII(i,t.y.y));
                if(!udah[tmp.y.x][tmp.y.y][tmp.x]) udah[tmp.y.x][tmp.y.y][tmp.x]=1,q.push_back(tmp);
            }
          else if(arah==2)
            for(int j=t.y.y+1; j<kol and m[t.y.x][j]!='X'; j++) {
                PIII tmp=PIII(id,PII(t.y.x,j));
                if(!udah[tmp.y.x][tmp.y.y][tmp.x]) udah[tmp.y.x][tmp.y.y][tmp.x]=1,q.push_back(tmp);
            }
          else if(arah==3)
            for(int i=t.y.x+1; i<bar and m[i][t.y.y]!='X'; i++) {
                PIII tmp=PIII(id,PII(i,t.y.y));
                if(!udah[tmp.y.x][tmp.y.y][tmp.x]) udah[tmp.y.x][tmp.y.y][tmp.x]=1,q.push_back(tmp);
            }
          else 
            for(int j=t.y.y-1; j>=0 and m[t.y.x][j]!='X'; j--) {
                PIII tmp=PIII(id,PII(t.y.x,j));
                if(!udah[tmp.y.x][tmp.y.y][tmp.x]) udah[tmp.y.x][tmp.y.y][tmp.x]=1,q.push_back(tmp);
            }
        }
    }
}

int main() {
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) scanf("%s", m[i]);
    R(i,0,bar) R(j,0,kol) if(m[i][j]=='H') homex=i,homey=j;
    
    q.push_back(PIII(0,PII(homex,homey)));
    scanf("%d", &n);
    while(n-- and !q.empty() ) {
        cin >> s;
        int gerakan=detect(s);
        if(gerakan==0) {
            id++;
            move();
        } else if(gerakan==1) {
            arah--;
            if(arah==0) arah=4;
        } else {
            arah++;
            if(arah==5) arah=1;
        }
    }
    while(n>=0) { cin >> s; n--; }
    q.sort(); q.unique();
    printf("%d\n", q.size());
    for(list<PIII>::iterator it=q.begin(); it!=q.end(); it++) printf("%d %d\n", it->y.x+1,it->y.y+1);   
    return 0;
}
