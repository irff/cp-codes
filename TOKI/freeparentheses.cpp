#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

int angka,tanda;
int num[35],sig[35];
bool memo[31][31][6001];
bitset<6001> used;
char sampah[500];

void rec(int idx, int open, int val){
    if( memo[idx][open][val+3500]) // has been reached
        return ;
    memo[idx][open][val+3500]=1;
    if(idx==angka){
        used[val+3500]=1;
        return ;
    }
    int nval = val+num[idx+1]*sig[idx]* (( open%2==0 ) ? 1 : -1);
    if(sig[idx]== -1)
        rec(idx+1,open+1,nval); // kurung buka
    if(open>0)
        rec(idx+1,open-1, nval); // kurung tutup
    rec(idx+1, open, nval); // normal jare
}

int main(){
    while(gets(sampah)>0){
        angka=0; tanda=0;
        int i=1;
        // String TOKEN-ization
        for(char *p = strtok(sampah," "); p!=NULL; p = strtok(NULL, " "),i++){
            if(i%2) num[++angka] = atoi(p);
            else sig[++tanda] = (p[0]=='-' ? -1 : 1);
        }
        used.reset();
        memset(memo,0,sizeof(memo));
        
        rec(1, 0, num[1]);
        printf("%d\n", (int) used.count());
        strcpy(sampah,"");    
    }
    return 0;
}
