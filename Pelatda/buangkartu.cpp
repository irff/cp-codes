#include <cstdio>
#include <algorithm>
using namespace std;

int teskes;
int find_dekat(int num) {
    for(int i=1; i<=21; i++) {
        if(num <= (1<<i)) return (1<<i);
    }
}
char s[1000];
int main() {
    gets(s);
    scanf("%d", &teskes);
    while(teskes--) {
        int n;
        scanf("%d", &n);
        if(n==1) printf("%d\n", n);
        else {
            int dekat = find_dekat(n);
            printf("%d\n", dekat-(2*(dekat-n)));
        }
    }
    return 0;
}
