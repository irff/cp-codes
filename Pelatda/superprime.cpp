/*
    ID: irfan1
    LANG: C++
    TASK: sprime
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int prim[20000], np=0;
bool bs[20000];

bool cek(int num) {
    if(num==0 or num==1) return 0;
    int x = num, c=0;
    while(x>0 and c<np) {
        if(x%prim[c]==0 and prim[c]!=num) {
            return 0;
        }
        c++;
    }
    return 1;
}

void rek(int num, int step) {
    if(!cek(num)) return ;
    if(step>=n) {
        printf("%d\n", num);
        return ;
    }
    if(cek(num)) {
        for(int i=0; i<10; i++) {
            rek(num*10+i,step+1);
        }
    }
}


int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    for(int i=2; i<=10000; i++) bs[i]=1;
    for(int i=2; i*i<=10000; i++)
      for(int j=i*i; j<=10000; j+=i) bs[j]=0; 
    for(int i=2; i<=10000; i++) if(bs[i]) prim[np++]=i;

    scanf("%d", &n);
    for(int i=0; i<10; i++) rek(i,1);
    return 0;
}
