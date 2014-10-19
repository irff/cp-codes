#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

struct profil {
    char nama[300];
    int point;
    int win;
    int goal;
    int selisih;
    int nmain;
} ;

profil team[40]; 
int nteam,ntanding,gola,golb;
char nama[40][300],teama[300],teamb[300];

bool cmp(profil a, profil b) {
     if(a.point == b.point) {
      if(a.win == b.win) {
        if(a.selisih == b.selisih) {
          if(a.goal == b.goal) {
            if(a.nmain == b.nmain) {
                if(strcmp(a.nama,b.nama)==-1) return 1;
                return 0;
            }
            return a.nmain < b.nmain;
          }
          return a.goal > b.goal;
        }
        return a.selisih > b.selisih;
      }
      return a.win > b.win;
     }
     return a.point > b.point;
}

int main() {
    scanf("%d", &nteam);
    R(i,0,nteam) scanf("%s", team[i].nama);
    scanf("%d", &ntanding);
    R(i,0,ntanding) {
        scanf("%s %d %d %s", teama, &gola, &golb, teamb);
        int ida=0,idb=0;
        R(j,0,nteam) {
            if(strcmp(teama,team[j].nama)==0) ida=j;
            if(strcmp(teamb,team[j].nama)==0) idb=j;
        }
        if(gola > golb) team[ida].point+=3,team[ida].win++;
        else if(golb > gola) team[idb].point+=3,team[idb].win++;
        else team[ida].point++,team[idb].point++;
        
        team[ida].goal+=gola;
        team[ida].selisih+=(gola-golb);
        team[ida].nmain++;
        team[idb].goal+=golb;
        team[idb].selisih+=(golb-gola);
        team[idb].nmain++;
    }
    sort(team, team+nteam, cmp); 
    R(i,0,nteam) {
        printf("%s %d %d %d %d %d\n", team[i].nama, team[i].point,
        team[i].win,team[i].selisih,team[i].goal,team[i].nmain);
        //printf("%s\n", team[i].nama);
    }
}
