SELECT
    Wands.id,
    Wands_Property.age,
    Wands.coins_needed,
    Wands.power
FROM
    Wands
JOIN Wands_Property ON Wands_Property.code = Wands.code
WHERE
    Wands_Property.is_evil = 0   
    AND
    Wands.coins_needed IN 
    (SELECT 
        MIN(Wands.coins_needed)
     FROM 
        Wands
     WHERE
        Wands.code = Wands_property.code
     GROUP BY Wands.power)
ORDER BY Wands.power DESC, Wands_Property.age DESC