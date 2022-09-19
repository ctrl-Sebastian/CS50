 SELECT title FROM movies WHERE id IN (SELECT DISTINCT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Johnny Depp"))

 INTERSECT

  SELECT title FROM movies WHERE id IN (SELECT DISTINCT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Helena Bonham Carter"));