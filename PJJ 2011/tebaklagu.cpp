#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int nnada=24;

char s[120], ff[120], nada[24][3];
int utama[120], dicari[120];
int mins=9999,lens, idx, lenff, n;
bool ketemu=0;
int main() {
    strcpy(nada[0],"c.");   strcpy(nada[12],"C.");
    strcpy(nada[1],"c#");   strcpy(nada[13],"C#");
    strcpy(nada[2],"d.");   strcpy(nada[14],"D.");
    strcpy(nada[3],"d#");   strcpy(nada[15],"D#");
    strcpy(nada[4],"e.");   strcpy(nada[16],"E.");
    strcpy(nada[5],"f.");   strcpy(nada[17],"F.");
    strcpy(nada[6],"f#");   strcpy(nada[18],"F#");
    strcpy(nada[7],"g.");   strcpy(nada[19],"G.");
    strcpy(nada[8],"g#");   strcpy(nada[20],"G#");
    strcpy(nada[9],"a.");   strcpy(nada[21],"A.");
    strcpy(nada[10],"a#");   strcpy(nada[22],"A#");
    strcpy(nada[11],"b.");   strcpy(nada[23],"B.");
    
    scanf("%s", s); lens=strlen(s)/2;
    for(int i=0,l=0; i<lens*2; i+=2,l++) {
        for(int j=0; j<nnada; j++) {
            if(s[i]==nada[j][0] and s[i+1]==nada[j][1]) {
                utama[l]=j;
                mins=min(mins, j);
                break;
            } 
        }
    }
    for(int i=0; i<lens; i++) utama[i]-=mins;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        mins=9999;
        scanf("%s", ff); int lenf=strlen(ff)/2;
        for(int j=0,l=0; j<lenf*2; j+=2,l++) {
            for(int k=0; k<nnada; k++) {
                if(ff[j]==nada[k][0] and ff[j+1]==nada[k][1]) {
                    dicari[l]=k;
                    mins=min(mins,k);
                    break;
                }
            }
        }
        for(int j=0; j<lenf; j++) dicari[j]-=mins;
        
        for(int j=0; j+lens-1<lenf and !ketemu; j++) {
            int sama=0;
            for(int k=0; k<lens; k++) {
                if(utama[k]==dicari[j+k]) sama++;
            }
            if(sama==lens) ketemu=1;
        }
        
        if(ketemu) idx=i+1;        
    }
    
    if(ketemu) printf("%d\n", idx);
    else printf("#\n");
    
    return 0;
}
