CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE k int;
  SET K = n-1;
  RETURN (
      SELECT DISTINCT Salary FROM Employee WHERE Salary IS NOT NULL ORDER BY Salary DESC LIMIT k, 1
  );
END
