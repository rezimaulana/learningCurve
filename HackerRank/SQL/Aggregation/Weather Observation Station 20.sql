select
    round(ranks.lat_n, 4)
from
(
        select
            lat_n,
            rank() over (
                order by
                    lat_n
            ) as lat_rank
        from
            station
    ) as ranks
where
    ranks.lat_rank =(
        select
            round(count(*) / 2, 0)
        from
            station
    );