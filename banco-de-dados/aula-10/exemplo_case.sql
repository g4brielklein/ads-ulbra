create or replace
procedure exemplo_case
  (n1 in number, n2 in number)
is
begin
  case
    when n1 > n2 then
      dbms_output.put_line('N1 é maior que N2');
    when n1 < n2 then
      dbms_output.put_line('N1 é menor que N2');
    else
      dbms_output.put_line('N1 é igual a N2');
  end case;
end exemplo_case;