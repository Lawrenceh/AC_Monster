bool Swap2Balance(int *pa, int *pb, int n)
{
	int suma=0,sumb=0;
	for (int i=0;i<n;i++)
	{
		suma+=pa[i];
		sumb+=pb[i];
	}

	int diff=suma-sumb;
	while (diff!=0)
	{
		int besti=0,bestj=0;
		int bestchange=0;
		for(int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				int change=(pa[i]-pb[j]);
				//?????(suma-pa[i]+pb[j])-(sumb+pa[i]-pb[j])=diff-2*change
				if (abs(diff-2*change)<abs(diff-2*bestchange))
				{
					bestchange=change;
					besti=i;
					bestj=j;
				}
			}

		if (bestchange==0)	//??????
			return false;
		int temp=pa[besti];
		pa[besti]=pb[bestj];
		pb[bestj]=temp;

		suma-=bestchange;
		sumb+=bestchange;
		diff=suma-sumb;

	}
	return true;
}
