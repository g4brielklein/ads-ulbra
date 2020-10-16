create or replace procedure aumenta_sal
 (cod in tbfuncionario.codfunc%TYPE,
  perc in number)
is
begin
  update tbfuncionario
    set salariofunc = salariofunc+(salariofunc * perc/100)
    where codfunc = cod;
end aumenta_sal;