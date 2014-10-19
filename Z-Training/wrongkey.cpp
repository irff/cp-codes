#include <cstring>
#include <cstdio>
using namespace std;

char s[1100];
int words;
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0; i<len; i++){
        if(s[i]!=' ' and s[i+1]==' ') words++;
        
        if(s[i]==']') putchar('[');
        if(s[i]=='[') putchar('p');
        if(s[i]=='p') putchar('o');
        if(s[i]=='o') putchar('i');
        if(s[i]=='i') putchar('u');
        if(s[i]=='u') putchar('y');
        if(s[i]=='y') putchar('t');
        if(s[i]=='t') putchar('r');
        if(s[i]=='r') putchar('e');
        if(s[i]=='e') putchar('w');
        if(s[i]=='w') putchar('q');
        
        if(s[i]=='\'') putchar(';');
        if(s[i]==';') putchar('l');
        if(s[i]=='l') putchar('k');
        if(s[i]=='k') putchar('j');
        if(s[i]=='j') putchar('h');
        if(s[i]=='h') putchar('g');
        if(s[i]=='g') putchar('f');
        if(s[i]=='f') putchar('d');
        if(s[i]=='d') putchar('s');
        if(s[i]=='s') putchar('a');
        
        if(s[i]=='/') putchar('.');
        if(s[i]=='.') putchar(',');
        if(s[i]==',') putchar('m');
        if(s[i]=='m') putchar('n');
        if(s[i]=='n') putchar('b');
        if(s[i]=='b') putchar('v');
        if(s[i]=='v') putchar('c');
        if(s[i]=='c') putchar('x');
        if(s[i]=='x') putchar('z');
        
        if(s[i]=='\\') putchar('=');
        if(s[i]=='=') putchar('-');
        if(s[i]=='-') putchar('0');
        if(s[i]=='0') putchar('9');
        if(s[i]=='9') putchar('8');
        if(s[i]=='8') putchar('7');
        if(s[i]=='7') putchar('6');
        if(s[i]=='6') putchar('5');
        if(s[i]=='5') putchar('4');
        if(s[i]=='4') putchar('3');
        if(s[i]=='3') putchar('2');
        if(s[i]=='2') putchar('1');
        if(s[i]=='1') putchar('`');
        
        if(s[i]==' ') putchar(' ');
    }
    printf(" %d\n", words+1);
    scanf("\n");
    return 0;
}
