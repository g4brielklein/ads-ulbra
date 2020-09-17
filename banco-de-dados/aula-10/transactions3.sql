update produto set estoque=400 where codigo=4;
update produto set estoque=900 where codigo=6;
savepoint ponto1;
insert into produto(codigo,nome,valor,estoque)
values(7,’melão’,6.80,20);
delete from produto where codigo=2;
savepoint ponto2;
delete from produto where codigo=1;
rollback to savepoint ponto1;
update produto set estoque=700 where codigo=3;
commit;