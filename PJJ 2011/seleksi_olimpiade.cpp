#include <algorithm>
#include <cstdio>
#include <string>
#include <functional>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<PII,PIS> NILAI;

int teskes, nsiswa, nlolos;
NILAI a[100];
string x;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &nsiswa, &nlolos);
        cin >> x;
        R(i,0,nsiswa) {
            cin >> a[i].second.second;
            scanf("%d%d%d", &a[i].second.first, &a[i].first.second, &a[i].first.first);
        }
        sort(a,a+nsiswa);
        bool lolos = 0;
        for(int i=nsiswa-1; i>nsiswa-1-nlolos; i--) {
            if(a[i].second.second == x) {
                lolos = 1;
                break;
            }
        }
        printf("%s\n", (lolos)?"YA":"TIDAK");
    }
    return 0;
}
