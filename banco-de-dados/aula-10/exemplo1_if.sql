create or replace
procedure exemplo1_if
  (n1 in number, n2 in number)
is
begin
  if n1 = n2 then
    dbms_output.put_line('n1 é igual a n2');
  end if;
  if (n1 > (n2*2)) then
    dbms_output.put_line('N1 é maior do que o dobro de N2');
  else
    dbms_output.put_line('N1 não é maior do que o dobro de N2');
  end if;
end exemplo1_if;