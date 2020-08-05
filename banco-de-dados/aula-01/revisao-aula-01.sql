create table tbgenero (
  pkcodgen integer not null,
  nomegen varchar(20) not null
);

alter table tbgenero
  add constraint tbgeneropk primary key(pkcodgen);

create table tbfilme (
  pkcodfilme integer not null,
  titulo varchar(30) not null,
  fkcodgen integer,
  fkcodclass integer
);

alter table tbfilme add constraint tbfilmepk primary key(pkcodfilme); 
alter table tbfilme add constraint tbfilme_fkcodgen foreign key(fkcodgen)
  references tbgenero(pkcodgen) ;
alter table tbfilme add constraint tbfilme_fkcodclass foreign key(fkcodclass)
  references tbclassificacao(pkcodclass);

create table tbclassificacao (
  pkcodclass integer not null,
  nomeclass varchar(20) not null,
  valodiaria number(5,2)
);

alter table tbclassificacao add constraint tbclassificacaopk primary key(pkcodclass);

create table tbrelfilmeloc (
  pkcodrel integer not null,
  fkcodfilme integer,
  fkcodloc integer
);

alter table tbrelfilmeloc add constraint tbrelfilmelocpk primary key(pkcodrel);
alter table tbrelfilmeloc add constraint tbrelfilmeloc_fkcodfilme foreign key(fkcodfilme) references tbfilme(pkcodfilme);
alter table tbrelfilmeloc add constraint tbrelfilmeloc_fkcodloc foreign key(fkcodloc) references tblocacao(pkcodloc);

create table tblocacao (
  pkcodloc integer not null,
  dataloc date,
  fkcodcli integer
);

alter table tblocacao add constraint tblocacaopk primary key(pkcodloc);
alter table tblocacao add constraint tblocacao_fkcodcli foreign key(fkcodcli) references tbcliente(pkcodcli);


create table tbcliente (
  pkcodcli integer not null,
  nomecli varchar(30) not null,
  endcli varchar(30),
  cidadecli varchar(30),
  ufcli varchar(2)
);

alter table tbcliente add constraint tbclientepk primary key(pkcodcli);
