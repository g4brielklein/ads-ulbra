create table tbcliente (
  pkcodcli integer not null,
  nomecli varchar(20),
  fonecli varchar(16),
  idadecli integer,
  constraint tbcliente_pk primary key(pkcodcli) 
);

create table tbpertences (
  pkcodpert integer not null,
  descricaopert varchar(30),
  constraint tbpertences_pk primary key(pkcodpert)
);

create table tbproprietario (
  pkcodpro integer not null,
  nomepro varchar(20),
  fonepro varchar(20),
  cidadepro varchar(20),
  numerocontratosativos integer,
  constraint tbproprietario_pk primary key(pkcodpro)
);s

create table tbcontrato (
  pkcodcont integer not null,
  fkcodcli integer,
  fkcodpro integer,
  datacont date,
  datafimcont date,
  valorcont number(15,2),
  logradouroimovel varchar(200),
  statuscont integer,
  constraint tbcontrato_pk primary key(pkcodcont) 
);

alter table tbcontrato add constraint tbcontrato_fk1 foreign key(fkcodcli)
references tbcliente(pkcodcli);

alter table tbcontrato add constraint tbcontrato_fk2 foreign key(fkcodpro)
references tbproprietario(pkcodpro);

create table tbrelcontpert (
  pkrelcontpert integer not null,
  fkcodcont integer,
  fkcodpert integer,
  constraint tbrelcontpert_pk primary key(pkrelcontpert) 
);

alter table tbrelcontpert add constraint tbrelcontpert_fk1 foreign key(fkcodcont)
references tbcontrato(pkcodcont);

alter table tbrelcontpert add constraint tbrelcontpert_fk2 foreign key(fkcodpert)
references tbpertences(pkcodpert);

create or replace
trigger tbcontrato_adiu
after insert or update or delete on tbcontrato
for each row

begin

  if (inserting) and (:new.statuscont=1) then
    update tbproprietario set numerocontratosativos = numerocontratosativos + 1
      where pkcodpro =: new.fkcodpro;
  end if;
  
  if (deleting) and (:old.statuscont=1) then
    update tbproprietario set numerocontratosativos = numerocontratosativos - 1
      where pkcodpro =: old.fkcodpro;
  end if;
  
  
  
  if (updating) then
  
    if (:old.statuscont<>:new.statuscont) then
      if (:old.fkcodpro=:new.fkcodpro) then
        if(:new.statuscont=1) then
          update tbproprietario set numerocontratosativos = numerocontratosativos + 1
            where pkcodpro =: new.fkcodpro;
        else
          update tbproprietario set numerocontratosativos = numerocontratosativos - 1
            where pkcodpro =: new.fkcodpro;
        end if; -- fim do status = 1
      else -- do proprietário
        if(:new.statuscont=1) then
          update tbproprietario set numerocontratosativos = numerocontratosativos + 1
            where pkcodpro =: new.fkcodpro;
        else
          update tbproprietario set numerocontratosativos = numerocontratosativos - 1
            where pkcodpro =: new.fkcodpro;
        end if; -- fim do status = 1
      end if;
      
    end if;
  
  end if;
  
end;





































