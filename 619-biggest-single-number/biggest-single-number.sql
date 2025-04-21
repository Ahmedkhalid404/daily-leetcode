select max(num) num

from (
    select m.num
    from MyNumbers m
    group by num
    having count(*) = 1
) m