#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define x first
#define y second
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define PII pair<int,int>
#define ALL(c) c.begin(),c.end() 
vector<PII> p;
int teskes,n,a,b,c,start,maks;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        p.clear();
        maks=1;
        scanf("%d", &n);
        R(i,0,n){
            scanf("%d%d%d", &a, &b, &c);
            p.push_back(PII(a+b+c,a+b));
        }
        sort(ALL(p));
        start=p[0].x;
        R(i,1,n)
           if( p[i].y >= start) start=p[i].x,maks++;
        printf("%d\n", maks);
    }

    return 0;
}
