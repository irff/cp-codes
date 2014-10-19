#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

char s[1000];
int n, len;
vector<int> v;

bool rek(int n, int id) {
    if(n==0 and id==len) return 1;
    char x[1000]; memset(x, '\0', sizeof x);
    int j=0,angka=0;
    for(int i=id; i<len; i++) {
        x[j++]=s[i];
        angka=atoi(x);
        if(n>=angka) {
            if( rek(n-angka, i+1) ) {
                v.push_back(angka);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int teskes;
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", s);
        scanf("%d", &n);
        len=strlen(s);
        rek(n,0);
        int gede=v.size();
        for(int i=gede-1; i>=0; i--) {
            printf("%d", v[i]);
            if(i!=0) printf(", ");
        }
        printf("\n");
        scanf("\n");
}
    
    return 0;
}
