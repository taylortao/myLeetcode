select d.Name as Department, e.Name as Employee, o.Salary as Salary from (select Id, DepartmentId, Salary from (select Id, DepartmentId, Salary, @rk:=(DepartmentId=@dp)*(@rk+(@pv<>(@pv:=Salary))) as Rank, @dp:=DepartmentId as DepartmentId2 from Employee, (select @rk:=0, @dp:=-1, @pv:=-1) init order by DepartmentId, Salary desc) as od where Rank<3) o, Department d, Employee e where d.Id=o.DepartmentId and e.Id=o.Id order by Department, Salary desc;