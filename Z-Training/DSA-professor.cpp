#include <cstdio>

int n,a[6],num,total,hasil;
double rat;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        total+=num;
        a[num]++;
    }
    for(int i=1; i<=5; i++){
        scanf("%d", &num);
        hasil+=(num*a[i]);
    }
    printf("%d ", hasil);
    
    rat=(double)total/n;
    if((int)(rat*10)%10==0) printf("%.0lf\n", rat);
    else printf("%.1lf\n", rat);
    scanf("\n");
    return 0;
}
