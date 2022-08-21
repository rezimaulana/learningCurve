select
DISTINCT(city)
from station
where
LEFT(city,1) not in ("a","i","u","e","o")