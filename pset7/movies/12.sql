  SELECT title
  FROM movies
  WHERE movies.id IN (
SELECT stars.movie_id
  FROM stars
  WHERE stars.person_id = (SELECT people.id
  FROM people
  WHERE name = "Johnny Depp"))
INTERSECT
  SELECT title
  FROM movies
  WHERE movies.id IN (
SELECT stars.movie_id
  FROM stars
  WHERE stars.person_id = (SELECT people.id
  FROM people
  WHERE name = "Helena Bonham Carter"));

