drop table tbgol;
drop table tbpartida;
drop table tbatleta;
drop table tbclube;

create table tbclube(
pkcodclube integer not null,
nomeclube varchar(60) not null,
numvitorias integer default 0,
numderrotas integer default 0,
numempates integer default 0,
numjogosparticipados integer default 0,
constraint tbclubepkcodclube primary key(pkcodclube)
);

create table tbatleta(
pkcodatleta integer not null,
nomeatleta varchar(60) not null,
numerogolmarcadoatleta integer default 0,
fkclube integer,
constraint tbatletapkcodatletapk primary key(pkcodatleta)
);

alter table tbatleta add constraint tbatletafkclube foreign key(fkclube) references
tbclube(pkcodclube);

create table tbpartida(
pkcodpartida integer not null,
fktimeA integer not null,
fktimeB integer not null,
numerogoltimeA integer default 0,
numerogoltimeB integer default 0,
vencedor varchar(60),
constraint tbpartidapkcodpartida primary key(pkcodpartida)
);

alter table tbpartida add constraint tbpartidafktimeA foreign key(fktimeA) references
tbclube(pkcodclube);
alter table tbpartida add constraint tbpartidafktimeB foreign key(fktimeB) references
tbclube(pkcodclube);

create table tbgol(
pkcodgol integer not null,
fkcodclube integer not null,
fkcodpartida integer not null,
fkcodatleta integer not null,
constraint tbgolpkcodgol primary key(pkcodgol)
);

alter table tbgol add constraint tbgolfkcodclube foreign key(fkcodclube) references
tbclube(pkcodclube);
alter table tbgol add constraint tbgolfkcodpartida foreign key(fkcodpartida) references
tbpartida(pkcodpartida);
alter table tbgol add constraint tbgolfkcodatleta foreign key(fkcodatleta) references
tbatleta(pkcodatleta);

insert into tbclube( pkcodclube , nomeclube ) values (50,'Z� gotinha');
insert into tbclube( pkcodclube , nomeclube ) values (51,'Uma boa id�ia');
insert into tbclube( pkcodclube , nomeclube ) values (52,'Amigos do Barranco');

insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(1,'Zararias',0,51);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(2,'Dede',0,50);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(3,'Mussum',0,51);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(4,'Didi',0,52);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(5,'Gugu',0,50);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(6,'Bozo',0,50);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(7,'Ratata',0,51);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(8,'Eliana',0,51);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(9,'Ratinbum',0,51);
insert into tbatleta( pkcodatleta , nomeatleta , numerogolmarcadoatleta,fkclube) values
(10,'Zeca',0,52);

insert into tbpartida(pkcodpartida , fktimeA , fktimeB) values(700,51,50);
insert into tbpartida(pkcodpartida , fktimeA , fktimeB) values(701,51,52);
insert into tbpartida(pkcodpartida , fktimeA , fktimeB) values(702,50,52);