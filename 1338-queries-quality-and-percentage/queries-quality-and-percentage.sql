select 
q.query_name ,
round(sum(q.rating / q.position) / count(*), 2) quality ,
round(count(case when q.rating < 3 then 1 end) / count(*) * 100, 2) poor_query_percentage 

from Queries q
group by q.query_name