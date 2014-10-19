var soal:string;
    i,k,n:integer;
    ni,nu,np,tmp:real;
    
function checkprefix(ch:char;a:real):real;
begin
    if(ch='m') then checkprefix:=a/1000
    else if(ch='k') then checkprefix:=a*1000
    else if(ch='M') then checkprefix:=a*1000000
    else checkprefix:=a;
end;

function findformula(i:integer; quan,units:char):real;
var num:string;
    j,x:integer;
    angka:real;
begin
    if (soal[i]=quan) and (soal[i+1]='=') then
    begin
        j:=i+2; x:=0;
        while (soal[j]<>'m') and (soal[j]<>'k') and (soal[j]<>'M') and (soal[j]<>units) do
        begin
            num[x]:=soal[j];
            inc(x); inc(j);
        end;
        val(num, angka);
        findformula:=checkprefix(soal[j], angka);
    end else findformula:=-1;
end;
begin
    readln(n);
    for k:=1 to n do
    begin
        ni:=-1; nu:=-1; np:=-1;
        readln(soal);
        for i:=1 to length(soal) do
        begin
             writeln(i);
            tmp:=findformula(i,'I', 'A');
            if tmp <> -1 then ni:=tmp;
            tmp:=findformula(i,'U', 'V');
            if tmp <> -1 then nu:=tmp;
            tmp:=findformula(i,'P', 'W');
            if tmp <> -1 then np:=tmp;
        end;
        writeln('Problem #',k);
        if ni=-1 then writeln('I=',(np/nu):0:2,'A')
        else if nu=-1 then writeln('U=',(np/ni):0:2,'V')
        else writeln('P=',(nu*ni):0:2,'W');
        
        writeln;
    end;
end.
