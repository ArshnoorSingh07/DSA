# Write your MySQL query statement below
SELECT emp.unique_id as unique_id, e.name 
    FROM Employees e LEFT JOIN EmployeeUNI emp
    ON e.id = emp.id;