# Write your MySQL query statement below
SELECT t.unique_id, e.name from Employees e 
    LEFT JOIN EmployeeUNI t ON e.id = t.id;