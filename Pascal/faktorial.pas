function faktorial(n:integer):longint;
begin
	if(n = 0) then faktorial := 1
	else faktorial := n * faktorial(n-1);
end;

begin
	writeln(faktorial(6));
end.