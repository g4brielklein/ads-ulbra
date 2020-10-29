create or replace
PROCEDURE LEGAL
AS
  TYPE tipoCursor IS REF CURSOR;
  cursorDinamico tipoCursor;
  CURSOR LISTACLUBE IS SELECT C.PKCODCLUBE, C.NOMECLUBE, COUNT(*) AS QUANTIDADE  FROM TBCLUBE C
                       LEFT JOIN TBATLETA A ON A.FKCLUBE=C.PKCODCLUBE
                       GROUP BY C.PKCODCLUBE, C.NOMECLUBE;
  XPKCODCLUBE TBCLUBE.PKCODCLUBE%TYPE;
  XNOMECLUBE  TBCLUBE.NOMECLUBE%TYPE;
  XQUANTIDADE INTEGER; 
  xnomeAtleta tbatleta.nomeatleta%type;
BEGIN
 open LISTACLUBE;
 loop    
    fetch LISTACLUBE into XPKCODCLUBE,XNOMECLUBE,XQUANTIDADE;
    exit when LISTACLUBE%NOTFOUND=true; --condição de saída do laço loop   
    DBMS_OUTPUT.PUT_LINE('=====================================');
    DBMS_OUTPUT.PUT_LINE('nome do clube :'||XNOMECLUBE);
    DBMS_OUTPUT.PUT_LINE('Número de Atletas :'||XQUANTIDADE);
    OPEN cursorDinamico FOR 'SELECT NOMEATLETA FROM TBATLETA WHERE FKCLUBE='||XPKCODCLUBE;
    loop
      fetch cursorDinamico into xnomeAtleta;
      exit when cursorDinamico%NOTFOUND=true;
      DBMS_OUTPUT.PUT_LINE('Atleta :'||xnomeAtleta);
    end loop;
    close cursorDinamico;
 end loop;
 close LISTACLUBE;

END LEGAL;