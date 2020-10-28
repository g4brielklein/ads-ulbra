/*
3) Crie um procedimento que passado o código da partida (fkcodpartida) 
o código do Atleta (fkcodAtleta) e o código do clube (fkcodclube) 
realize a seguintes Rotinas:

Inserir um novo registro na tabela Tbgol (chamando função para código da 
tarefa 1)
Verificar se o código do clube passado como parâmetro é o fktimeA ou fktimeB. Dependendo da Resposta incremente o atributo numerogoltimeA ou numerogoltimeB  da tabela de partida
Chame o procedimento criado no exercício 2.
Incremente mais um gol para o Atleta passado como parâmetro
Imprima em tela o nome do Atleta que fez o Gol e o número que gols que o 
mesmo já fez
Imprima o nome do time que se refere o Gol(não esqueça que deve ser o 
time passado como parâmetro e não o time do atleta, pois o gol pode ser 
contra seu próprio time)
*/
create or replace
procedure verificagol(xfkcodpartida in tbpartida.pkcodpartida%type,
 xfkcodAtleta in tbatleta.pkcodatleta%Type, xfkcodclube in tbclube.pkcodclube%Type)
is
  xproximo integer;
  xnomeatleta tbatleta.nomeatleta%type;
  xnumerogolmarcadoatleta tbatleta.numerogolmarcadoatleta%type;
  xnomeclube tbclube.nomeclube%type;
begin
 xproximo:=proximocod('TBGOL');
 insert into tbgol(pkcodgol,fkcodclube,fkcodpartida, fkcodatleta) values (xproximo,xfkcodclube,xfkcodpartida,xfkcodatleta);
 update tbpartida set numerogoltimeA=numerogoltimeA+1 where pkcodpartida=xfkcodpartida  and fktimea=xfkcodclube;
 update tbpartida set numerogoltimeB=numerogoltimeB+1 where pkcodpartida=xfkcodpartida  and fktimeb=xfkcodclube;
 evencedor(xfkcodpartida);
 update tbatleta set numerogolmarcadoatleta=numerogolmarcadoatleta+1 where pkcodatleta=xfkcodAtleta;
 select nomeatleta,numerogolmarcadoatleta into xnomeatleta,xnumerogolmarcadoatleta from tbatleta where pkcodatleta=xfkcodAtleta;
 DBMS_OUTPUT.PUT_LINE('==== GGGGOOOOOOOOLLLLLLLLLL =======');
 DBMS_OUTPUT.PUT_LINE(' Atleta que marcou :'||xnomeatleta);
 DBMS_OUTPUT.PUT_LINE(' Ele já marcou em sua carreira :'||xnumerogolmarcadoatleta||' gols');
 select nomeclube into xnomeclube from tbclube where pkcodclube=xfkcodclube;
 DBMS_OUTPUT.PUT_LINE(' Clube que marcou gol :'||xnomeclube);

end verificagol;