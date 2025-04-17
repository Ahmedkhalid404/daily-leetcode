select 
    a.activity_date day,
    count(distinct a.user_id) active_users 
from Activity a

where a.activity_date >= '2019-06-28' and a.activity_date <= '2019-07-27'

group by a.activity_date 