#include <cstdio>

char ga[1000],gb[1000];
int teskes,n;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%s%s", &n,ga,gb);
        if(n%2==1) printf("%s\n", ga);
        else {
            bool dp=0;
            for(int i=1; i<30; i++) {
                if(n==(1<<i)) { dp=1; break; }
            }
            if(dp) printf("%s\n", gb);
            else printf("%s\n", ga);
        }
    }

}
