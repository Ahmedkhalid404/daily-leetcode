select r.contest_id , round(count(r.user_id) / ( select count(*) from Users  ) * 100, 2) percentage 
from Register r
group by r.contest_id 
order by percentage desc , contest_id asc