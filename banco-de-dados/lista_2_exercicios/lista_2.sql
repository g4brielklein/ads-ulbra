create table tbproduto (
  pkcodprod integer not null,
  nomeprod varchar(100),
  estoqueprod integer,
  custoprod number(15,2),
  margemprod number(15,2),
  valorvendaprod number(15,2),
  quantitensprod number(15,2),
  constraint tbproduto_pk primary key(pkcodprod)
);

create table tbmateriaprima (
  pkcodmat integer not null,
  nomemat varchar(100),
  estoquemat integer,
  valorunit number(15,2),
  constraint tbmateriaprima_pk primary key(pkcodmat)
);

create table tbcomproduto (
  pkcodcomprod integer not null,
  fkcodmat integer,
  fkcodprod integer,
  quant number(15,2),
  constraint tbcomproduto_pk primary key(pkcodcomprod)
);

insert into tbmateriaprima(pkcodmat, nomemat, estoquemat, valorunit) values(1, 'mat 1', 10, 2.00);
insert into tbmateriaprima(pkcodmat, nomemat, estoquemat, valorunit) values(2, 'mat 2', 5, 1.50);
insert into tbmateriaprima(pkcodmat, nomemat, estoquemat, valorunit) values(3, 'mat 3', 3, 5.00);
insert into tbmateriaprima(pkcodmat, nomemat, estoquemat, valorunit) values(4, 'mat 4', 1, 2.50);
insert into tbmateriaprima(pkcodmat, nomemat, estoquemat, valorunit) values(5, 'mat 5', 50, 4.00);

insert into tbproduto(pkcodprod, nomeprod, estoqueprod, custoprod, margemprod, valorvendaprod, quantitensprod) values(1, 'produto 1', 3, 8.00, 50.00, 12.00, 2);
insert into tbproduto(pkcodprod, nomeprod, estoqueprod, custoprod, margemprod, valorvendaprod, quantitensprod) values(2, 'produto 2', 0, 16.00, 10.00, 17.60, 3);
insert into tbproduto(pkcodprod, nomeprod, estoqueprod, custoprod, margemprod, valorvendaprod, quantitensprod) values(3, 'produto 3', 5, 8.00, 70.00, 13.60, 2);

insert into tbcomproduto(pkcodcomprod, fkcodmat, fkcodprod, quant) values(1, 2, 1, 2);
insert into tbcomproduto(pkcodcomprod, fkcodmat, fkcodprod, quant) values(2, 3, 1, 1);
insert into tbcomproduto(pkcodcomprod, fkcodmat, fkcodprod, quant) values(3, 5, 2, 1);
insert into tbcomproduto(pkcodcomprod, fkcodmat, fkcodprod, quant) values(4, 3, 2, 2);
insert into tbcomproduto(pkcodcomprod, fkcodmat, fkcodprod, quant) values(5, 1, 2, 1);
insert into tbcomproduto(pkcodcomprod, fkcodmat, fkcodprod, quant) values(6, 1, 3, 2.5);
insert into tbcomproduto(pkcodcomprod, fkcodmat, fkcodprod, quant) values(7, 2, 3, 2);


