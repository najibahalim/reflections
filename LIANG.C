#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int gd=DETECT,gm=0;
	int x1,y1,x2,y2,xmin,ymin,xmax,ymax,x11,x21,y11,y21,i;
	float t1,t2,p[4],q[4],temp;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter line co-ordinates (x1,y1) & (x2,y2)");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	printf("Enter window co-ordinates (xwmin,ywmin) & (xwmax,ywmax)");
	scanf("%d %d %d %d",&xmin,&ymin,&xmax,&ymax);
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	rectangle(xmin,ymin+250,xmax,ymax+250);

	p[0]=-(x2-x1);
	p[1]=(x2-x1);
	p[2]=-(y2-y1);
	p[3]=(y2-y1);

	q[0]=(x1-xmin);
	q[1]=(xmax-x1);
	q[2]=(y1-ymin);
	q[3]=(ymax-y1);

	for(i=0;i<4;i++)
	{
		if(p[i]==0)
		{
			printf("Line is parallel to one clipping boundry\n");
			if(q[i]>=0)
			{
				if(i<2)
				{
					if(y1<ymin)
					y1=ymin;

					if(y2>ymax)
					y2=ymax;

					line(x1,y1+250,x2,y2+250);
				}
				if(i>1)
				{
					if(x1<xmin)
						x1=xmin;

					if(x2>xmax)
					x2=xmax;

					line(x1,y1+250,x2,y2+250);
				}
			}
		}
	}
	t1=0;
	t2=1;
	for(i=0;i<4;i++)
	{
		temp=q[i]/p[i];
		if(p[i]<0)
		{
			if(t1<=temp)
			t1=temp;
		}
		else
		{
			if(t2>temp)
			t2=temp;
		}
	}
	if(t1<t2)
	{
		x11=x1+t1*p[1];
		x21=x1+t2*p[1];
		y11=y1+t1*p[3];
		y21=y1+t2*p[3];
		line(x11,y11+250,x21,y21+250);
	}
	getch();


}

