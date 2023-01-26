#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>


using namespace std;
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
    printf("                                 ---------------------------------------------------------------");

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
  //  circle(100,100,50);
    //moveto(100,100);
    //moveto(100,100);
   // lineto(100,200);
    //lineto(300,444);
    //line(0,0,600,100);
       // rectangle(10,10,600,450);
       rotate_triangle(320,240,200,100,50);



    getch();
    closegraph();




    return 0;
}
