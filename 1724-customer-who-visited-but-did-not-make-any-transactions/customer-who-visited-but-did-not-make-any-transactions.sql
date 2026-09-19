# Write your MySQL query statement below
select v.customer_id, count(*) as count_no_trans
    FROM Visits v left join transactions t
    on v.visit_id = t.visit_id 
    where t.transaction_id is null
    Group by v.customer_id;