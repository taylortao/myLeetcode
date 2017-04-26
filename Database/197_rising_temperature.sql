Simple:
select w1.Id as Id from Weather w1 , Weather w2 where w1.Temperature > w2.Temperature and To_Days(w1.Date) - To_Days(w2.Date) =1

Complicated:
select Id from (select Id, Date_Add(Date, Interval -1 day) as tyd, @pv as yt, @pv:=Temperature as tt, @dt as yd, @dt:=Date as td from Weather, (select @pv:=1000, @dt:='0-0-0') init order by Date) as weathertable where tyd=yd and tt > yt;