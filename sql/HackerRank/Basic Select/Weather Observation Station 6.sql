select
DISTINCT(city)
from station
where
SUBSTRING(city,1,1) = "a"
or SUBSTRING(city,1,1) = "i"
or SUBSTRING(city,1,1) = "u"
or SUBSTRING(city,1,1) = "e"
or SUBSTRING(city,1,1) = "o"