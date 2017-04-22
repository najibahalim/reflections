#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int xmin,xmax,ymin,ymax,x1,x2,y1,y2,i,x11,x12,y11,y12;
	float temp,p[4],q[4],t1=0,t2=1;
	int gd=DETECT,gm=0;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter window co-ordinates ");
	scanf("%d %d %d %d",&xmin,&ymin,&xmax,&ymax);
	printf("Enter line co-ordinates ");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	rectangle(xmin+250,ymin,xmax+250,ymax);
	p[0]=-(x2-x1);
	p[1]=(x2-x1);
	p[2]=-(y2-y1);
	p[3]=(y2-y1);
	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;

	for(i=0;i<4;i++)
	{
		if(p[i]==0)
		{
			printf("Line is parallel to %dth boundry ",i);
			if(q[i]>=0)
			{
				if(i<2)
				{
					if(y1<ymin)
					y1=ymin;
					if(y2>ymax)
					y2=ymax;
					line(x1+250,y1,x2+250,y2);
					getch();
					return;
				}
				if(i>1)
				{
					if(x1<xmin)
					x1=xmin;
					if(x2>xmax)
					x2=xmax;
					line(x1+250,y1,x2+250,y2);
					getch();
					return;
				}
			}
		}
	}

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
		x12=x1+t2*p[1];
		y11=y1+t1*p[3];
		y12=y1+t2*p[3];
		line(x1+250,y1,x2+250,y2);
	}
	getch();
}