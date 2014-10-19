#include <cstdio>


int n,a[10000];

void swap(int i, int j) { int tmp=a[i]; a[i]=a[j]; a[j]=tmp; }

int partition(int ki, int ka) {
    int i=ki,j=ka+1,v=a[ki];
    while(1) {
        while(a[++i] < v) if(i==ka) break;
        while(a[--j] > v) if(j==ki) break;
        if(i>=j) break;
        swap(i,j);
    }
    swap(ki,j);
    return j;
}

void quicksort(int ki, int ka) {
    if( ki >= ka) return ;
    int j=partition(ki,ka);
    // DnC spirit!!!
    quicksort(ki,j-1);
    quicksort(j+1,ka);
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(0,n-1);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
