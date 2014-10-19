#include <cstdio>
#include <algorithm>
using namespace std;

char a[100][10];
int bar, kol;
int bisa_runtuh = -1;

int masih_runtuh(){
    int runtuh = -1;
    for(int i=0; i<bar; i++) {
        bool bisa = 1;
        for(int j=0; j<kol; j++) {
            if(a[i][j] == '0') bisa = 0;
        }
        if(bisa) {
            runtuh = i;
            for(int j=0; j<kol; j++) {
                a[i][j] = '0';
            }
        }
    }
    return runtuh;
}

void runtuhkan() {
    for(int j=0; j<kol; j++) {
        int x = bisa_runtuh, n=0;
        for(int i=x; i>=0; i--) {
            if(a[i][j]=='1') {
                n++;
                a[i][j]='0';
            }
        }
        while((x+1) < bar and a[x+1][j] == '0') {
            x++;
        }
        for(int i = x; i>=x-n+1; i--) a[i][j]='1';
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    for(int i=0; i<bar; i++) {
        scanf("%s", &a[i]);
    }
    bisa_runtuh = masih_runtuh();
    while(bisa_runtuh !=-1) {
        runtuhkan();
        bisa_runtuh = masih_runtuh();
    }
    for(int i=0; i<bar; i++) printf("%s\n", a[i]);
    return 0;
}
