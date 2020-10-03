create or replace
function exemplo2_if
  (num in integer) return varchar
is
  resp varchar(10);
begin
  if num>0 then
    resp:='Positivo';
  elsif num<0 then
    resp:='Negativo';
  elsif num=0 then
    resp:='Nulo';
  end if;
  return resp;
end exemplo2_if;