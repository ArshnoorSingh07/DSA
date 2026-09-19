# Write your MySQL query statement below
SELECT p.product_id, 
    ROUND(
        IFNULL(SUM(p.price * u.units) / SUM(u.units), 0),
    2) as average_price
    FROM prices p
    LEFT JOIN unitsSold u
    ON p.product_id = u.product_id
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
    GROUP BY p.product_id;