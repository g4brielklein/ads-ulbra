create or replace
procedure exemplo_loop
  (fim in integer)
is
  n integer;
begin
  n:=1;
  loop
    dbms_output.put_line('Número é ' || n);
    if n=fim then
      exit;
    end if;
    n:= n+1;
  end loop;
  n:=n+1;
  loop
    dbms_output.put_line('Número é' || n);
    exit when n=fim;
    n:=n+1;
  end loop;
end exemplo_loop;