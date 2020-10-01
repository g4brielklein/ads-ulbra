-- Exemplo 1: - “Criação do cenário para testar dos exemplos”

create table tbfuncionario(
codfunc integer not null,
nomefunc varchar(20),
salariofunc number(15,2),
constraint funcionario_PK primary key(codfunc)
);
insert into tbfuncionario(codfunc,nomefunc,salariofunc) values (1,’Maria’,2000);
insert into tbfuncionario(codfunc,nomefunc,salariofunc) values (2,’Debora’,1500);
insert into tbfuncionario(codfunc,nomefunc,salariofunc) values (3,’Rosana’,3500);

-- Exemplo de procedure
CREATE OR REPLACE PROCEDURE aumenta_sal
(codigo IN tbfuncionario.codfunc%TYPE,
perc IN number)
IS
BEGIN
    UPDATE tbfuncionario
    SET salariofunc = salariofunc+(salariofunc* perc/100)
    WHERE codfunc = codigo;
END aumenta_sal;