#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,char> m;
string s;
int main() {
    m["| oo  .  o|"]='a';
    m["|  o  .   |"]=' ';
    m["| ooo .  o|"]='q';
    m["| ooo .o o|"]='u';
    m["| oo o.  o|"]='i';
    m["| oo  . oo|"]='c';
    m["| oo o. oo|"]='k';
    m["| oo  . o |"]='b';
    m["| ooo . o |"]='r';
    m["| oo o.ooo|"]='o';
    m["| ooo .ooo|"]='w';
    m["| oo o.oo |"]='n';
    m["| oo  .oo |"]='f';
    m["| oo o.ooo|"]='o';
    m["| oooo.   |"]='x';
    m["| oo o. o |"]='j';
    m["| ooo .o o|"]='u';
    m["| oo o.o o|"]='m';
    m["| ooo .   |"]='p';
    m["| ooo . oo|"]='s';
    m["| oo o.ooo|"]='o';
    m["| ooo .oo |"]='v';
    m["| oo  .o o|"]='e';
    m["| ooo . o |"]='r';
    m["| ooo .o  |"]='t';
    m["| oo o.   |"]='h';
    m["| oo  .o o|"]='e';
    m["| oo o.o  |"]='l';
    m["| oo  .  o|"]='a';
    m["| oooo. o |"]='z';
    m["| oooo.  o|"]='y';
    m["| oo  .o  |"]='d';
    m["| oo o.ooo|"]='o';
    m["| oo  .ooo|"]='g';
    m["|  o o.oo |"]='.';
    m["|    o. o |"]='\n';
    bool besar=1;
    while( getline(cin, s) > 0 ) {
        if( besar and m[s]!=' ' and m[s]!='\n') putchar( m[s]-'a'+'A'),besar=0;
        else putchar(m[s]);
        if( m[s]=='.') besar=1;
    }
    return 0;
}
