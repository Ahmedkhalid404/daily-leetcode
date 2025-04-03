select 
(ROUND (sum(CASE WHEN order_date=customer_pref_delivery_date THEN 1 ELSE 0 END) / count(*) , 4) * 100)  immediate_percentage 
from Delivery where (customer_id, order_date) in (select customer_id, min(order_date) from Delivery group by customer_id);