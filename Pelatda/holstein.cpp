/*
    ID: irfan1
    LANG: C++
    TASK: holstein
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> II;
typedef vector<int> VI;

VI cow, m[30], winning;
int nvit, nmakan, num, ans=2000111222;

void rek(int step, int ambil, VI manaaja, VI sisa) {
    if(step>=nmakan) return ;
    VI tmp=sisa;
    
    //kalo ngambil;
    bool jadi=1;
    R(i,0,nvit) {
        tmp[i]=sisa[i]-m[step][i];
        if(tmp[i]>0) jadi = 0;
    }
    //printf("%d\n", step);
    manaaja.push_back(step);
    if(jadi and ans > ambil+1) {
        //R(i,0,nvit) printf("%d ", tmp[i]);
        //printf("\n");
        ans=min(ans,ambil+1);
        winning = manaaja;
    } else rek(step+1, ambil+1, manaaja, tmp);

    //kalo ga ngambil;
    manaaja.pop_back();
    rek(step+1,ambil,manaaja,sisa);
    

}

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    scanf("%d", &nvit);
    
    R(i,0,nvit) { scanf("%d", &num); cow.push_back(num); }
    
    scanf("%d", &nmakan); 
    
    R(i,0,nmakan) {
        R(j,0,nvit) { scanf("%d", &num); m[i].push_back(num); }
    }
    VI tmp;
    rek(0,0,tmp,cow);
    printf("%d ", ans);
    if(ans>0) for(int i=0; i<ans; i++) printf("%d%c", winning[i]+1,(i==ans-1)?'\n':' ');
    return 0;
}
