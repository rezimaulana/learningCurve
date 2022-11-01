SELECT
    ID,
    Name,
    SUM(max_score) as total
FROM
    (
        SELECT
            h.hacker_id as ID,
            h.name as Name,
            Max(s.score) as max_score
        FROM
            Hackers h
            JOIN Submissions s ON h.hacker_id = s.hacker_id
        GROUP BY
            h.hacker_id,
            h.name,
            s.challenge_id
    ) as b
GROUP BY
    ID,
    Name
HAVING
    total > 0
ORDER BY
    total DESC,
    ID ASC