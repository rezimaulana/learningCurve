select
    min(start_date) start_date,
    max(end_date) end_date
from (select
        start_date,
        end_date,
        date_sub(start_date,INTERVAL row_number() over (order by start_date) DAY) as tag
    from projects) t
group by tag
order by count(*) asc,start_date;