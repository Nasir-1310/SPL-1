#include<bits/stdc++.h>
using namespace std;

#define originX 50
#define originY  500
#define MAX_Time 999
#define time_increment 0.1

double Hmax,H,Rmax,g=-1,Tmax,alpha,v0,R,t,Vt=-1;
int choice,known,operation;
char str_v0[20];


double Tmaximum(double v0,double alpha,double g);
double Rmaximum(double v0,double alpha,double g);
double Hmaximum(double v0,double alpha,double g);
void   projectile_graph(double v0,double alpha,double g);
double Veclocity_at_time_t(double v0,double alpha,double g,double t);







void projectile_Motion()
{
    start_here:
    print_Structure("Welcome to Dynamics world here you will find solution of your desire problem with visualization","  ");
    print_Structure("Enter number of known parameter","1)Velocity(m/s) 2)Angle(with respect to Horizontal(Degree)) 3)Time(Second) 4)Gravitational Acceleration(m/s)");
    int Number_of_parameter = 0;
 //   double Hmax,H,Rmax,g=-1,Tmax,alpha,v0,R,t,Vt=-1;
     H=alpha=v0=R=Hmax=Rmax=Tmax=t=-1;
  //  int choice,known;
 // freopen("projectile.txt","r",stdin);

    scanf("%d",&Number_of_parameter);
    known=Number_of_parameter;
    if(known<1 || known>4)
    {
        cin.ignore();
        cout<<"Enter a valid number :\n";
        goto start_here;
    }
    while(known--)
    {
        if(v0==-1)
            print_Structure("1. Initial velocity(m/s)","Press 1");
        if(alpha==-1)
            print_Structure("2. Angle(with respect to horizontal(Degree))","Press 2");
        if(t==-1)
            print_Structure("3. Time(Second)","Press 3");
        if(g==-1)
        {
            print_Structure("4. Gravitational Acceleration(m/s^2)","Press 4");
        }

        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter Initial velocity(m/s)\n");
            scanf("%lf",&v0);
            sprintf(str_v0, "%.1f m/s", v0);

        }

        else if(choice==2)
        {
            printf("Enter angle with respect to Horizontal(Degree)\n");
            scanf("%lf",&alpha);
            alpha=(M_PI*alpha)/180;
        }
        else if(choice==3)
        {
            printf("Enter time in which you want to see velocity(Second)\n ");
            scanf("%lf",&t);
        }
        else if(choice==4)
        {
            printf("Enter Gravitational Acceleration(m/s^2)\n");
            scanf("%lf",&g);
        }
    else
    {
        printf("Invalid choice! please try again\n");
        cin.ignore();
    }


    }
    printf("What do you want to determine\n");
    print_Structure("1. Maximum horizontal Range(Rmax)","Press 1");
    print_Structure("2. Maximum Height(Hmax)","Press 2");
    print_Structure("3. Time to reach Maximum height(Tmax)","Press 3");
    print_Structure("4. Total Time(2Tmax)","Press 4");
    print_Structure("5.Velocity at time T","press 6");



    if(g==-1)
        g=9.8;
    scanf("%d",&operation);
    if(operation==1)
    {
        Rmax= Rmaximum(v0,alpha,g);
        if(Rmax!=0)
        {
        print_Structure("Used formula","Rmax=(((vo^2)*sin(2*alpha))/g)");
        printf("Maximum height Rmax is : %lf\n",Rmax);
        }
    }
    else if(operation==2)
    {
        Hmax=Hmaximum(v0,alpha,g);
        if(Hmax!=0){
        print_Structure("Used formula","Maximum Height = (vo^2 * sin^2((alpha))) / (2 * g)");
        printf("Maximum height Hmax is : %lf\n",Hmax);
        }

    }
    else if(operation==3)
    {
        Tmax= Tmaximum(v0,alpha,g);
        if(Tmax!=0)
        {
        print_Structure("Used formula","Tmax=(vo*sin(alpha)/g)");
        printf("Maximum Time  Tmax is : %lf\n",Tmax);
        }
    }
    else if(operation==4)
    {
        Tmax=Tmaximum(2*v0,alpha,g);
        if(Tmax!=0){
        print_Structure("Used formula","Tmax=(2*vo*sin(alpha)/g)");
        printf("Maximum Time  2*Tmax is : %lf\n",Tmax);
        }
    }
    else if(operation==5)
    {
        Vt=Veclocity_at_time_t(v0,alpha,g,t);
        if(Vt!=-1)
        {
            print_Structure("Used formula","Vt=Sqrt(Vx^2+Vy^2)");
            printf("Velocity at time t is : %lf\n",Vt);
        }
    }
    else{
        printf("Invalid choice!\n");
    }


    //graph implementation
    print_Structure("Are you want to visualize the graph", "if Yes press 1 Otherwise press 2");
    int option;
    scanf("%d",&option);
    if(option ==1)
        projectile_graph(v0,alpha,g);




    return;
}


// Graph for projectile_Motion---------------------------------------------
void   projectile_graph(double v0,double alpha,double g)
{

    if(v0==-1 && alpha==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and alpha(with respect to horizontal)\n");
        return;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return;
    }
    else if(alpha==-1)
    {
        printf("Sorry alpha(with respect to horizontal) is not given\n");
        return;
    }
    else
    {


        double Ttotal;
        Ttotal=Tmaximum(2*v0,alpha,g);
       // double t_half=Ttotal/2;
        double t=0;

        double x,y,y1;

        print_Structure("Are you want to show step by step calculation?","If Yes press 1 otherwise press 2");
        int option;

        scanf("%d",&option);
        if(option==1)
            printf("Time(t)\t Horizontal Range(R)\t Height(H)\n");
        double Rmax=Rmaximum(v0,alpha,g);


        double xcoordinate,ycoordinate;


        //Arc to show angle
        double angle_in_degree=((alpha*180)/M_PI),distance_of_x=0,angle=alpha;
        if(angle_in_degree<=70.0)
        {
            distance_of_x=70;
        }
         else if(angle_in_degree>70.0 and angle_in_degree<80.0)
        {
            distance_of_x=15;
        }
        else if(angle_in_degree>=80.0 and angle_in_degree<88.0)
        {
            distance_of_x=12;
        }
        else if(angle_in_degree>89.0 and angle_in_degree<=90.90)
        {
            angle=alpha-0.01745;
            distance_of_x=1.5;
        }
        else
        {
            distance_of_x=50;
        }





         arc(originX,originY,0,angle_in_degree,60);
        line(originX,originY,originX+distance_of_x,originY-(distance_of_x*tan(angle)));

 // Draw the line for alpha
    line(90, 480, 90, 535);

    // Draw the arrow
    line(90, 480, 90-5,480+5 );
    line(90, 480, 90+5,480+5 );
         // test font size
 //   settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
     // Convert alpha to a string
    char projectileAngle[10],FHmax[]="Hmax = (v² * sin²(alpha)) / (2 * g)";
    char height[50], horizontal[50],totaltime[50],velocity[50],halftime[50];

    double printalpha=alpha*180/M_PI;
    Hmax=Hmaximum(v0,alpha,g);

    sprintf(projectileAngle, "%.1f°", printalpha);
    sprintf(height,"Hmax=%.2lf",Hmax);
    sprintf(horizontal,"Rmax=%.2lf",Rmax);
    sprintf(halftime,"Tmax=%.2lf",Tmax);
    sprintf(totaltime,"Tmax=%.2fl",2*Tmax);
    sprintf(velocity,"Vt=%.2lf",Vt);

    // Print the value of alpha at position (565, 565)
    outtextxy(90, 550, projectileAngle);
    outtextxy(originX+distance_of_x+15,originY-(distance_of_x*tan(angle))+30,str_v0);






        while(t<Ttotal)
        {


                    cleardevice();

            x=v0*cos(alpha)*t;
            y=(v0*sin(alpha)*t)-(0.5*g*t*t);

            y1=-y;




           if(option==1)
                 printf("%lf     %lf     %lf\n",t,x,y);

            arc(originX,originY,0,angle_in_degree,60);
            line(originX,originY,originX+distance_of_x,originY-(distance_of_x*tan(angle)));

            line(originX,originY,1000,originY);
            circle((x+originX),(y1+originY),12);

         // Draw the line for theta
    line(90, 480, 90, 535);

    // Draw the arrow
    line(90, 480, 90-5,480+5 );
    line(90, 480, 90+5,480+5 );
        outtextxy(90, 550, projectileAngle);
        outtextxy(originX+distance_of_x+15,originY-(distance_of_x*tan(angle))+30,str_v0);


          //  putpixel(x+originX,y1+originY,WHITE);



            swapbuffers();

           cleardevice();
            t+=time_increment;

            delay(60);

        }

        double finalpointofX =v0*cos(alpha)*Ttotal;
        double finalpointofY=(v0*sin(alpha)*Ttotal)-(0.5*g*Ttotal*Ttotal);
        double a=originX-10,b=originY-Hmax,c=originX+40,d=originY-Hmax,start_des_x=100,start_des_y=5;
        double start_ans_x=600,start_ans_y=30;

        finalpointofY= -finalpointofY;
        circle((finalpointofX+originX),(finalpointofY+originY),12);


        if(option==1)
        printf("%lf     %lf     %lf\n",Ttotal,x,y);


 // Draw the line for theta
    line(90, 480, 90, 535);

  // Draw the arrow
    line(90, 480, 90-5,480+5 );
    line(90, 480, 90+5,480+5 );
   // line(90, 485, 95, 485);
   // line(90, 485, 85, 485);

    outtextxy(90, 550, projectileAngle);
    outtextxy(originX+distance_of_x+15,originY-(distance_of_x*tan(angle))+30,str_v0);



        line(originX,originY,1000,originY);
        //-----printing path-----------------

        t=0;
        while(t<=Ttotal)
        {

            x=v0*cos(alpha)*t;
            y=(v0*sin(alpha)*t)-(0.5*g*t*t);

            y1=-y;
           arc(originX,originY,0,angle_in_degree,60);
            line(originX,originY,originX+distance_of_x,originY-(distance_of_x*tan(angle)));

            line(originX,originY,1000,originY);
            circle((x+originX),(y1+originY),2);

            //putpixel(x+originX,y1+originY,YELLOW);



            swapbuffers();
            t+=time_increment;
            delay(6);

        }


         swapbuffers();
          //   settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
          line(start_ans_x-50,start_ans_y,start_ans_x-50,start_ans_y+100);
              if(operation==1)
            {
                outtextxy(start_ans_x, 30, "Used Formula :");
                outtextxy(start_ans_x, 50, "Rmax=(v^2*sin(2*alpha))/g");
                outtextxy(start_ans_x, 70, horizontal);
            }

         else  if(operation==2)
            {
                outtextxy(start_ans_x, start_ans_y, "Used Formula :");
                outtextxy(start_ans_x, 50, "Hmax=(v^2*sin^2(alpha))/(2*g)");
                outtextxy(start_ans_x, 70, height);
            }
        else if(operation==3)
            {
                outtextxy(start_ans_x, 30, "Used Formula :");
                outtextxy(start_ans_x, 50, "Tmax=(v*sin(alpha))/g");
                outtextxy(start_ans_x, 70, halftime);
            }
        else if(operation==4)
            {
                outtextxy(start_ans_x, 30, "Used Formula :");
                outtextxy(start_ans_x, 50, "2Tmax=(2*v*sin(alpha))/g");
                outtextxy(start_ans_x, 70, totaltime);
            }
        else if(operation==5)
            {
                outtextxy(start_ans_x, 30, "Used Formula :");
                outtextxy(start_ans_x, 50, "v = sqrt(Vx^2 + Vy^2)");
                outtextxy(start_ans_x, 70, velocity);
            }
            //description
            outtextxy(start_des_x,start_des_y,"Description");
            outtextxy(start_des_x,start_des_y+20,"--------------------------------");
            outtextxy(start_des_x,start_des_y+40,"Available Formula");
            outtextxy(start_des_x,start_des_y+60,"Rmax=(((Vo^2)sin(2*alpha))/g)");
            outtextxy(start_des_x,start_des_y+80,"Hmax=(((Vo^2)sin^2(alpha))/2g)");
            outtextxy(start_des_x,start_des_y+100,"Tmax=Vo sin(alpha)/g");
            outtextxy(start_des_x,start_des_y+120,"V=sqrt(Vx^2+Vy^2)");
          //  outtextxy(start_des_x,start_des_y+140,"Vx=Vocos(alpha)");
           // outtextxy(start_des_x,start_des_y+160,"Vy=Vosin(alpha)-gt");





            line(originX,originY+15,(finalpointofX+originX),(originY+15));
            outtextxy((originX+finalpointofX/2),originY+30,horizontal);
            line(originX-15,originY,originX-15,originY-(Hmax));

        // line for Hmax
        line(a, b, c, d);
        // arrow  for Hmax
        line(a, b, a + 10, b + 10);
        line(a, b, a +10, b -10);

        outtextxy(c-20, d-30,height);
    outtextxy(originX+distance_of_x+15,originY-(distance_of_x*tan(angle))+30,str_v0);






              swapbuffers();

    }
    return;
}


    double Veclocity_at_time_t(double v0,double alpha,double g,double t)
    {
        double Vx=v0*cos(alpha);
        double Vy=v0*sin(alpha)-g*t;

        double V=sqrt(Vx*Vx+Vy*Vy);
        return V;
    }

//Function for finding Tmax
double Tmaximum(double v0,double alpha,double g)
{

    if(v0==-1 && alpha==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and alpha(with respect to horizontal)\n");
        return 0;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return 0;
    }
    else if(alpha==-1)
    {
        printf("Sorry alpha(with respect to horizontal) is not given\n");
        return 0;
    }
    else
    {
        double T_max=(v0*sin(alpha))/g;
        // printf("Maximum Time  Tmax is : %lf\n",T_max);
        return  T_max;


    }
}
//Function for Rmax
double Rmaximum(double v0,double alpha,double g)
{
    if(v0==-1 && alpha==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and alpha(with respect to horizontal)\n");
        return 0;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return 0;
    }
    else if(alpha==-1)
    {
        printf("Sorry alpha(with respect to horizontal) is not given\n");
        return 0;
    }
    else
    {
        double R_max=((v0*v0*sin(2*alpha))/g);
        // printf("Maximum height Rmax is : %lf\n",R_max);

        return  R_max;
        // graph(v0,theta,g)


    }
}


//Function for Hmax
double Hmaximum(double v0,double alpha,double g)
{

    if(v0==-1 && alpha==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and alpha(with respect to horizontal)\n");
        return 0;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return 0;
    }
    else if(alpha==-1)
    {
        printf("Sorry ! alpha(with respect to horizontal) is not given\n");
        return 0;
    }
    else
    {
        double H_max=(v0*v0*pow(sin(alpha),2)/(2*g));
        // graph(v0,alpha,g);
        // printf("Maximum height Hmax is : %lf\n",H_max);

        return H_max;


    }
}

