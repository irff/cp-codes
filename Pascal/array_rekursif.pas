var
	a : array[1..100] of integer;
	i, n : integer;

procedure tampilkan(x : integer);
begin
	if(x <= n) then begin
		write(a[x],' ');
		tampilkan(x + 1);
	end else
	writeln;
end;

procedure input(x : integer);
begin
	if(x <= n) then begin
		read(a[x]);
		input(x + 1);
	end;
end;

begin
	readln(n);
	input(1);
	tampilkan(1);
end.