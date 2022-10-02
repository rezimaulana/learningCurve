select
    s.hacker_id,
    h.name
from
    submissions AS s,
    difficulty AS d,
    challenges AS c,
    hackers AS h
where
    s.challenge_id = c.challenge_id
    and c.difficulty_level = d.difficulty_level
    and s.score = d.score
    and h.hacker_id = s.hacker_id
group by
    s.hacker_id,
    h.name
having
    count(submission_id) > 1
order by
    count(submission_id) desc,
    hacker_id;