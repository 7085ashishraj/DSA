# Write your MySQL query statement below
select e.name
from employee e
join employee em
on e.id = em.managerId
group by e.id, e.name
having count(em.id) >= 5