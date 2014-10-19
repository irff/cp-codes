#include <cstdio>
#include <cstring>
using namespace std;

char utama[100200],sub[100200];
int n;
int main() {
    scanf("%d", &n);
    scanf("%s", utama);
    int len=strlen(utama);
    for(int i=0; i<n; i++) {
        scanf("%s", sub);
        int lensub=strlen(sub);
        int x=0;
        for(int j=0; j<len and x<lensub; j++) {
            if( utama[j]==sub[x] ) x++;
        }
        printf("%c\n", (x==lensub)?'Y':'N');
    }
    return 0;
}
