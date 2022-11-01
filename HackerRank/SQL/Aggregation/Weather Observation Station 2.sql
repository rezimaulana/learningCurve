select
    concat(
        round(sum(lat_n), 2),
        ' ',
(
            select
                round(sum(long_w), 2)
            from
                station
        )
    )
from
    station;