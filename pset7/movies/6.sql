SELECT AVG(rating)
FROM ratings JOIN movies ON movies.id = ratings.movie_id
WHERE year = 2012;

-- Joining the tables ratings and movies on the movie_id;
