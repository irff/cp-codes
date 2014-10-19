#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define x first
#define y second
typedef pair<int,int> PII;
typedef vector<PII> VII;

typedef struct {
    int a, b ,c;
} yeah;

yeah x;

int n,v1,v2;
VII coor1,coor2;

int CP(PII P, PII Q, PII R){
    return (P.x-Q.x)*(R.y-Q.y)-(P.y-Q.y)*(R.x-Q.x);
}

VII convexhull( VII points){
    int fwd=0; VII CH;
    
    R(i,0,points.size()){
     while(fwd>1 and CP( CH[fwd-2],CH[fwd-1],points[i]) <= 0) CH.pop_back(),fwd--;
     CH.push_back(points[i]),fwd++;
    }
    
    int bwd=fwd;
    RV(i,points.size()-2,0){
     while(bwd > fwd and CP(CH[bwd-2],CH[bwd-1],points[i]) <=0 ) CH.pop_back(),bwd--;
     CH.push_back(points[i]),bwd++;
    }
    return CH;
}

int main(){
    scanf("%d", &n);
    R(i,0,n){
        scanf("%d%d", &v1,&v2);
        coor1.push_back(PII(v1,v2));
    }
    yeah x = yeah(){1,2,3};
    sort(coor1.begin(),coor1.end());
    coor2=convexhull(coor1);
    R(i,0,coor2.size())
      printf("%d %d\n", coor2[i].first, coor2[i].second);
    scanf("\n");
    return 0;
}
