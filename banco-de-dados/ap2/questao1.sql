/*
1)  Crie uma Função que passado o nome da tabela sempre retorne o 
próximo código que corresponde a chave primária da tabela.
*/
create or replace
function proximocod(xnometabela varchar) return integer
is
 resposta integer;
begin  
  if xnometabela='TBATLETA' THEN
    select NVL(max(pkcodatleta),0) into resposta from tbatleta;
  elsif xnometabela='TBCLUBE' THEN
    select NVL(max(PKCODCLUBE),0) into resposta from TBCLUBE;    
  elsif xnometabela='TBGOL' THEN
    select NVL(max(PKCODGOL),0) into resposta from TBGOL;    
  elsif xnometabela='TBPARTIDA' THEN
    select NVL(max(PKCODPARTIDA),0) into resposta from TBPARTIDA;    
  ELSE
   resposta:=0;
  END IF;
  resposta:=resposta+1;
  return resposta;
end proximocod;