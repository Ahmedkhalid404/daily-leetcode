SELECT person_name
FROM (
  SELECT *,
         SUM(weight) OVER (ORDER BY turn) AS cumulative_weight
  FROM Queue
) AS temp
WHERE cumulative_weight <= 1000
ORDER BY turn DESC
LIMIT 1;