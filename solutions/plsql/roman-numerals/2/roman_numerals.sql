create or replace function "ROMAN_NUMERALS"
(n in NUMBER)
return VARCHAR2
is
    dnum number;
    rnum varchar2(100) := null;
begin
    dnum := n;
    if dnum >= 1000
    then
        rnum := rpad('M',floor(dnum/1000),'M');
        dnum := mod(dnum,1000);
    end if;
    if dnum >= 900
    then
        rnum := rnum || 'CM';
        dnum := dnum - 900;
    end if;
    if dnum >= 500
    then
        rnum := rnum || 'D';
        dnum := dnum - 500;
    end if;
    if dnum >= 400
    then
        rnum := rnum || 'CD';
        dnum := dnum - 400;
    end if;
    if dnum >= 100
    then
        rnum := rnum || rpad('C',floor(dnum/100),'C');
        dnum := mod(dnum,100);
    end if;
    if dnum >= 90
    then
        rnum := rnum || 'XC';
        dnum := dnum - 90;
    end if;
    if dnum >= 50
    then
        rnum := rnum || 'L';
        dnum := dnum - 50;
    end if;
    if dnum >= 40
    then
        rnum := rnum || 'XL';
        dnum := dnum - 40;
    end if;
    if dnum >= 10
    then
        rnum := rnum || rpad('X',floor(dnum/10),'X');
        dnum := mod(dnum,10);
    end if;
    if dnum >= 9
    then
        rnum := rnum || 'IX';
        dnum := dnum - 9;
    end if;
    if dnum >= 5
    then
        rnum := rnum || 'V';
        dnum := dnum - 5;
    end if;
    if dnum = 4
    then
        rnum := rnum || 'IV';
        dnum := dnum - 4;
    end if;
    if dnum >= 1
    then
        rnum := rnum || rpad('I',dnum,'I');
    end if;
    return rnum;
end;
