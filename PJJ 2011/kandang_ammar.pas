var
        a,b,k : array[0..507,0..507] of char;
        n,m,i,j,x,y,bebek,kucing,selisih : longint;
 
procedure floodkucing(c,d : longint);
begin
        k[c,d] := 'K';
        if k[c+1,d] = '.' then floodkucing(c+1,d);
        if k[c-1,d] = '.' then floodkucing(c-1,d);
        if k[c,d+1] = '.' then floodkucing(c,d+1);
        if k[c,d-1] = '.' then floodkucing(c,d-1);
end;
 
procedure floodbebek(c,d : longint);
begin
        b[c,d] := 'B';
        if b[c+1,d] = '.' then floodbebek(c+1,d);
        if b[c-1,d] = '.' then floodbebek(c-1,d);
        if b[c,d+1] = '.' then floodbebek(c,d+1);
        if b[c,d-1] = '.' then floodbebek(c,d-1);
end;
 
begin
        readln(n,m);
        for i := 0 to m+1 do
                for j := 0 to n+1 do a[i,j] := '#';
 
        for i := 1 to m do begin
                for j := 1 to n do read(a[i,j]);
                readln();
        end;
 
        for i := 1 to m do
                for j := 1 to n do if a[i,j] = 'K' then begin
                        k[i,j] := '.';
                        x := i;
                        y := j;
                end else if a[i,j] = 'B' then k[i,j] := '.' else k[i,j] := a[i,j];
        floodkucing(x,y);
 
        for i := 1 to m do
                for j := 1 to n do if a[i,j] = 'B' then begin
                        b[i,j] := '.';
                        x := i;
                        y := j;
                end else if a[i,j] = 'K' then b[i,j] := '.' else b[i,j] := a[i,j];
        floodbebek(x,y);
 
        for i := 1 to m do
                for j := 1 to n do if k[i,j] = 'K' then inc(kucing);
        for i := 1 to m do
                for j := 1 to n do if b[i,j] = 'B' then inc(bebek);
 
        selisih := abs(kucing-bebek);
        if selisih = 0 then writeln('SERI') else
                if kucing > bebek then writeln('K ',selisih) else
                        writeln('B ',selisih);
end.
