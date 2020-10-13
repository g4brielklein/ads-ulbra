create or replace
PROCEDURE TESTEEXCEPTION2
  (v1 in number,
  v2 in number)
IS
  num number;
  excecaoprog exception;
BEGIN
  if v2<v1 then
    RAISE excecaoprog;
  end if;
  for num in v1..v2 loop
    DBMS_OUTPUT.PUT_LINE('Número :'||num);
  end loop;
EXCEPTION
  WHEN excecaoprog THEN
    DBMS_OUTPUT.PUT_LINE('O valor informado como segundo parâmetro é inferior ao primeiro');
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('ERRO = Ocorreu um erro na operação =');
END TESTEEXCEPTION2;