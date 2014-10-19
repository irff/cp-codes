#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

char a[100], b[100];
int mins = 2000111222;
int main() {
    scanf("%s%s", &a, &b);
    int lena = strlen(a); int leni = strlen(b);
    for(int i=0; i+lena<=leni; i++) {
        int beda = 0;
        for(int j=i, ctr = 0; ctr<lena; ctr++,j++) {
            if(b[j]!=a[ctr]) beda++;
        }
        mins = min(beda, mins);
    }
    printf("%d\n", mins);
    return 0;
}
