#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define x first
#define y second

typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

queue<PIII> q;
int bar,kol,homex=-1,homey=-1,n;
int arah=1,id=0;
char m[300][300];
string s;
vector<PII> v;

int detect(string s) {
    if(s=="LURUS") return 0;
    if(s=="KIRI") return 1;
    return 2;
}

void move() {
    while(!q.empty() and q.front().y<id){
        PIII t=q.front(); q.pop();

        if(arah==1) 
            for(int i=t.x.x-1; i>=0 and m[i][t.x.y]!='#'; i--) q.push(PIII(PII(i,t.x.y),id));
        else if(arah==2)
            for(int j=t.x.y+1; j<kol and m[t.x.x][j]!='#'; j++) q.push(PIII(PII(t.x.x,j),id));
        else if(arah==3)
            for(int i=t.x.x+1; i<bar and m[i][t.x.y]!='#'; i++) q.push(PIII(PII(i,t.x.y),id));
        else for(int j=t.x.y-1; j>=0 and m[t.x.x][j]!='#'; j--) q.push(PIII(PII(t.x.x,j),id));
    }
}

int main() {
    scanf("%d%d", &bar,&kol);
    R(i,0,bar) scanf("%s", m[i]);
    R(i,0,bar) R(j,0,kol) if(m[i][j]=='H') homex=i,homey=j;
    
    q.push(PIII(PII(homex,homey),0));
    
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
    while(!q.empty()) {
        v.push_back(PII(q.front().x.x,q.front().x.y));
        q.pop();
    }
    sort(v.begin(),v.end());
    vector<PII>::iterator akhir=unique(v.begin(),v.end());
    
    printf("%d\n", akhir-v.begin());
    for(vector<PII>::iterator it=v.begin(); it!=akhir; it++) printf("%d %d\n", it->first+1, it->second+1);
    return 0;
}
