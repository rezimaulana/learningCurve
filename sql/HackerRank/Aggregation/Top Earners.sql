select
    max(months * salary),
    count(employee_id)
from
    Employee
group by
    (months * salary)
order by
    (months * salary) desc
limit
    1;