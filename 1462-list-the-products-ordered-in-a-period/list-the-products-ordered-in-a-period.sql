# Write your MySQL query statement below
select p.product_name, sum(unit) as unit
from products p
join orders od on
p.product_id = od.product_id
where year(order_date) = 2020 and month(order_date) = 2
group  by p.product_name
having sum(unit) > 99
