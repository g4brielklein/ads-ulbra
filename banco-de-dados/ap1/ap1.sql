create table tbOs (
    pkNumOs integer not null,
    dataOs date not null,
    fkCodCli integer not null,
    fkCodEquip integer not null,
    fkCodProd integer not null,
    valorTotalOs float not null default 0 constraint check_valorTotalOs check(valorTotalOs >= 0),
    constraint tbOs_pkNumOs primary key(pkNumOs)
);

alter table tbOs add constraint tbOs_fkCodCli foreign key(fkCodCli)
    references tbCliente(pkCodCli);
alter table tbOs add constraint tbOs_fkCodEquip foreign key(fkCodEquip)
    references tbEquipamento(pkCodEquip);
alter table tbOs add constraint tbOs_fkCodProd foreign key(fkCodProd)
    references tbProduto(pkCodProd);

create table tbCliente (
    pkCodCli integer not null,
    nomeCli varchar(50) not null,
    emailCli varchar(100) not null unique,
    foneCli varchar(20) not null,
    constraint tbCliente_pkCodCli primary key(pkCodCli)
);

create table tbEquipamento (
    pkCodEquip integer not null,
    nomeEquip varchar(50) not null,
    numSerieEquip integer not null unique,
    marcaEquip varchar(50) not null unique,
    potenciaEquip varchar(10),
    anoFabEquip integer not null,
    constraint tbEquipamento_pkCodEquip primary key(pkCodEquip)
);

create table tbProduto (
    pkCodProd integer not null,
    nomeProd varchar(50) not null,
    qtdProd integer not null,
    valorUnProd float not null,
    desconto integer constraint check_desconto check(desconto >= 0 and desconto <= 99),
    constraint tbProduto_pkCodProd primary key(pkCodProd)
);