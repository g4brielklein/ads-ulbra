update produto set estoque=800 where codigo=2;
delete from produto where codigo=3;
insert into produto(codigo,nome,valor,estoque)
values(5,’morango’,4.70,50);
select * from produto order by codigo;
rollback;
insert into produto(codigo,nome,valor,estoque)
values(6,’pêssego’,1.50,70);
select * from produto order by codigo;
commit;