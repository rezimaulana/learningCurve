SELECT
    GROUP_CONCAT(if(occupation = 'doctor', name, NULL)) AS 'doctor',
    GROUP_CONCAT(if(occupation = 'professor', name, NULL)) AS 'professor',
    GROUP_CONCAT(if(occupation = 'singer', name, NULL)) AS 'singer',
    GROUP_CONCAT(if(occupation = 'actor', name, NULL)) AS 'actor'
FROM
    (
        SELECT
            *,
            row_number() OVER(
                PARTITION BY OCCUPATION
                ORDER BY
                    NAME
            ) AS N
        FROM
            OCCUPATIONS
    ) AS ORD
GROUP BY N;