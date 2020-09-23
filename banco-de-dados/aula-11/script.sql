create table tbmarca(
    pkcodmarca integer not null,
    nomemarca varchar(30),
    quatveiculos integer,
    primary key (pkcodmarca)
);

insert into tbmarca(pkcodmarca, nomemarca,quatveiculos ) values (1,&#39;VW&#39;,0);
insert into tbmarca(pkcodmarca, nomemarca,quatveiculos ) values (2,&#39;FORD&#39;,0);
insert into tbmarca(pkcodmarca, nomemarca,quatveiculos ) values (3,&#39;FIAT&#39;,0);

create table tbtipodespesa(
    pktipodesp integer not null,
    descricaodesp varchar(30),
    somatoriodesp numeric(15,2),
    servicoproduto integer,
    primary key (pktipodesp)
);

insert into tbtipodespesa(pktipodesp, descricaodesp,somatoriodesp,servicoproduto) values (55,&#39;Auto
Peças&#39;,0,1);
insert into tbtipodespesa(pktipodesp, descricaodesp,somatoriodesp,servicoproduto) values
(56,&#39;Mecânica&#39;,0,2);
insert into tbtipodespesa(pktipodesp, descricaodesp,somatoriodesp,servicoproduto) values
(57,&#39;Despachante&#39;,0,2); 

create table tbveiculo(
    pkcodvei integer not null,
    placa varchar(8),
    modelo varchar(30),
    valorcompra numeric(15,2),
    valorvenda numeric(15,2) default 0,
    somatoriodespesa numeric(15,2) default 0,
    quantdespesas integer default 0,
    mediapordespesa numeric(15,2) default 0,
    lucrovenda numeric(15,2) default 0,
    fkcodmarca integer,
    vendido integer default 0,
    primary key (pkcodvei)
);

create table tbdespesasvei(
    pkcoddespvei integer not null,
    fkcodvei integer,
    fktipodesp integer,
    descricaodespesa varchar(60),
    datalanc date,
    valordespesa numeric(15,2) default 0,
    primary key (pkcoddespvei)
);