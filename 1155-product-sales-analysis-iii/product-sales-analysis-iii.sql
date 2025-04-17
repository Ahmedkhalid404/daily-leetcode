select
    s.product_id ,
    s.year first_year,
    s.quantity  ,
    s.price

from Sales s

where (s.product_id, s.year) in (
    select 
        s.product_id,
        min(s.year)
    from Sales s
    group by 1
)