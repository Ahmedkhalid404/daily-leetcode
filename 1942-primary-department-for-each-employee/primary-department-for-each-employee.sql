select 
    e.employee_id ,
    e.department_id 

from Employee e

where e.primary_flag = 'Y' or e.employee_id in (
    select e.employee_id
    from Employee e
    group by 1
    having count(*) = 1
)

group by 1
