#include <cstdio>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[5002],b[5002],na,nb;
int ta,tb;
int hasil;
double ra,rb; // rata2 awal;
int main(){
    scanf("%d%d", &na,&nb);
    R(i,0,na) scanf("%d", &a[i]),ta+=a[i];
    R(i,0,nb) scanf("%d", &b[i]),tb+=b[i];
    ra=(double)ta/na; rb=(double)tb/nb;
    R(i,0,na){
        double tmp1=(double)(ta-a[i])/(na-1);
        double tmp2=(double)(tb+a[i])/(nb+1);
        if(tmp1 > ra and tmp2 > rb) hasil++;
    }
    printf("%d\n", hasil);
    return 0;
}
