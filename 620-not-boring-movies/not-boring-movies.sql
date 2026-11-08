# Write your MySQL query statement below
SELECT * 
FROM Cinema
Where mod(id,2)
AND description != 'Boring'
ORDER BY rating DESC;