SELECT SUM(c.population)
FROM city c
INNER JOIN country co ON co.code = c.countrycode
WHERE co.continent = 'Asia';