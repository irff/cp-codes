#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LLD;
typedef map<int, bool> MIB;

MIB m;
int awal, akhir;
char s[100];
void rek(int ke, int v) {
    if(ke==9) {
        //printf("%d\n", v);
        int na = v, va = 0;
        long long ni = (LLD)na*na, vi = 0;
        while(na>0) va += (na%10),na/=10;
        while(ni>0) vi += (ni%10),ni/=10;
        if(va*va == vi) m[v]=1;
        return ;
    }
    rek(ke+1,v*10);
    rek(ke+1,v*10+1);
    rek(ke+1,v*10+2);
    rek(ke+1,v*10+3);
}

int main() {
    gets(s);
    rek(0,0);
    m[1000000000]=1;
    scanf("%d%d", &awal, &akhir);
    int n = 0;
    for(MIB::iterator it=m.begin(); it!=m.end(); it++) {
        if(it->first >= awal and it->first <=akhir) {
            printf("%lld\n", it->first);
            n++;
        }
    }
    printf("%d\n", n);

    return 0;
}
