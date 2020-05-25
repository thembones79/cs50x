SELECT DISTINCT(name)
FROM people
WHERE name
IS NOT "Kevin Bacon" AND id IN
(SELECT person_id
FROM stars
WHERE movie_id IN
(SELECT movie_id
FROM stars
Where person_id IN
(SELECT id
FROM people
WHERE name = "Kevin Bacon" AND birth = 1958)));
