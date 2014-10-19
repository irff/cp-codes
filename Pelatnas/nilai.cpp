#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

typedef pair<string,int> PII;

PII siswa[15200];
int nsiswa,nquery;
char nil[5];
int main() {
    scanf("%d", &nsiswa);
    R(i,0,nsiswa) cin >> siswa[i].second >> siswa[i].first;
    sort(siswa, siswa+nsiswa);
    scanf("%d", &nquery);
    R(i,0,nquery) {
        int k; scanf("%d", &k);
        printf("%d %s\n", siswa[k-1].second, siswa[k-1].first.c_str());
    }
    return 0;
}
