#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=b;i--)
#define x first
#define y second
typedef pair<int,int> PII;

vector<PII> coor;
vector<double> gradien;
int start,finish,ntiang,d;
double hasil=0.00;
int main() {
    scanf("%d%d%d%d",&start,&finish,&ntiang,&d);
    coor.push_back(PII(start,0));
    coor.push_back(PII(finish,0));
    
    R(i,0,ntiang) {
        int a,b;
        scanf("%d%d", &a,&b);
        coor.push_back(PII(a-(d/2),b));
        coor.push_back(PII(a+(d/2),b));
    }
    //---SORTING SUMBU X
    sort(coor.begin(), coor.end());
    int n=coor.size();
    
    //---CARI TITIK TERTINGGI
    int maks=-1,kiri=-1, kanan=-1;
    R(i,0,n) {
        if(coor[i].y>maks) {
            maks=coor[i].y;
            kiri=i;
        }
    }
    
    //---CARI GRADIEN
    R(i,0,n) {
        double tmp=(double) (coor[kiri].y-coor[i].y)/(coor[kiri].x-coor[i].x);
        if(tmp<0) tmp*=-1;
        gradien.push_back(tmp);   
    }
    
    kanan=kiri;
    
    //---CARI JARAK KE KIRI
    while(kiri > 0) {
        double tmp=0.00,mins=2000111222.00;
        int id=0;
        R(i,0,kiri) if(gradien[i] < mins) { mins=gradien[i]; id=i; }
        tmp=sqrt( (coor[kiri].y-coor[id].y)*(coor[kiri].y-coor[id].y) + (coor[kiri].x-coor[id].x)*(coor[kiri].x-coor[id].x) );
        hasil+=tmp;
        kiri=id;
    }
    
    //---CARI JARAK KE KANAN
    while(kanan < n-1) {
        double tmp=0.00, mins=2000111222.00;
        int id=0;
        R(i,kanan+1,n) if(gradien[i] < mins) { mins=gradien[i]; id=i; }
        tmp=sqrt( (coor[kanan].y-coor[id].y)*(coor[kanan].y-coor[id].y) + (coor[kanan].x-coor[id].x)*(coor[kanan].x-coor[id].x) );
        hasil+=tmp;
        kanan=id;
    }
    printf("%.3lf\n", hasil);
    return 0;
}
