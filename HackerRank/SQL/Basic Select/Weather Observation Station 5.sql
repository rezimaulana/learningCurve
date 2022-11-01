select city, length(city) from station
order by length(city),city asc
limit 1;
select city, length(city) from station
order by length(city) desc
limit 1;

select DISTINCT(city), LENGTH(city)
from station
order by LENGTH(city) asc
limit 1;
select DISTINCT(city), LENGTH(city)
from station
order by LENGTH(city) desc
limit 1;