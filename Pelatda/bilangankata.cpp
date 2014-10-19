#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int teskes;
char s[12000];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", &s);
        int len = strlen(s);
        bool angka = 0, huruf = 0;
        R(i,0,len) {
            if(s[i] >= 'A' and s[i] <='Z') huruf = 1;
            if(s[i] >= 'a' and s[i] <='z') huruf = 1;
            if(s[i] >= '0' and s[i] <='9') angka = 1;
        }
        if(huruf and angka) {
            printf("BUKAN KEDUANYA\n");
        } else
        if(huruf) {
            printf("KATA\n");
        } else {
            printf("BILANGAN\n");
        }
    }

    return 0;
}
