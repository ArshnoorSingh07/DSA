# Write your MySQL query statement below
select t1.id from weather t1
    JOIN weather t2
    ON DATEDIFF(t1.recordDate, t2.recordDate) = 1
    where t1.temperature > t2.temperature;