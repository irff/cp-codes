#include <cstdio>
#include <cstring>
using namespace std;
#define p1 "var data:array[1..10000] of longint;"
#define p2 "    n,i,j,temp:longint;"
#define p3 "begin"
#define p4 "  readln(n);"
#define p5 "  for i:=1 to n do readln(data[i]);"
#define p6 "  for i:=1 to n-1 do"
#define p7 "    for j:=i+1 to n do"
#define p8 "      if (data[i]>data[j]) then"
#define p9 "      begin"
#define pa "        temp:=data[i];"
#define pb "        data[i]:=data[j];"
#define pc "        data[j]:=temp;"
#define pd "      end;"
#define pe "  for i:=1 to n do writeln(data[i]);"
#define pf "end."

#define c1 "int data[10001];"
#define c2 "int n,i,j,temp;"
#define c3 "int main(){"
#define c4 "  scanf(\"\%d\",&n);"
#define c5 "  for (i=1;i<=n;i++) scanf(\"\%d\",data[i]);"
#define c6 "  for (i=1;i<=n-1;i++)"
#define c7 "    for (j=i+1;j<=n;j++)"
#define c8 "      if (data[i]>data[j]){"
#define c9 "        temp=data[i];"
#define ca "        data[i]=data[j];"
#define cb "        data[j]=temp;"
#define cc "      }"
#define cd "  for (i=1;i<=n;i++) printf(\"\%d\\n\",data[i]);"
#define ce "  return 0;"
#define cf "}"

char s[1000];
int main(){
    scanf("%s", &s);
    if(strcmp(s,"PAS")==0){
        printf("%s\n", p1);
        printf("%s\n", p2);
        printf("%s\n", p3);
        printf("%s\n", p4);
        printf("%s\n", p5);
        printf("%s\n", p6);
        printf("%s\n", p7);
        printf("%s\n", p8);
        printf("%s\n", p9);
        printf("%s\n", pa);
        printf("%s\n", pb);
        printf("%s\n", pc);
        printf("%s\n", pd);
        printf("%s\n", pe);
        printf("%s\n", pf);
    } else if(strcmp(s,"CPP")==0){
        printf("%s\n", c1);
        printf("%s\n", c2);
        printf("%s\n", c3);
        printf("%s\n", c4);
        printf("%s\n", c5);
        printf("%s\n", c6);
        printf("%s\n", c7);
        printf("%s\n", c8);
        printf("%s\n", c9);
        printf("%s\n", ca);
        printf("%s\n", cb);
        printf("%s\n", cc);
        printf("%s\n", cd);
        printf("%s\n", ce);
        printf("%s\n", cf);
    }

    return 0;
}
