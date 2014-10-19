#include <cstdio>
#include <cstring>

char s[4];
int a,b;

int main() {
    for(int i=0; i<6; i++) {
        scanf("%s", &s);
        if(s[1]=='A') a++;
        else if(s[1]=='B') b++;
    }
    int skor=0;
    if(b>=3) skor=100;
    else if(b>=2) skor=70;
    else if(a>=1 and b>=2) skor=50;
    else if(a>=1 and b>=1) skor=40;
    else if(a>=2 and b>=1) skor=25;
    else if(a>=3) skor=20;
    else if(a>=2) skor=10;
    else if(b>=1) skor=5;
    else if(a>=1) skor=2;
    printf("%d\n", skor);

    return 0;
}
