create table tbdestino (
  pkcodigodestino integer not null,
  nomedestino varchar(20) not null
);

alter table tbdestino
  add constraint tbdestinopk primary key(pkcodigodestino);

create table tbaviao (
  pkcodigoaviao integer not null,
  anofabaviao date not null,
  modeloaviao varchar(30),
  numvoosrealizados integer,
  numpoltronas integer,
);

alter table tbaviao add constraint tbaviaopk primary key(pkcodigoaviao); 

create table tbvoo (
  pknumerovoo integer not null,
  origemvoo varchar(100) not null,
  datasaida date,
  datasaida time,
  datachegada date,
  datachegada time,
  numlugaresocupados integer,
);

alter table tbclassificacao add constraint tbvoopk primary key(pknumerovoo);

create table tbreserva (
  pkcodigoreserva integer not null,
  numpoltronas integer,
);

alter table tbreserva add constraint tbreservapk primary key(pkcodigoreserva);

create table tbcliente (
  pkcpfcli integer not null,
  nomecli varchar(50),
  enderecocli varchar(50),
  bairrocli varchar(50),
  idadecli integer,
  sexocli char,
  nomedamaecli varchar(50),
  qtdreservas integer,
  qtdcancelamentos integer
);

alter table tbcliente add constraint tbclientepk primary key(pkcpfcli);

create table tbpassageiro (
  pkcpfpass integer not null,
  nomepass varchar(30) not null,
  idadepass integer,
  status integer,
);

alter table tbpassageiro add constraint tbpassageiropk primary key(pkcpfpass);
