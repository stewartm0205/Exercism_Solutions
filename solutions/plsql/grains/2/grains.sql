create or replace function "GRAINS"
(n in NUMBER)
return NUMBER
is
    ng number;
    i number;
begin
    ng := 1;
    i := 1;
    while i < n 
    loop
        ng := ng * 2;
        i := i + 1;
    end loop;
    return ng;
end;

create or replace function "TOTAL_GRAINS"
return NUMBER
is
    ng number;
    tg number;
    i number;
begin
    tg := 0;
    for i in 1..64 
    loop
        ng := grains(i);
        tg := tg + ng;
    end loop;
    return tg;
end;
