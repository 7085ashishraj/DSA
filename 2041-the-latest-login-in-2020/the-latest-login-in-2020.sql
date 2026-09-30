# Write your MySQL query statement below
select user_id as user_id, MAX(time_stamp) as last_stamp
from Logins where YEAR(time_stamp) = '2020' group by 1;