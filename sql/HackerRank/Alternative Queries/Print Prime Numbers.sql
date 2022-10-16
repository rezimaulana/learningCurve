with recursive numGen(n) as (
    select
        2
    union
    all
    select
        n + 1
    from
        numGen
    where
        n < 1000
),
doubleLayer(x, y, z) as (
    select
        a.n,
        b.n,
case
            when mod(a.n, b.n) = 0 then 1
            else 0
        end
    from
        numGen a,
        numGen b
    where
        a.n >= b.n
),
primeNum(n) as (
    select
        a.x
    from
        doubleLayer a
    group by
        a.x
    having
        sum(a.z) = 1
)
select
    group_concat(
        n
        order by
            n separator '&'
    )
from
    primeNum;