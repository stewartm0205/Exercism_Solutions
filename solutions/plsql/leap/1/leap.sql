create or replace function "ISLEAP"
(year in NUMBER)
return VarChar2
is
begin
   if mod(year, 400) = 0 or (not (mod(year, 100) = 0) and mod(year,4) = 0)
   then
       return 'Y';
   else
       return 'N';
   end if;
end;

