SELECT 
    o.customer_id, 
    SUM(o.order_volume) AS num_products_ordered
FROM 
    orders o
GROUP BY 
    o.customer_id
ORDER BY 
    o.customer_id ASC;
