#include <cstdio>
#include <cstring>
using namespace std;

int teskes,maxhp,maxmp,hp,mp,naction;
char s[100];
bool mati;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d", &maxhp,&maxmp,&naction);
        hp=maxhp,mp=maxmp;
        for(int i=0; i<naction; i++) {
            scanf("%s", s);
            mati=0;
            if(strcmp(s, "Heal")==0) {
                int x; scanf("%d", &x);
                if(!mati and mp>=15*x) {
                    hp+=50*x;
                    if(hp>maxhp) hp=maxhp;
                    mp-=(15*x);
                }
            } else if(strcmp(s,"Potion")==0) {
                hp+=50;
                if(!mati and hp>maxhp) hp=maxhp;
            } else {
                int x; scanf("%d", &x);
                if(!mati) {
                    hp-=x;
                    if(hp<=0) mati=1;
                }
            }
            printf("%d %d %s\n", hp,mp,mati?"mati":"hidup");
        }
        
        if(mati) printf("Game Over\n");
        else printf("Win(%d/%d)\n", hp,mp);
    }
    return 0;
}
