SELECT DISTINCT name
FROM stars join people ON stars.person_id = people.id
WHERE movie_id IN
(SELECT movie_id
FROM people JOIN stars ON stars.person_id = people.id
WHERE birth = 1958 AND name = "Kevin Bacon")
AND NAME != "Kevin Bacon";