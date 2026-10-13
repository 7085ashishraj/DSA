# Write your MySQL query statement below
Select employee_id , salary as bonus
From Employees where mod(employee_id, 2) != 0 AND name not like
'M%' union select employee_id, 0 as bonus From employees where mod(employee_id, 2) = 0 or name like 'M%' order by employee_id;