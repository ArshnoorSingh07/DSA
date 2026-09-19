# Write your MySQL query statement below
Select p.product_name, s.year, s.price 
    From sales s inner Join product p
    on s.product_id = p.product_id;