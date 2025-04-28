with last_updated as (
    select 
        product_id,
        new_price price,
        change_date

    from products
    where (product_id,change_date) in (
        select 
            product_id,
            max(change_date)
        from products
        where change_date <= '2019-08-16'
        group by product_id
    ) 
)

select 
    p2.product_id,
    ifnull(p1.price, 10) price

from last_updated p1
right join (select distinct product_id from products) p2 on p1.product_id = p2.product_id


