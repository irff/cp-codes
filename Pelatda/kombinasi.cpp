#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
int pertama,n;

void rek(int ke, VI v) {
    if(ke >= n) {
        for(int i=0; i<n; i++) printf("%c", v[i]+'A');
        printf("\n");
    } else {
        for(int i=v[ke-1]+1; i<pertama; i++) {
            VI tmp = v; tmp.push_back(i);
            rek(ke+1, tmp);
        }
    }
}

int main() {
    scanf("%d%d", &pertama, &n);
    
    for(int i=0; i <= pertama-n; i++) {
        vector<int> x;
        x.push_back(i);
        rek(1,x);
    }
    return 0;
}
