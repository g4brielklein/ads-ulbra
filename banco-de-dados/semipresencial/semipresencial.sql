create table tbDestino (
  pkCodDest integer not null,
  nomeDest varchar(100) not null unique,
  constraint tbDestino_pkCodDest primary key(pkCodDest)
)

create table tbAviao (
  pkCodAviao integer not null,
  anoFabAviao integer not null,
  modeloAviao varchar(50) not null,
  numVoos integer constraint check_numVoos check(numVoos>=0 and numVoos<=4000),
  constraint tbAviao_pkCodAviao primary key(pkCodAviao)
)

create table tbVoo (
  pkNumVoo integer not null,
  origemVoo varchar(100) not null unique,
  fkDestVoo varchar(100) not null unique,
  dataHoraSaida timestamp not null,
  dataHoraChegada timestamp not null,
  numPoltronas integer default 120,
  lugaresOcupados integer default 0,
  check(lugaresOcupados < numPoltronas),
  constraint tbVoo_pkNumVoo primary key(pkNumVoo)
)

alter table tbVoo add constraint tbVoo_fkDestVoo foreign key(fkDestVoo)
  references tbDestino(nomeDest) on delete cascade
  
create table tbCliente (
  pkCodCli integer not null,
  nomeCli varchar(50) not null,
  enderecoCli varchar(100),
  bairroCli varchar(100),
  idadeCli integer,
  CpfCli integer not null unique,
  sexo varchar(1) not null constraint check_sexo check(sexo in('M','F')),
  nomeMaeCli varchar(50),
  qtdReservas integer default 0 constraint check_qtdReservas check(qtdReservas >= 0),
  qtdCancel integer default 0 constraint check_qtdCancel check(qtdCancel >= 0),
  constraint tbCliente_pkCodCli primary key(pkCodCli)
)

create table tbPassagem (
  pkCodPass integer not null,
  fkCodCli integer not null,
  fknumVoo integer not null,
  numPoltrona integer not null,
  status integer not null,
  constraint tbPassagem_pkCodPass primary key(pkCodPass)
)

alter table tbPassagem add constraint tbPassagem_fkCodCli foreign key(fkCodCli)
  references tbCliente(pkCodCli) on delete cascade
  
begin transaction
insert into tbPassagem(pkCodPass, fkCodCli, fknumVoo, numPoltrona, status) values (1, 1, 1, 1, 0);
update tbVoo set lugaresOcupados = lugaresOcupados + 1 where pkNumVoo = 1;
update tbCliente set qtdReservas = qtdReservas + 1 where pkCodCli = 1;
commit;

begin transaction
insert into tbPassagem(pkCodPass, fkCodCli, fknumVoo, numPoltrona, status) values (2, 2, 1, 2, 0);
savepoint s1;
update tbVoo set lugaresOcupados = lugaresOcupados + 1 where pkNumVoo = 1;
update tbCliente set qtdReservas = qtdReservas + 1 where pkCodCli = 1;
rollback;
update tbVoo set lugaresOcupados = lugaresOcupados - 1 where pkNumVoo = 1;
update tbCliente set qtdReservas = qtdReservas - 1 where pkCodCli = 1;
update tbCliente set qtdCancel = qtdCancel + 1 where pkCodCli = 1;
commit;

  
