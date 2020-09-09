create table tbPaciente (
    pkCodPac integer not null,
    nomePac varchar(50) not null,
    idadePac integer constraint check_idadePac check(idadepac >= 0 and idadepac <=
    130),
    sexoPac varchar(1),
    alturaPac number(3,2),
    pesoPac number(4,2),
    cpfPac varchar(14) unique,
    emailPac varchar(100) unique,
    constraint tbPaciente primary key(pkCodPac)
);

create table tbProntuario (
    pkCodPront integer not null,
    dataColeta date,
    chave varchar(50) unique,
    convenio varchar(50),
    fkCodPac integer not null,
    fkCodExam integer not null,
    constraint tbProntuario_pkCodPront primary key(pkCodPront)
);

alter table tbProntuario add constraint tbProntuario_fkCodPac foreign key(fkCodPac)
    references tbPaciente(pkCodPac);
alter table tbProntuario add constraint tbProntuario_fkCodExam foreign key(fkCodExam)
    references tbExame(pkCodExam);

create table tbExame (
    pkCodExam integer not null,
    nomeExam varchar(50) not null unique,
    dataPront integer constraint check_dataPront check (datapronto >= 1 and datapronto
    <= 90),
    laudoExam varchar(200),
    fkCodTec integer not null,
    constraint tbExame_pkCodExam primary key(pkCodExam)
);

alter table tbExame add constraint tbExame_fkCodTec foreign key(fkCodTec)
    references tbTecnico(pkCodTec);

create table tbTecnico (
    pkCodTec integer not null,
    nomeTec varchar(50) not null,
    constraint tbTecnico_pkCodTec primary key(pkCodTec)
);

create table tbExamesProntuario (
    pkCodExamPront integer not null,
    fkCodExam integer not null,
    fkCodPront integer not null,
    constraint tbExamesProntuario_pkCodExamPront primary key(pkCodExamPront)
);

alter table tbExamesProntuario add constraint tbExamesProntuario_fkCodExam foreign key(fkCodExam)
    references tbExame(pkCodExam);
alter table tbExamesProntuario add constraint tbExamesProntuario_fkCodPront foreign key(fkCodPront)
    references tbProntuario(pkCodPront);

insert into tbexame(pkCodExam, nomeExam, dataPront, laudoExame, fkCodTec)
    values (1, ‘Eletrocardiograma’, 7, ‘ok’, 1);
insert into tbTecnico(pkCodTec, nomeTec) values (1, 'Gabriel');
savepoint P1;
update tbPaciente p set p.nomePac = ‘teste’ where p.pkCodPac = 20;
savepoint P2;
delete from tbPaciente p where p.pkCodPac = 80;
rollback to savepoint P1;
insert into tbPaciente p (pkCodPac, nomePac, idadePac, emailPac) values (1, ‘Zé’,
55, ‘teste@teste.com.br’);
commit;
