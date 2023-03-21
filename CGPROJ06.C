#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
void man();
void mankick();
void anim();
void keeper();
void goal_post();
void start_frame();
void loader();
void end_goal();
void end_save();

void main(){
int gm,gd=DETECT;
int i=355,op,lr;
int poly[]={220,40,425,40,385,5,170,5,220,40};
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
start_frame();
printf("\n\n\n\n\n\n\n\n\n\t\t\t\tPRESS\n");
printf("\t\t\t\t1 to score a goal and \n\t\t\t\t2 to save the goal \n\t\t\t\t");
scanf("%d",&op);
if(op==1){
printf("\n\t\t\t\tChoose the side you want to score\n\t\t\t\tpress 4 for left end and 6 for right end\n\t\t\t\t");
scanf("%d",&lr);
}
loader();
cleardevice();
//spot marking2/*
//circle(310,300,5);
//rectangle(308,298,312,302);
//spot mark end */
goal_post();

setcolor(LIGHTCYAN);
circle(315,i,15);//ball
setfillstyle(SOLID_FILL,LIGHTCYAN);
floodfill(315,i,LIGHTCYAN);

man();
mankick();
anim(op,lr);
if(op==1)
end_goal();
else
end_save();
getch();
}


void anim(int opt,int lrs){
int i=365,j=315,lim=35,ikeep=265,jkeep=265;
//int poly[]={220,40,425,40,385,5,170,5,220,40};
if(opt==2)
lim=65;//limit of ball when save
else
lim=5;//limit of ball when goal
while(i>lim){
goal_post();
/*spot marking2
circle(310,300,5);
rectangle(308,298,312,302);
//spot mark end*/
man();
setcolor(YELLOW);
//keeper start
circle(ikeep,40,12);
line(ikeep,52,jkeep,92);
line(ikeep,65,jkeep-15,75);
line(ikeep,65,jkeep+15,75);
line(ikeep,92,jkeep-15,112);
line(ikeep,92,jkeep+15,112);
ikeep=ikeep+2;
jkeep=jkeep+2;
//keeper end

setcolor(LIGHTCYAN);
circle(j,i,15);//ball
setfillstyle(SOLID_FILL,LIGHTCYAN);
floodfill(j,i,LIGHTCYAN);

if(opt==1){
	i=i-30;
	if(lrs==4){
	j=j-8;
	}
	else
	j=j+5;
	delay(150);
//	if(i==65)
//		delay(200);//last frame
	cleardevice();
	}
else{
	i=i-10;
	delay(40);
	if(i==65)
		delay(500);//for last frame keeper holds the ball
	cleardevice();
	}
}
//getch();
}

void man(){
setcolor(RED);
circle(350,260,15);
line(350,275,350,340);
line(350,290,330,305);
line(350,290,370,305);
line(350,340,370,375);
line(350,340,330,375);//kick00
}


void mankick(){
delay(700);
line(350,340,325,360);//kick01
setcolor(GREEN);
line(350,340,330,375);
delay(200);
line(350,340,325,360);
setcolor(RED);
line(350,340,330,375);
}


void goal_post(){
int poly[]={220,40,425,40,385,5,170,5,220,40};
setbkcolor(GREEN);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(20,40,610,600);//outline
setcolor(BLUE);
drawpoly(5,poly);//goal
setcolor(WHITE);
rectangle(220,40,425,150);//inner box
rectangle(125,40,520,250);//d
arc(325,239,195,345,50);//semi circle
arc(20,43,270,360,14);//left corner arc
arc(607,40,180,270,14);
}

void start_frame(){
setbkcolor(RED);
rectangle(260,125,440,290);
rectangle(170,60,555,115);//title rectangle
settextstyle(10,0,2);
outtextxy(180,63,"LET'S PLAY FOOTBALL");
setfillstyle(SOLID_FILL,WHITE);
floodfill(180,63,WHITE);
rectangle(160,325,565,335);
}

void loader(){
int i=160;
for(i=160;i<=565;i+=2)
{
rectangle(160,325,i,335);
delay(15);
}
}


void end_goal(){
int i=1;
setcolor(WHITE);
setbkcolor(RED);
for(i=1;i<=5;i++){
setbkcolor(RED);
settextstyle(10,0,i);
outtextxy(200,170,"GOAL!!!");
delay(75);
if(i!=5)
cleardevice();
}
}

void end_save(){
int i=1;
setcolor(WHITE);
setbkcolor(RED);
for(i=1;i<=5;i++){
setbkcolor(RED);
settextstyle(10,0,i);
outtextxy(75,170,"SAVED A GOAL!!!");
delay(75);
if(i!=5)
cleardevice();
}
}