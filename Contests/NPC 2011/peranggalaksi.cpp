#include <cstdio>
#include <algorithm>
using std::max;

int teskes,na,nb,maksa,maksb;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        maksa=-1,maksb=-1;
        scanf("%d%d", &na,&nb);
        for(int i=0; i<na; i++) {
           int tmp;
           scanf("%d", &tmp);
           maksa=max(maksa,tmp);
        }
        for(int i=0; i<nb; i++) {
            int tmp;
            scanf("%d", &tmp);
            maksb=max(maksb,tmp);
        }
        if(maksa>=maksb) printf("Cak Matik\n");
        else printf("Robot Api\n");
    }
    return 0;
}
