SELECT name
FROM people
WHERE id IN (
SELECT DISTINCT person_id
FROM directors
  JOIN movies ON directors.movie_id = movies.id
 JOIN ratings ON ratings.movie_id = movies.id
WHERE rating >= 9.0);