var i : integer;

function f(n : integer):integer;
begin
	if(n = 0) then f := 0
	else if(n = 1) then f := 1
	else f := f(n-1) + f(n-2);
end;

begin
	writeln(f(4));
end.

	f(3)
	= f(2) 			+ f(1)
	  f(1) + f(0)	  1
	  1   + 0