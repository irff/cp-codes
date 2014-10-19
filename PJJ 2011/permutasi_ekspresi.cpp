#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

char s[100];
int len,hasil;
map<long long, bool> ada, udah[15];
void rek(int a, long long d) {
    if( udah[a][d] == 1) return ;
    udah[a][d]=1;
    if(a==len) { ada[d]=1; return ; }
    int ctr=0;
    long long n=0;
    R(i,a,len) {
        n=n*10+(s[i]-'0');
        if(a==0) rek(i+1, n); 
        else {
             rek(i+1,d+n);
             rek(i+1,d-n);
        }
    }
}
int main() {
    scanf("%s", &s);
    len = strlen(s);
    rek(0,0);
    for(map<long long,bool>::iterator it=ada.begin(); it!=ada.end(); it++) {
        //printf("%d\n", it->first);
        hasil++;
    }
    printf("%d\n", hasil);
    return 0;
}
