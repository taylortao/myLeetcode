var maxProfit = function(k, prices) {
	if (k === 0)
	{
		return 0;
	}
	
	var d = [];
	var mp = 0;
	for (var i=1; i<prices.length; i++)
	{
		d[i-1] =  prices[i] - prices[i-1]
		if (d[i-1] > 0)
		{
			mp += d[i-1];
		}
	}
	
    if (k * 2 >= prices.length)
	{
		return mp;
	}
	
	var l=[], g=[];
	for (var i=0; i<k; i++)
	{
		l[i] = [];
		g[i] = [];
	}
	
	for (var ki=0; ki<k; ki++)
	{
		l[ki][0] = d[0];
		g[ki][0] = max(d[0], 0);
		for (var i=1; i<d.length; i++)
		{
			l[ki][i] = max(l[ki][i-1] + d[i], (ki > 0 ? g[ki-1][i-1] + d[i] : d[i]));
			g[ki][i] = max(g[ki][i-1], l[ki][i]);
		}
	}
	
	return g[k-1][d.length - 1];
};

var max = function (a, b) {
	return a > b ? a : b;
}