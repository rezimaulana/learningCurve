select
    s.name
from
    students s
    join (
        select
            temp1.st1 as idd
        from
            (
                select
                    f.id as st1,
                    p.salary as sl1,
                    row_number() over(
                        order by
                            f.id
                    ) as rn2
                from
                    packages p
                    join friends f on f.id = p.id
            ) as temp1
            join (
                select
                    f.friend_id as st2,
                    p.salary as sl2,
                    row_number() over(
                        order by
                            f.id
                    ) as rn1
                from
                    packages p
                    join friends f on f.friend_id = p.id
            ) as temp2 on temp1.rn2 = temp2.rn1
        where
            temp2.sl2 > temp1.sl1
    ) as temp3 on s.id = temp3.idd
    join friends ff on s.id = ff.id
    join packages pp on ff.friend_id = pp.id
order by
    pp.salary;