program salingsilang;

var
r,c,i,j,k,m,n:integer;
a:array[0..101,0..101] of char;
dumb:char;
thestring:string;
counter:boolean;

begin
readln(r,c);
for i:=1 to r do
for j:=1 to c do
if j<c then read(a[j,i],dumb) else readln(a[j,i]);
readln(n);
for k:=1 to n do
begin
counter:=false;
readln(thestring);
for i:=1 to r do
begin
for j:=1 to c do
begin
if a[j,i]=thestring[1] then
begin
counter:=true;
for m:=2 to length(thestring) do
if a[j-m+1,i]thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
counter:=true;
for m:=2 to length(thestring) do
if a[j-m+1,i-m+1]thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
counter:=true;
for m:=2 to length(thestring) do
if a[j,i-m+1]thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
counter:=true;
for m:=2 to length(thestring) do
if a[j+m-1,i-m+1] thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
counter:=true;
for m:=2 to length(thestring) do
if a[j+m-1,i] thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
counter:=true;
for m:=2 to length(thestring) do
if a[j+m-1,i+m-1] thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
counter:=true;
for m:=2 to length(thestring) do
if a[j,i+m-1] thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
counter:=true;
for m:=2 to length(thestring) do
if a[j-m+1,i+m-1] thestring[m] then
begin
counter:=false;
break;
end;
if counter then break;
end;
if counter then break;
end;
if counter then break;
end;
if counter then writeln(thestring, ‘ Y’) else writeln(thestring,’ T’);
end;

end.
