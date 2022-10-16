WITH sub_cnt as (
    SELECT
        submission_date,
        hacker_id,
        COUNT(submission_id) AS sub_n
    FROM
        submissions
    GROUP BY
        submission_date,
        hacker_id
),
max_sub_hacker AS (
    SELECT
        submission_date,
        hacker_id,
        sub_n,
        max_sub_rnk
    FROM
(
            SELECT
                *,
                ROW_NUMBER() OVER (
                    PARTITION BY submission_date
                    ORDER BY
                        sub_n DESC,
                        hacker_id
                ) as max_sub_rnk
            FROM
                sub_cnt
        ) tmp
    WHERE
        max_sub_rnk = 1
),
daily_max_sub_hacker_n AS (
    SELECT
        DISTINCT submission_date,
        COUNT(hacker_id) OVER (PARTITION BY submission_date) as sub_hacker_n
    FROM
(
            SELECT
                submission_date,
                hacker_id,
                sub_n,
                ROW_NUMBER() OVER (
                    PARTITION BY hacker_id
                    ORDER BY
                        submission_date
                ) as date_rnk,
                DATEDIFF(DAY, '2016-03-01', submission_date) + 1 as need_dates
            FROM
                sub_cnt
        ) tmp
    WHERE
        date_rnk = need_dates
)
SELECT
    m.submission_date,
    sub_hacker_n,
    m.hacker_id,
    name
FROM
    max_sub_hacker as m
    INNER JOIN daily_max_sub_hacker_n as d ON (m.submission_date = d.submission_date)
    LEFT JOIN hackers h ON(m.hacker_id = h.hacker_id)

    --ms sol server