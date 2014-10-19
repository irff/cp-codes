#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define P2 pair<int,int>
#define P3 pair<int,P2>
#define x first
#define y second
int teskes,nkotak,nklik,r;
vector<P3> k;
P3 tmp,klik;
long long skor;

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        k.clear();
        skor=0;
        scanf("%d%d%d", &nkotak,&nklik,&r);
        R(i,0,nkotak) { scanf("%d%d%d", &tmp.x,&tmp.y.x,&tmp.y.y); k.push_back(tmp); }
        R(i,0,nklik){
            scanf("%d%d%d", &klik.x,&klik.y.x,&klik.y.y);
            R(j,0,k.size()){
                if(klik.y.x <= (k[j].y.x+r) and klik.y.x >= (k[j].y.x-r) and klik.y.y <= (k[j].y.y+r) and klik.y.y >= (k[j].y.y-r) ){
                    if(klik.x==k[j].x) skor+=300,k[j].x=-2000;
                    else if(klik.x==k[j].x+1) skor+=100,k[j].x=-2000;
                    else if(klik.x==k[j].x+2) skor+=50,k[j].x=-2000;
                }
            }
        }
        printf("%lld\n", skor);
    }
    return 0;
}
