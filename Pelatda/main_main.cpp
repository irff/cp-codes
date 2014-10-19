#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> PII;

char s[1000];
PII kap[1000];

bool cp(PII a, PII b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    scanf("%s", &s);
    int len = strlen(s);
    int ctr = 0;
    for(int i=1; i<len; i++) {
        if(s[i] >='A' and s[i] <= 'Z') {
            kap[ctr].first = s[i];
            kap[ctr].second = i;
            ctr++;
        }
    }
    sort(kap, kap+ctr, cp);
    for(int i=0; i<ctr; i++) {
        for(int j=0; j<len; j++) {
            bool ilang = 0;
            for(int k=0; k<=i; k++) {
                if(j == kap[k].second) ilang = 1;
            }
            if(!ilang) printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}
