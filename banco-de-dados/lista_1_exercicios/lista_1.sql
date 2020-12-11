create table tbproduto (
  pkcodprod number not null,
  nomeprod varchar2(20),
  estoqueprod integer,
  estoquemin integer,
  valorvendaprod number(10,2),
  quantultcompra integer
);

alter table tbproduto add constraint tbproduto_pk primary key(pkcodprod);

create table tbcliente (
  pkcodcli number not null,
  nomecli varchar2(100),
  limitecompra number(10,2),
  comprarealizada number(10,2),
  saldoliberado number(10,2),
  ultimadatacompra date
);

alter table tbcliente add constraint tbcliente_pk primary key(pkcodcli);

create table tbpedido (
  pkcodped number not null,
  fkcodcli number,
  datapedido date,
  totalpedido number(10,2)
);

alter table tbpedido add constraint tbpedido_pk primary key(pkcodped);
alter table tbpedido add constraint tbpedido_fk1 foreign key(fkcodcli)
references tbcliente(pkcodcli);

create table tbitensped (
  pkcoditens number not null,
  fkcodprod number,
  fkcodped number,
  quantidade integer,
  valorunit number(10,2),
  valortotal number(10,2)
);

alter table tbitensped add constraint tbitensped_pk primary key(pkcoditens);
alter table tbitensped add constraint tbitensped_fk1 foreign key(fkcodprod)
references tbproduto(pkcodprod);
alter table tbitensped add constraint tbitensped_fk2 foreign key(fkcodped)
references tbpedido(pkcodped);





