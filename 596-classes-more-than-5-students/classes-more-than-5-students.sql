select 
    c.class     

from Courses c

group by c.class
having count(*) >= 5