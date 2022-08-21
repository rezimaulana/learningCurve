select
city
from station
where id % 2 =0
group by city