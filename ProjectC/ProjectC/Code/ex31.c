#include <stdio.h>
main()
{
	int i;	
	struct date{
	int	year;
	int	month;
	int day;
	};
	struct date *pdate, days[2];
	days[0].year=2008;
	days[0].month=2;
	days[0].day=15;
	days[1].year=2007;
	days[1].month=9;
	days[1].day=14;
	for(i=0;i<2;i++)
	{
		pdate=&days[i];
		printf("year %d ,month %d, day %d\n", pdate->year,pdate->month,pdate->day);
	}
}
