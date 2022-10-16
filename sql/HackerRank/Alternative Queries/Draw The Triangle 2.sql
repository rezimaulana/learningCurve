with recursive cte(n) as (
    select
        1
    union
    all
    select
        n + 1
    from
        cte
    limit
        20
)
select
    repeat("* ", n)
from
    cte;