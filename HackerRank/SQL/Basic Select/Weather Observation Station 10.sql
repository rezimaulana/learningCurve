select
distinct(city)
from station
where
right(city,1) not in ("a","i","u","e","o")