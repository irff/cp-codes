var
    i,j,teskes,k : integer;
    s,T,tmp : string;
    ans : array[1..4] of string;
begin
  readln(teskes);
  for k:=1 to teskes do begin
    readln(s);
    T:='';
    for i:= 1 to length(s) do begin
        if(s[i]='1') then begin
            ans[3]:=T+'2';
            ans[4]:=T+'3';
        end else
        if(s[i]='2') then begin
            ans[2]:=T+'1';
            ans[4]:=T+'4';
        end else
        if(s[i]='3') then begin
            ans[1]:=T+'1';
            ans[3]:=T+'4';
        end else
        if(s[i]='4') then begin
            ans[1]:=T+'2';
            ans[2]:=T+'3';
        end;
        T:=T+s[i];
    end;
    for i:=1 to 4 do
      for j:= i+1 to 4 do
          if(ans[i]>ans[j]) then begin
              tmp:=ans[i];
              ans[i]:=ans[j];
              ans[j]:=tmp;
          end;
      writeln('Case #',k,':');
    for i:=1 to 4 do begin
        if(length(ans[i])<>0) then writeln(ans[i]);
        ans[i]:='';
    end;

  end;
end.