#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n,hitung=0;
string s;

int main () {
    char angka[10][15]= { "*nol*", "*satu*", "*dua*", "*tiga*", "*empat*",
                          "*lima*", "*enam*", "*tujuh*", "*delapan*", "*sembilan*"};
    scanf("%d", &n);
    getline(cin,s);
    while(n--) {
        getline(cin,s);
        int len=s.length();;
        for(int i=0; i<len; i++) {
            if(s[i]=='\"') {
                printf("%s", angka[hitung%10]);
                hitung++;
            } else printf("%c", s[i]);
        }
        printf("\n");
    }

    return 0;
}
