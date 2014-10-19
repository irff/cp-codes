#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef pair<double,PII> PDI;

PDI bioskop[700000];
int bar,kol;
int m[1200][600];

bool cp(PDI a, PDI b) {
    if(fabs(a.first-b.first) < 1e-9) {
        if(a.second.first == b.second.first) return a.second.second < b.second.second;
        return a.second.first > b.second.first;
    }
    return a.first < b.first;
}

int main() {
    scanf("%d%d", &kol, &bar);
    int ada = 0;
    int posa=bar-1, posi = kol/2;
    
    for(int i=0; i<bar; i++) {
        for(int j=0; j<kol; j++) {
            bioskop[ada].first = (double)sqrt((double)(abs(posa-i)*abs(posa-i)+abs(posi-j)*abs(posi-j)));
            bioskop[ada].second.first = i;
            bioskop[ada].second.second = j;
            ada++;
        }
    }
    //printf("%d\n", ada);
    sort(bioskop, bioskop+ada, cp);
    for(int i=0; i<ada; i++) {
        m[bioskop[i].second.first][bioskop[i].second.second]=i+1;
    }
    for(int i=0; i<bar; i++) {
        for(int j=0; j<kol; j++) {
           printf("%d%c", m[i][j], (j==kol-1)?'\n':' ');
        }
    }
    return 0;
}
