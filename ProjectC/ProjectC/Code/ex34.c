#include <stdio.h>
struct student{
	int no;
	float score;
} stu[4]={200801,93,200802,95,200803,92.5,200804,97};
struct data_struct{
	unsigned	var1:1;
	unsigned	var2:1;
	unsigned	var3:1;
	unsigned	var4:5;
	unsigned	var5:5;
	int			var6;
} ds1;
main()
{
	struct student *ps, *find();
	int i,no[3];
	no[0]=200803; no[1]=200806;no[2]=200802;
	for(i=0;i<3;i++)
	{	
		ps=find(no[i]);
		if(ps!=0)		
		printf("No.: %d, Score: %f\n",ps->no,ps->score); 
		else
		printf("Error No.!\n");
	}
	printf("%d \n",sizeof(ds1));
}

struct student *find(int no)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(stu[i].no==no)
		return &stu[i];
	}
	return 0;
}
