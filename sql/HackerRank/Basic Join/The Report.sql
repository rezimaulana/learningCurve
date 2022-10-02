SELECT
    CASE
        WHEN b.GRADE < 8 THEN NULL
        ELSE a.NAME
    END,
    b.GRADE,
    a.MARKS
FROM
    Students a
    INNER JOIN Grades b ON a.MARKS BETWEEN b.MIN_MARK
    AND B.MAX_MARK
ORDER BY
    b.GRADE DESC,
    a.NAME,
    a.MARKS;