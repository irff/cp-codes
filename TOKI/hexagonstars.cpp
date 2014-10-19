#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(c) c.begin(),c.end()
#define PII pair<int,int>
#define VII vector<PII>
#define x first
#define y second

int n,hexa;
VII awal,pilihan,hasil;
PII sampah;

int CP(PII P, PII Q, PII R){
    return (P.x-Q.x)*(R.y-Q.y)-(P.y-Q.y)*(R.x-Q.x);
}

VII ConvexHull( VII points){
    int fwd=0; VII CH;
    for(int i=0; i<points.size(); i++){
        while(fwd>1 and CP( CH[fwd-2], CH[fwd-1], points[i] ) <= 0) CH.pop_back(),fwd--;
        CH.push_back(points[i]),fwd++;
    }
    int bwd=fwd;
    
    for(int i=points.size()-2; i>=0; i--){
        while(bwd > fwd and CP(CH[bwd-2], CH[bwd-1], points[i]) <=0 ) CH.pop_back(),bwd--;
        CH.push_back(points[i]),bwd++;
    }
    CH.erase(CH.begin());
    //printf("\nsize : %d\n", CH.size());
    return CH;
}

int main(){
    hexa=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &sampah.x, &sampah.y);
        awal.push_back(sampah);
    }
    sort(ALL(awal));
    for(int i1=0; i1<n; i1++)
     for(int i2=i1+1; i2<n; i2++)
      for(int i3=i2+1; i3<n; i3++)
       for(int i4=i3+1; i4<n; i4++)
        for(int i5=i4+1; i5<n; i5++)
         for(int i6=i5+1; i6<n; i6++){
             pilihan.clear();
             pilihan.push_back(awal[i1]);
             pilihan.push_back(awal[i2]);
             pilihan.push_back(awal[i3]);
             pilihan.push_back(awal[i4]);
             pilihan.push_back(awal[i5]);
             pilihan.push_back(awal[i6]);
             sort(ALL(pilihan));
             
             /*for(int i=0; i<pilihan.size(); i++){
                 printf("** %d %d\n", pilihan[i].x, pilihan[i].y);
             }*/
             hasil=ConvexHull(pilihan);
             sort(hasil.begin(), hasil.end());
             /*for(int i=0; i<hasil.size(); i++){
                 printf("-- %d %d\n", hasil[i].x, hasil[i].y);
             }
             puts("\n");*/
             if(pilihan==hasil) hexa++;
         }
    printf("%d\n", hexa);
    return 0;
}
