create or replace
procedure exemplo_teste
as
  cursor cadona is select nome,estoque from  tbproduto ;
  xnome tbproduto.nome%type;
  xestoque tbproduto.estoque%type;
begin
  open cadona;
  loop    
    fetch cadona into xnome,xestoque;
    exit when cadona%NOTFOUND=true; --condição de saída do laço loop
    DBMS_OUTPUT.PUT_LINE('Registro nº:'||cadona%ROWCOUNT);
    DBMS_OUTPUT.PUT_LINE('nome do produto encontrado :'||xnome);
    DBMS_OUTPUT.PUT_LINE('Estoque do produto encontrado :'||xestoque);
  end loop;
  
  close cadona;
end exemplo_teste;