create or replace
function proximocodigo
  (tabela in varchar) return integer
is
  prox integer;
begin
  if (upper(tabela) = 'tbcliente') then
    select max(cli.pkcodcli) into prox from tbcliente cli;
    prox:=prox+1;
  end if;
  if (upper(tabela) = 'tbcobertura') then
    select max (cob.pkcodcobert) into prox from tbcobertura cob;
    end if;
  if (upper(tabela) = 'tbveiculo') then
    select max (vei.pkcodvei) into prox from tbveiculo vei;
    prox:=prox+1;
  end if;
  if (upper(tabela) = 'tbapolice') then
    select max (apo.pknumapolice) into prox from tbapolice apo;
    prox:=prox+1;
  end if;
  if (upper(tabela) = 'tbitenscobertura') then
    select max (itens.pkitens) into prox from tbitenscobertura itens;
    prox:=prox+1;
  end if;
  if (upper(tabela) = 'tbparcela') then
    select max (par.pkcodparcela) into prox from tbparcela par;
    prox:=prox+1;
  end if;
  return (prox);
end proximocodigo;