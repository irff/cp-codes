#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
const int INF = -2000111222;
int teskes, n;
int da[4], di[4], daya, dayi, mins;
char s[10];
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int thatyear(int a, int b, int c) {
    //printf("-%d %d %d-\n", a, b, c);
    int now = 0, bul = 0;
    now+=a;
    //printf("thatyear %d ", now);
    R(i,1,b) {
        if(i==2) {
            if(c%4==0) now+=29;
            else now+=28;
        } else now+=month[i];
    }
    //printf("thatyear %d ", now);
    return now;
}
int compute(int a, int b, int c) {
    if(c == da[2]) {
        if(b == da[1]) {
            if(a > da[0]) return INF;
        }
        if(b > da[1]) return INF;
    }
    if(c > (da[2])) return INF;
    if(b > 12) return INF;
    if(b==2) {
        if(c%4==0) {
            if(a > 29) return INF;
        } else if( a > 28) return INF;
    } else {
        if(a > month[b]) return INF;
    }
    //printf("bisa\n");
    int now = 0, bul = 0;
    if(da[2] == c) {
      if(da[1]==b) {
          now = da[0]-a;
          return now;
      } else {
          if(b==2) {
              if(c%4==0) bul = 29;
              else bul = 28;
          } else bul = month[b];
          
          now+=(bul-a);
          R(i,b+1, da[1]) {
              if(i==2) {
                if(c%4==0) now+=29;
                else now+=28;
              } else now+=month[i];
          }
          now+=da[0];
          return now;
      }
    }
    else {
      if(b==2) {
        if(c%4==0) bul = 29;
        else bul = 28;
      } else bul = month[b];
      now+=(bul-a);
    
      R(i, b+1, 13) {
        if(i==2) {
            if(c%4==0) now+=29;
            else now+=28;
        } else now+=month[i];
      }
    }
    //printf("n1 %d ", now);
    R(i,c+1,da[2]) {
        if(i%4==0) now+=366;
        else now+=365;
    }
    //printf("n2 %d ", now);
    if(da[2] > c) now+=thatyear(da[0], da[1], da[2]);
    //printf("n3 %d ", now);
    return now;
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        mins = INF;
        daya = 0, dayi = 0;
        scanf("%s", &s);
        da[0] = ((s[0]-'0')*10)+(s[1]-'0');
        da[1] = ((s[3]-'0')*10)+(s[4]-'0');
        da[2] = ((s[6]-'0')*10)+(s[7]-'0');
        da[2] +=100;
        //printf("%d %d %d\n", da[0], da[1], da[2]);
        scanf("%s", &s);
        di[0] = ((s[0]-'0')*10)+(s[1]-'0');
        di[1] = ((s[3]-'0')*10)+(s[4]-'0');
        di[2] = ((s[6]-'0')*10)+(s[7]-'0');
        //printf("%d %d %d\n", di[0], di[1], di[2]);
        int limit = 0;
        for(int i=0, y = da[2]; i<18; i++, y--) {
            if(y%4==0) limit+=366;
            else limit+=365;
        }
        sort(di,di+3);
        int sem = compute(di[0], di[1], di[2]+100);
        mins = max(mins, sem);
        
        //printf("%d %d %d - %d\n", di[0], di[1], di[2], sem);
        while(next_permutation(di, di+3) > 0) {
            //printf("%d %d %d\n", di[0], di[1], di[2]);
            int sem = compute(di[0], di[1], di[2]+100);
            mins = max(mins, sem);
            //printf("%d %d %d - %d\n", di[0], di[1], di[2], sem);
            
        }
        //printf("limit = %d, mins = %d\n", limit, mins);
        if(mins != INF and mins >= limit) printf("YA\n");
        else printf("TIDAK\n");
    }
    return 0;
}
