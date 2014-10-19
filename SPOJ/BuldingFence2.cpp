#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define x first.first
#define y first.second
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef pair<int,int> PII;
typedef pair<PII,int> PIII; // x,y, id;
typedef vector<PIII> PTS;
PTS awal;
int teskes,n;

int CP(PIII P, PIII Q, PIII R){
    return (P.x-Q.x)*(R.y-Q.y)-(P.y-Q.y)*(R.x-Q.x);
}

double perimeter(PTS p){
    double per=0.00,x1,y1,x2,y2,dx,dy;
    R(i,0,p.size()-1){
        x1=p[i].x; x2=p[i+1].x;
        y1=p[i].y; y2=p[i+1].y;
        per += sqrt( (x2-x1)*(x2-x1)+ (y2-y1)*(y2-y1) );
    }
    return per;
}

void proses(PTS &points){
    sort(points.begin(),points.end());
    int fwd=0; PTS CH;
    R(i,0,points.size()){
      while(fwd>1 and CP(CH[fwd-2],CH[fwd-1],points[i])<=0) CH.pop_back(),fwd--;
      CH.push_back(points[i]),fwd++;
    }
    int bwd=fwd;
    RV(i,points.size()-2,0){
      while(bwd>fwd and CP(CH[bwd-2],CH[bwd-1],points[i])<=0) CH.pop_back(),bwd--;
      CH.push_back(points[i]),bwd++;
    }
    if(CH.size()==1) printf("0.00\n1\n");
    else {
        CH.erase(CH.begin());
        PTS tmp;
 
        printf("%.2lf\n", perimeter(CH));
        
        RV(i,CH.size()-1,0){
            printf("%d ", CH[i].second);
        }
    }
    puts("");
}

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        awal.clear();
        scanf("%d", &n);
        R(i,1,n+1){
            int ca,cb;
            scanf("%d%d", &ca,&cb);
            awal.push_back(PIII(PII(ca,cb),i));
        }
        proses(awal);
        puts("");
    }
    return 0;
}
