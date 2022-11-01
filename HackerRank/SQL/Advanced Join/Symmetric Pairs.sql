select
    x,
    y
from
    (
        select
            f1.x as x,
            f1.y as y,
            count(*) as cnt
        from
            Functions f1
        where
            exists (
                select
                    *
                from
                    Functions f2
                where
                    f1.x = f2.y
                    and f1.y = f2.x
                    and (
                        f1.x < f2.x
                        or f1.x = f1.y
                    )
            )
        group by
            f1.x,
            f1.y
        order by
            f1.x
    ) as s
where
    x <> y
    or cnt = 2