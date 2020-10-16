create table tbfuncionario (
  codfunc integer not null,
  nomefunc varchar(20),
  salariofunc number(15,2),
  constraint tbfuncionario_pk primary key(codfunc)
);

insert into tbfuncionario(codfunc, nomefunc, salariofunc) values (1, 'Gabriel', 5000);
insert into tbfuncionario(codfunc, nomefunc, salariofunc) values (2, 'Christiano', 8000);
insert into tbfuncionario(codfunc, nomefunc, salariofunc) values (3, 'Jeferson', 9000);