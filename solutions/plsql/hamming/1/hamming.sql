create or replace function "HAMMING"
(strand1 in VARCHAR2,
strand2 in VARCHAR2)
return NUMBER
is
    dist number;
    i number;
begin
    dbms_output.enable(null);
    if length(strand1) <> length(strand2)
    then 
        return 0;
    end if;
    dist := 0;
    for i in 1..length(strand1) Loop
        dbms_output.put_line('I='||I||','||substr(strand1,i,1)||' '|| substr(strand2,i,1));
        if substr(strand1,i,1) <> substr(strand2,i,1) 
        then

            dist := dist + 1;
        end if;
    end loop;
    return dist;
end;
