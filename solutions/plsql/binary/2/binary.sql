create or replace function "BIN_TO_DEC"
(binnum in VARCHAR2)
return NUMBER
is
    bn varchar2(32);
    b varchar2(1);
    dnum number;
    n number;
begin
    dnum := 0;
    bn := binnum;
    n  := 1;
    while (length(bn)>=1)
    loop
        b := substr(bn,length(bn),1);    
        bn := substr(bn,1,length(bn)-1);
        if b = '1'
        then 
            dnum := dnum + power(2,n-1);
        elsif b = '0' 
        then 
            dnum := dnum + 0;
        else
            dnum := 0;
            exit;
        end if;
        n := n + 1;
    end loop;
    return dnum;
end;

