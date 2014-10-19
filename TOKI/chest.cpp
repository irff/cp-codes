#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define P2 pair<int,int>
#define P4 pair<P2,P2>
#define P3 pair<P2,int>
#define x first
#define y second

vector<P4> a;
P3 b,c;
int tipe,xx,xy,yx,w,teskes;
long long hasil;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        hasil=0LL;
        scanf("%d", &tipe);
        if(tipe==0) {
            scanf("%d%d%d%d", &xx,&xy,&yx,&w);
            a.push_back( P4( P2(xx,xy),P2(yx,w) ) );
        } 
        else if(tipe==1){
            scanf("%d%d%d", &b.x.x, &b.x.y, &b.y);
            scanf("%d%d%d", &c.x.x, &c.x.y, &c.y);
            R(i,0,a.size()){
                if( a[i].x.x >= b.x.x and a[i].x.x <=c.x.x)
                 if( a[i].x.y >= b.x.y and a[i].x.y <=c.x.y)
                  if( a[i].y.x >= b.y and a[i].y.x <= c.y)
                   hasil+=a[i].y.y;
            }
            printf("%lld\n", hasil);
        }
    }
    return 0;
}
