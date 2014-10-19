var
    n,i: integer;
    x : array[1..10000] of real;

function cek(a,b:real) : real;
var
    ha,hb,t,u,mid : real;
begin
    mid := (a+b)/2;
    for i:=1 to n do begin
        t:=abs(x[i]-a);
        ha:=ha+sqrt(t*t*t);
        u:=abs(x[i]-b);
        hb:=hb+sqrt(t*t*t);
    end;
    if(a==b) cek:=a
    else if(hb>ha) cek:=cek(a,mid)
    else cek:=cek(mid,b);
end;

begin
    readln(n);
    for i:=1 to n do begin
        readln(x[i]);
    end;
    writeln(cek(0,1000));
end.
