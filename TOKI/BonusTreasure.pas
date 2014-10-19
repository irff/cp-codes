function f(i, N : longint) : char;
var j : longint;
begin
   if i = 1 then f:='(' else
   if i = (1 shl N) then f:= ')' else begin
      for j:=1 to N do
         if i <= (1 shl j)-1 then begin
            f := f(i-(1 shl (j-1))+1, j-1);
            break;
         end;
   end;
end;
 
var N, K, M, i : longint;
 
begin
   while true do begin
      readln(N,K,M); if (N=0) and (K=0) and (M=0) then break;
      inc(K); for i:=K to K+M-1 do write( f(i, N) ); writeln;
   end;
end.
