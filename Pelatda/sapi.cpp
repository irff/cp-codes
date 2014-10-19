#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

char m[100][100];
int sapa,sapi,jona,joni,step=0;
int main() {
    R(i,0,10) scanf("%s", &m[i]);
    
    R(i,0,10) R(j,0,10) {
        if(m[i][j]=='F') jona=i,joni=j;
        if(m[i][j]=='C') sapa=i,sapi=j;
    }
    //printf("%d %d\n%d %d\n", jona, joni, sapa, sapi);
    int arahsapi=0,arahjon=0;
    while(step<1000) {
        if(sapa==jona and sapi==joni) break;
        if(arahsapi==0) {
            if(m[sapa-1][sapi]=='*' or sapa==0) arahsapi=1;
            else sapa--;
        } else
        if(arahsapi==1) {
            if(m[sapa][sapi+1]=='*' or sapi==9) arahsapi=2;
            else sapi++;
        } else
        if(arahsapi==2) {
            if(m[sapa+1][sapi]=='*' or sapa==9) arahsapi=3;
            else sapa++;
        } else
        if(arahsapi==3) {
            if(m[sapa][sapi-1]=='*' or sapi==0) arahsapi=0;
            else sapi--;
        }
        //jon
        if(arahjon==0) {
            if(m[jona-1][joni]=='*' or jona==0) arahjon=1;
            else jona--;
        } else
        if(arahjon==1) {
            if(m[jona][joni+1]=='*' or joni==9) arahjon=2;
            else joni++;
        } else
        if(arahjon==2) {
            if(m[jona+1][joni]=='*' or jona==9) arahjon=3;
            else jona++;
        } else
        if(arahjon==3) {
            if(m[jona][joni-1]=='*' or joni==0) arahjon=0;
            else joni--;
        }
        step++;
    }
    if(step>500) printf("0\n");
    else printf("%d\n", step);
    return 0;
}
