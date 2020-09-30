drop table tbparcela;
drop table tbitenscobertura;
drop table tbapolice;
drop table tbcliente;
drop table tbcobertura;
drop table tbveiculo;

create table tbcliente(
 pkcodcli integer not null,
 nomecli varchar(100),
 numapolices integer default 0,
 numparcelasaperto numeric(15,2),
 valorparcelasaberto numeric(15,2),
 primary key (pkcodcli)
);
 
insert into tbcliente(pkcodcli,nomecli, numapolices,numparcelasaperto,valorparcelasaberto) values (1,'Carol',1,2,250);
insert into tbcliente(pkcodcli,nomecli, numapolices,numparcelasaperto,valorparcelasaberto) values (2,'Ana',0,0,0);

create table tbcobertura(
 pkcodcobert integer not null,
 nomecobert varchar(100),
 valorpremiopadrao numeric(15,2),
 valorfranquiapadrao numeric(15,2),
 primary key (pkcodcobert)
);

insert into tbcobertura(pkcodcobert,nomecobert, valorpremiopadrao, valorfranquiapadrao) values (20,'Roubo',20000,1500);
insert into tbcobertura(pkcodcobert,nomecobert, valorpremiopadrao, valorfranquiapadrao) values (21,'Quebra Lanterna',0,150);
insert into tbcobertura(pkcodcobert,nomecobert, valorpremiopadrao, valorfranquiapadrao) values (22,'Quebra de vidro',0,250);

create table tbveiculo(
 pkcodvei integer not null,
 placavei varchar(8),
 modelo varchar(100),
 anofabricacao integer,
 numapolices  integer default 0,
 primary key (pkcodvei)
);

insert into tbveiculo(pkcodvei,placavei,modelo,anofabricacao,numapolices) values (88,'XXX-8888','Argo',2020,1);
insert into tbveiculo(pkcodvei,placavei,modelo,anofabricacao,numapolices) values (89,'AAA-9999','Fusca',1977,0);
insert into tbveiculo(pkcodvei,placavei,modelo,anofabricacao,numapolices) values (90,'BBB-7777','Gol',2019,0);

create table tbapolice(
 pknumapolice integer not null,
 fkcodcli integer,
 fkcodvei integer, 
 valortotalapolice numeric(15,2),
 primary key (pknumapolice),
 foreign key (fkcodvei) references tbveiculo(pkcodvei),
 foreign key (fkcodcli) references tbcliente(pkcodcli)
);

insert into  tbapolice( pknumapolice, fkcodcli, fkcodvei, valortotalapolice) values (456,1,88,1000);
 
create table tbitenscobertura(
 pkitens integer not null,
 fknumapolice integer,
 fkcodcobert integer, 
 valorcobertura numeric(15,2),
 primary key (pkitens),
 foreign key (fknumapolice) references tbapolice(pknumapolice),
 foreign key (fkcodcobert) references tbcobertura(pkcodcobert)
);
 
insert into tbitenscobertura(pkitens, fknumapolice, fkcodcobert, valorcobertura) values (1,456,20,850);
insert into tbitenscobertura(pkitens, fknumapolice, fkcodcobert, valorcobertura) values (2,456,22,150);

create table  tbparcela(
 pkcodparcela integer not null,
 fknumapolice integer,
 situacao integer default 0,
 valorparcela numeric(15,2),
 primary key (pkcodparcela),
 foreign key (fknumapolice) references tbapolice(pknumapolice)
);

insert into tbparcela(pkcodparcela, fknumapolice, situacao, valorparcela) values (1,456,1,250);
insert into tbparcela(pkcodparcela, fknumapolice, situacao, valorparcela) values (2,456,1,250);
insert into tbparcela(pkcodparcela, fknumapolice, situacao, valorparcela) values (3,456,1,250);
insert into tbparcela(pkcodparcela, fknumapolice, situacao, valorparcela) values (4,456,0,250);