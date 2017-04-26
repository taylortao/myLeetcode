Method 1:
select Score,(select count(distinct s2.Score) from Scores s2 where s2.Score > s1.Score)+1 as Rank from Scores s1 order by Score desc;

Method 2:
set @rk = 0;
set @pv = -0.1;
select Score, Rank from (select Score, @rk := @rk + (Score <> @pv) as Rank, @pv:=Score as Ps from Scores order by Score desc) as RkTable;

Simpler:
select Score, Rank from (select Score, @rk := @rk + (Score <> @pv) as Rank, @pv:=Score as Ps from Scores, (SELECT @rk := 0, @pv := -1) init order by Score desc) as RkTable;

Simpler:
select Score, @rk := @rk + (@pv <> (@pv:=Score)) as Rank from Scores, (SELECT @rk := 0, @pv := -1) init order by Score desc;

