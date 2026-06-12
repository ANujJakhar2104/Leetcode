# Write your MySQL query statement below
with final as (
    select country ,state , amount ,
    DATE_FORMAT(trans_date, '%Y-%m') AS month
    from Transactions
)

select month , country ,
count(amount) as trans_count,
sum(case when state = 'approved' then 1 else 0 end) as approved_count,
sum(amount) as trans_total_amount, 
sum(case when state = 'approved' then amount else 0 end) as approved_total_amount
from final
group by month , country;