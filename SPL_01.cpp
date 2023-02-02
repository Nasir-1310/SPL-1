#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
//#define  height_of_projectile(v0,theta,time,aacceleration) ((v0)*sin(theta)*(time)+0.5*(aacceleration)*(time)*(time))
//#define horizontal_distance_of_projectile(v0,theta,time)  (v0*cos(theta)*time)


using namespace std;

//function of the formula to find the height of the projectile
double height_of_projectile(double v0,double theta,double time,double acceleration)
{
   double  height=((v0)*sin(theta)*(time)+(0.5)*(acceleration)*(time)*(time));
    return height;
}

//function of the formula to find horizontal dintance
double horizontal_distance_of_projectile(double v0,double theta,double time)
{
    double horizontal_distance=((v0)*cos(theta)*(time));
    return horizontal_distance;
}
void rotate_triangle(int cx,int cy,int h,int w,int angle)
{
    double theta=(double)(angle%180)*M_PI/180.00;
    int dx=h/2;
    int dy=w/2;
    int point[8]={ (int)(-dx*cos(theta)-dy*sin(theta)+cx),
                            (int)(-dx*sin(theta)+dy*cos(theta)+cy),
                            (int)(dx*cos(theta)-dy*sin(theta)+cx),
                            (int)  (dx*sin(theta)+dy*cos(theta)+cy),

                            (int)(dx*cos(theta)+dy*sin(theta)+cx),
                            (int)(dx*sin(theta)-dy*cos(theta)+cy),
                            (int)(-dx*cos(theta)+dy*sin(theta)+cx),
                            (int) (-dx*sin(theta)-dy*cos(theta)+cy),

                          };
        for(int i=0;i<8;i+=2)
        {
            line(point[i],point[i+1],point[(i+2)/8],point[(i+3)/8]);
        }
}
int main()
{
    printf("                                      ------Welcome to  LearnPhysics game world-------\n");
    printf("                                 ---------------------------------------------------------------\n");

double height,acceleration,time,theta,v0,horizontal_distance;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

      // rotate_triangle(320,240,200,100,50);

      printf("Enter initial velocity  v0\n");
      scanf("%lf",&v0);
      printf("Enter acceleration a\n ");
      scanf("%lf",&acceleration);
      printf("Enter angle with respect to horizontal\n");
      scanf("%lf",&theta);
      theta=theta*M_PI/180;
      printf("Enter starting time t(t>=0)\n");
      scanf("%lf",&time);
      double x=0;
      //moveto(200,300);
     // line(200,300,300,400);
      while(height>=0)
      {
          height=height_of_projectile(v0,theta,time,acceleration);
          horizontal_distance=horizontal_distance_of_projectile(v0,theta,time);
          printf("When time t=%lf then height h =%lf  and horizontal distance x=%lf\n",time,height,horizontal_distance);
          cleardevice();
          moveto(400,400);
          //line(0,0,500,600);
          circle(horizontal_distance+100,height+100,30);
          swapbuffers();
          time+=1.00;
         delay(100);
      }


/*for(int i=100,j=100;i<=600;i++)
{
    cleardevice();
    circle(i,j,60);
    if(j>200)
        j-=2;
    else j++;
    swapbuffers();
    delay(10);
}*/
    getch();
    closegraph();




    return 0;
}

/*
20
-9.8
90
0
*/
