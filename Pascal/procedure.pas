procedure show(n : integer);
begin
	if(n = 3) then exit;
		
	show(n + 1);

	writeln(n);
end;

begin
	show(0);
end.

