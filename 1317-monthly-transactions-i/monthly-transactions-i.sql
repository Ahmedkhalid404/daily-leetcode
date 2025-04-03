select 
DATE_FORMAT(t.trans_date, '%Y-%m') month, 
t.country , 
count(*) trans_count,
count(case when t.state = 'approved' then 1 end) approved_count ,
sum(t.amount) trans_total_amount ,
sum(case when t.state = 'approved' then t.amount else 0 end) approved_total_amount 

from Transactions t
group by DATE_FORMAT(t.trans_date, '%Y-%m') , t.country