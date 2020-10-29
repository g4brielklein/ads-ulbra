create or replace
procedure exemploCur5 (opcao IN integer)
As
 TYPE tipoCADONA IS REF CURSOR;
 cursorDinamico tipoCADONA;
 wcodigo tbproduto.codigo%type;
 wnome tbproduto.nome%type;
 westvalor number;
begin
 if (opcao=1) then
   OPEN cursorDinamico FOR 'SELECT codigo,nome,estoque FROM tbproduto ORDER BY nome';
 Else
   OPEN cursorDinamico FOR 'SELECT codigo,nome,valor FROM tbproduto ORDER BY VALOR';
 end if;
 loop
   dbms_output.put_line('**************************************************');
   fetch cursorDinamico into wcodigo, wnome,westvalor;
   if (not cursorDinamico%found) then
     exit;
   end if;
   dbms_output.put_line('Estou “varrendo” a linha ' || cursorDinamico%rowcount );
   dbms_output.put_line('Código do produto: ' || wcodigo);
   dbms_output.put_line('Nome no produto: ' || wnome);
   if (opcao=1) then
     dbms_output.put_line('Estoque do produto: ' || westvalor);
   else
     dbms_output.put_line('Valor do produto: ' || westvalor);
   end if;
 end loop;
 close cursorDinamico;
end exemploCur5;