select
    b.n,
    case
        when b.p is not null then case
            when (
                select
                    count(*)
                from
                    bst
                where
                    p = b.n
            ) = 0 then 'Leaf'
            else 'Inner'
        end
        else 'Root'
    end
from
    bst b
order by
    b.n;