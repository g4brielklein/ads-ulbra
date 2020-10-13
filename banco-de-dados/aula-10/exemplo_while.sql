create or replace
function somatorio
  (num in integer) return integer
is
  n integer;
  r integer;
begin
  n:= 1;
  r:= 0;
while n<=num loop
  r:= r + n;
  n:= n + 1;
end loop;
return(r);
end somatorio;