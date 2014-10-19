#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define fs first
#define sc second

typedef map<int,int> MII;
typedef pair<int,int> PII;
typedef long long LLD;

int teskes;
int n, bar, kol;
int counta[1200], countb[1200];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(counta, 0, sizeof counta);
        memset(countb, 0, sizeof countb);
        scanf("%d%d%d", &bar, &kol, &n);
        R(i,0,n) {
            int a,b;
            scanf("%d%d", &a, &b);
            counta[a]++; countb[b]++;
        }
        int ansa = 1, minsa = 2000111222, ansi = 1, minsi = 2000111222;
        R(i,1,1001) {
            int suma = 0, sumi =0;
            R(j,1,1001) {
                if(counta[j]!=0) suma+=abs((j-i))*counta[j];
                if(countb[j]!=0) sumi+=abs((j-i))*countb[j];
            }
            if(suma < minsa) minsa = suma, ansa = i;
            if(sumi < minsi) minsi = sumi, ansi = i;
        }
        printf("(Street: %d, Avenue: %d)\n", ansa, ansi);
    }
    return 0;
}
