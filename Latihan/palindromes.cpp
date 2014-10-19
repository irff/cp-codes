#include <cstdio>
#include <cstring>

char mirror[256],s[100];
int len;

bool cekmirror() {
    bool sama=1;
    for(int i=0; i<=len/2; i++)
      if(s[i]!=mirror[ s[len-i] ]) sama=0;
    return sama;
}

bool cekpalin() {
    bool sama=1;
    for(int i=0; i<=len/2; i++)
      if(s[i]!=s[len-i]) sama=0;
    return sama;
}

int main(){
    mirror['A']='A'; mirror['M']='M';
    mirror['E']='3'; mirror['0']='0';
    mirror['H']='H'; mirror['S']='2';
    mirror['I']='I'; mirror['T']='T';
    mirror['J']='L'; mirror['U']='U';
    mirror['L']='J'; mirror['V']='V';
    
    mirror['W']='W'; mirror['X']='X';
    mirror['Y']='Y'; mirror['Z']='5';
    mirror['1']='1'; mirror['2']='S';
    mirror['3']='E'; mirror['5']='Z';
    mirror['8']='8'; mirror['O']='O';
    while(scanf("%s", s) > 0 ) {
        len=strlen(s)-1;
        bool ispal=cekpalin();
        bool ismir=cekmirror();
        printf("%s -- ", s);
        if(ispal and ismir) printf("is a mirrored palindrome\n");
        else if(ispal) printf("is a regular palindrome\n");
        else if(ismir) printf("is a mirrored string\n");
        else printf("is not a palindrome\n");
    }
}
