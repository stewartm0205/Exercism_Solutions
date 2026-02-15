create or replace function "RAINDROPS"
(n in NUMBER)
return VARCHAR2
is
    raindrop varchar2(100) := null;
begin
    if mod(n,3) = 0
    then
        raindrop := 'Pling';
    end if;
    if mod(n,5) = 0
    then
        raindrop := raindrop || 'Plang';
    end if;
    if mod(n,7) = 0
    then
        raindrop := raindrop || 'Plong';
    end if;
    if raindrop is null
    then 
        raindrop := to_char(n, '99999');
    end if;
    return raindrop;
end;

