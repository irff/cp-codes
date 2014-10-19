#include <cstdio>
#include <bitset>
using namespace std;

bitset<8> bs;
int teskes,num;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        char s[1000];
        strcpy(s,"");
        scanf("%s", &s);
        for(int i=0; i<32; i++){
            bs[i%8]=s[i]-'0';
            if(i%8==7){
                int num=0;
                for(int j=7; j>=0; j--){
                    num+=bs[j]*(1<<(7-j));
                }
                printf("%d", num);
            }
            if(i%8==7 and i!=31) putchar('.');
        }
        puts("");
    }
}
