#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<=int(_b); i++)
#define r(i,_a,_b) for(int i=int(_a); i<int(_b); i++)
int n;
char s[30];
char m[100][200];

void draw(int i, int pos) {
    if(pos==1) R(j,i*(n+3)+1,i*(n+3)+n) m[0][j]='-';
    if(pos==2) R(j,1,n) m[j][i*(n+3)]='|';
    if(pos==3) R(j,1,n) m[j][i*(n+3)+n+1]='|';
    if(pos==4) R(j,i*(n+3)+1,i*(n+3)+n) m[n+1][j]='-';
    if(pos==5) R(j,n+2,2*n+1) m[j][i*(n+3)]='|';
    if(pos==6) R(j,n+2,2*n+1) m[j][i*(n+3)+n+1]='|';
    if(pos==7) R(j,i*(n+3)+1,i*(n+3)+n) m[2*n+2][j]='-';
}

int main() {
    scanf("%d%s", &n, s);
    int len=strlen(s);
    r(i,0,2*n+3) r(j,0,len*(n+3)-1) m[i][j]='.';
    r(i,0,len) {
        if(s[i]=='0') {
            draw(i,1); draw(i,2); draw(i,3); draw(i,5); draw(i,6); draw(i,7);
        } if(s[i]=='1') {
            draw(i,3); draw(i,6);
        } if(s[i]=='2') {
            draw(i,1); draw(i,3); draw(i,4); draw(i,5); draw(i,7); 
        } if(s[i]=='3') {
            draw(i,1); draw(i,3); draw(i,4); draw(i,6); draw(i,7);
        } if(s[i]=='4') {
            draw(i,2); draw(i,3); draw(i,4); draw(i,6);
        } if(s[i]=='5') {
            draw(i,1); draw(i,2); draw(i,4); draw(i,6); draw(i,7);
        } if(s[i]=='6') {
            draw(i,1); draw(i,2); draw(i,4); draw(i,5); draw(i,6); draw(i,7);
        } if(s[i]=='7') {
            draw(i,1); draw(i,3); draw(i,6);
        } if(s[i]=='8') {
            draw(i,1); draw(i,2); draw(i,3); draw(i,4); draw(i,5); draw(i,6); draw(i,7);
        } if(s[i]=='9') {
            draw(i,1); draw(i,2); draw(i,3); draw(i,4); draw(i,6); draw(i,7);
        }
    }
    r(i,0,2*n+3) printf("%s\n", m[i]);
    return 0;
}
