select hacker_id, name, cnt
from (
    select a.hacker_id, h.name, a.cnt,
    count(h.name) over(partition by a.cnt) cnt2,
    max(a.cnt) over() mx
    from (
        select hacker_id, count(challenge_id) cnt
        from challenges
        group by hacker_id
    ) a, hackers h
    where a.hacker_id = h.hacker_id
    order by a.cnt desc, hacker_id
)
where not (cnt < mx and cnt2 > 1);

--oracle