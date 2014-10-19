#include <cstdio>

int teskes,num;
int main () {
    while(scanf("%d", &teskes) and teskes!=0) {

        for(int i=0; i<teskes; i++) {
            scanf("%d", &num);
            if(num%7==0 and num%13==0) printf("Uga Weird Year\n");
            else if(num%7==0) printf("Uga Lucky Year\n");
            else if(num%13==0) printf("Uga BadLuck Year\n");
            else printf("Uga???\n");
        }
        printf("Jumlah perawan yang selamat: %d orang\n", teskes*3);
    
    }
    return 0;
}
