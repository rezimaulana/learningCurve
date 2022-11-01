select
DISTINCT(city)
from station
where
RIGHT(city,1) = "a"
or RIGHT(city,1) = "i"
or RIGHT(city,1) = "u"
or RIGHT(city,1) = "e"
or RIGHT(city,1) = "o"