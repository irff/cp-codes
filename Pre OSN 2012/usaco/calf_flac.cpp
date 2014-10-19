/*
    ID: irfan1
    LANG: C++
    TASK: calfflac
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char ori[21000],s[21000];
int realpos[21000], reala, realb, maks=-1;
int main() {
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    int ci=0,ca=0;
    char ch;
    while(scanf("%c", &ch)>0) {
        if( (ch >='a' and ch<='z') or (ch>='A' and ch<='Z')) {
            s[ca] = ch;
            if(ch >='A' and ch <='Z') s[ca]=s[ca]-'A'+'a';
            realpos[ca]=ci;
            ca++;
        }
        ori[ci]=ch;
        ci++;
    }
    //satu
    for(int i=0; i<ca; i++) {
        int a=i, b=i;
        while(a > 0 and b<ca-1 and s[a-1] == s[b+1]) {
            a--; b++;
        }
        if(b-a+1 > maks) {
            maks = b-a+1;
            reala = realpos[a];
            realb = realpos[b];
        }
    }
    
    //dua
    for(int i=0; i<ca-1; i++) {
        int a=i, b=i+1;
        while(s[a]==s[b] and a > 0 and b<ca-1 and s[a-1] == s[b+1]) {
            a--; b++;
        }
        
        if(b-a+1 > maks) {
            maks = b-a+1;
            reala = realpos[a];
            realb = realpos[b];
        }
    }
    /*
    for(int i=0; i<ca; i++) {
        for(int j=ca-1; j>=i; j--) {
            if(j-i+1 > maks) {  
                int a = i, b = j;
                while(a < b and s[a]==s[b]) {
                    a++;
                    b--;
                }
                if(a>=b) {
                    maks = j-i+1;
                    reala = realpos[i];
                    realb = realpos[j];
                }
            }
        }
    }
    */
    printf("%d\n", maks);
    for(int i=reala; i<realb+1; i++) printf("%c", ori[i]);
    printf("\n");
    return 0;
}

