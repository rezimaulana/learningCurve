SELECT c.name
FROM city c
INNER JOIN country co ON co.code = c.countrycode
WHERE co.continent = 'Africa';