#include <cstdio>
#include <cstdlib>

int selisih,now,circlek,rumah,n;
int main() {
    scanf("%d%d", &n, &circlek);
    int selisih=2000111222;
    for(int i=0; i<n; i++) {
        scanf("%d", &rumah);
        if( abs(circlek-rumah) < selisih) selisih=abs(circlek-rumah),now=rumah;
    }
    printf("Rumah Gasam terletak pada lokasi : %d\n", now);
    return 0;
}
