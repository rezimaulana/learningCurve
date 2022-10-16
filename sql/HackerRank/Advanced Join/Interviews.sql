select
    c1.contest_id,
    c1.hacker_id,
    c1.name,
    sum(t2.sum_subs) as total_submissions,
    sum(t2.sum_a_subs) as total_accepted_submissions,
    sum(t1.sum_views) as total_views,
    sum(t1.sum_unique_views) as total_unique_views
from
    contests c1
    join colleges c2 on c1.contest_id = c2.contest_id
    join challenges c3 on c2.college_id = c3.college_id
    left join (
        select
            challenge_id,
            sum(total_views) sum_views,
            sum(total_unique_views) sum_unique_views
        from
            view_stats
        group by
            challenge_id
    ) t1 on c3.challenge_id = t1.challenge_id
    left join (
        select
            challenge_id,
            sum(total_submissions) sum_subs,
            sum(total_accepted_submissions) sum_a_subs
        from
            submission_stats
        group by
            challenge_id
    ) t2 on c3.challenge_id = t2.challenge_id
group by
    c1.contest_id,
    c1.hacker_id,
    c1.name
having
    sum(t2.sum_subs) + sum(t2.sum_a_subs) + sum(t1.sum_views) + sum(t1.sum_unique_views) > 0
order by
    c1.contest_id;

    --sql server