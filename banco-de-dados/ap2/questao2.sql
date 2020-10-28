/*
2) Crie um procedimento que passado o código de uma partida Verifique 
quem é o vencedor Time A ou Time B e altere o atributo Vencedor da tabela 
tbpartida para o nome do time vencedor. 
Caso seja empate, troque o texto do atributo vencedor para “Empate”.
*/
create or replace
procedure evencedor(xpkcodpartida in tbpartida.pkcodpartida%type)
is
 resposta tbpartida.vencedor%type;
 xnumgoltimeA tbpartida.numerogoltimea%type;
 xnumgoltimeB tbpartida.numerogoltimeb%type;
 xfktimeA tbpartida.fktimea%type;
 xfktimeB tbpartida.fktimeb%type;
begin
 resposta:='Empate';
 select fktimea,fktimeb,numerogoltimea, numerogoltimeb 
   into xfktimea,xfktimeb,xnumgoltimeA, xnumgoltimeB  from tbpartida 
    where pkcodpartida=xpkcodpartida;
 if xnumgoltimeA>xnumgoltimeB then
   select nomeclube into resposta from tbclube where pkcodclube=xfktimea;
 end if;
  if xnumgoltimeA<xnumgoltimeB then
   select nomeclube into resposta from tbclube where pkcodclube=xfktimeb;
 end if;
 update tbpartida set vencedor=resposta where pkcodpartida=xpkcodpartida;
 
end evencedor;