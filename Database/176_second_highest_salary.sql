# Write your MySQL query statement below
select (select distinct Salary from Employee where Salary is not null order by Salary desc limit 1,1) as SecondHighestSalary;
