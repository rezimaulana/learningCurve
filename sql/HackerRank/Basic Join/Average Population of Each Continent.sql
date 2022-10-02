SELECT co.continent, FLOOR(AVG(c.population))
FROM country co
INNER JOIN city c ON co.code = c.countrycode
GROUP BY co.continent;