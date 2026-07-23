# Write your MySQL query statement below
SELECT * from Cinema  
WHERE description !=  'boring' AND id % 2 = 1
ORDER BY rating desc
