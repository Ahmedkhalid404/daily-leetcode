select
    em.employee_id,
    em.name,
    count(*) reports_count ,
    round( avg(emp.age) ) average_age 

from Employees em
join Employees emp on em.employee_id = emp.reports_to 

group by em.employee_id

order by em.employee_id