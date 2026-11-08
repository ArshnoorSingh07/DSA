# Write your MySQL query statement below
SELECT p.product_id as product_id,
    ROUND(
        IFNULL(SUM(p.price* u.units) / SUM(u.units), 0),
        2
    ) AS Average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP By p.product_id;