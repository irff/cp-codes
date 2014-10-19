#include <cstdio>
#define bp 2000
using namespace std;

int teskes;
long tarifbp,tarifjalan,jarak;
long biaya;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        biaya=0;
        scanf("%d%d%d", &tarifbp, &tarifjalan, &jarak);
        if(jarak>bp){
            biaya+=tarifbp;
            jarak-=bp;
            biaya+=(tarifjalan*(jarak/100));
            printf("%d\n", biaya);
        } else printf("%d\n", tarifbp);
    }
    return 0;
}
