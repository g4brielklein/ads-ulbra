select * from produto;

insert into produto(codigo,nome,valor,estoque) values(4,’laranja’,3.4,60);
update produto set estoque=500 where codigo=1;
commit;

select * from produto;