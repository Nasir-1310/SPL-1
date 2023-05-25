#include <bits/stdc++.h>
#include<graphics.h>
using namespace std;

#define originX 50
#define originY  500
#define MAX_Time 999
#define time_increment 0.1
#define river_magnificent 250
double Hmax,H,Rmax,g=-1,Tmax,alpha,v0,R,t,Vt=-1;
int choice,known,operation;
char str_v0[20];

char str_vBoat[30], str_vFlow[30],str_river_wide[30],str_angle[20],str_theta[20],str_resultant_V[30],str_time[30],str_displacement[30];
//int operation,resultant_V;
int resultant_V;

char str_v1[50],str_v2[50],str_u1[50],str_u2[50];
double m1=-1,u1=-1,m2=-1,u2=-1,v1=-1,v2=-1;

//double m1,m2,u1,u2,v1,v2;
void print_Structure(string first,string second);
double Tmaximum(double v0,double theta,double g);
double Rmaximum(double v0,double theta,double g);
double Hmaximum(double v0,double theta,double g);
double conservation_of_momentum(double m1,double u1,double m2,double u2,double v,double m);
double Veclocity_at_time_t(double v0,double alpha,double g,double t);
double combined_velocity(double m1,double u1,double m2,double u2);
 void graphcal_representation_of_mechanics( double m1,double u1,double m2,double u2,double m,double v,double finalV);




double time_cross_river(double vBoat,double  alpha,double width_of_the_river);
double R_resultant(double vBoat,double vFlow,double alpha);
double  Angle_of_boat_with_respect_to_flow(double vBoat,double vFlow,double alpha);
void   projectile_graph(double v0,double alpha,double g);









// Graph for projectile_Motion---------------------------------------------

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
        if(Hmax!=0)
        {
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
        if(Tmax!=0)
        {
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
    else
    {
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
            // rectangle(originX+x,originY+y1-30,originX+30+x,originY+y1);
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
        // rectangle(originX+x,originY+y1-30,originX+30+x,originY+y1);



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

        outtextxy(start_ans_x, 10, "Answer :");


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



///////////////////////////////////////////////////////////
// Function for visualization of vector analysis
void  vector_graph(double vBoat,double vFlow,double alpha,double width_of_the_river)
{
    if(vBoat<0 || vFlow<0 || alpha<0)
    {
        printf("Invalid Information! please try again later\n");
        return;
    }
    else if(vBoat<=0 and vFlow>=0 )
    {
        printf("Can't Cross The rives!Please try again\n");
        return;

    }
    else
    {


        //cleardevice();



        double theta=0;
        double midOfx=500,midOfy=originY,arrowLength=150,arrow=20;
        double angle_between_vboat_river_wide=alpha-(M_PI/2);
        double xcoordianate_According_to_vBoat=midOfx-(river_magnificent*tan(angle_between_vboat_river_wide));
        double ycoordinate_According_to_vBoat=midOfy-river_magnificent;

        double time_needed_to_cross_the_river=0;
        double time=0,x_answer=600,y_answer=10;
        time_needed_to_cross_the_river=time_cross_river(vBoat,alpha,width_of_the_river);
        setlinestyle(SOLID_LINE, 0, 4);

        line(originX,originY,originX+1000,originY);
        line(originX,originY-river_magnificent,originX+1000,originY-river_magnificent);


        resultant_V=R_resultant(vBoat,vFlow,alpha);
        theta=Angle_of_boat_with_respect_to_flow(vBoat,vFlow,alpha);

        if(theta<=0)
        {
            theta=theta+M_PI;
        }

        double xcomponent=0,ycomponent=0,xcoordinate=midOfx,ycoordinate=midOfy;
        xcomponent=resultant_V*cos(theta);
        ycomponent=resultant_V*sin(theta);


        // Convert alpha to a string
        double print_alpha=alpha*180/M_PI,print_theta=theta*180/M_PI;
        sprintf(str_angle, "%.1f°", print_alpha);
        sprintf(str_theta, "%.1f°", print_theta);



        while(time<time_needed_to_cross_the_river)
        {



            if(ycoordinate>midOfy-river_magnificent+50)
            {
                cleardevice();
                xcoordinate+=xcomponent*0.5;
                ycoordinate-=ycomponent*0.5;
                readimagefile("image.jpg",xcoordinate-25,ycoordinate-50,xcoordinate+25,ycoordinate);
                //swapbuffers();


                line(originX,originY,originX+1000,originY);
                line(originX,originY-river_magnificent,originX+1000,originY-river_magnificent);

                //line for flow to show arrow
                line(midOfx,midOfy,midOfx+arrowLength,midOfy);
                //for arrow sing
                line(midOfx+arrowLength,midOfy,midOfx+arrowLength-arrow,midOfy-arrow);
                line(midOfx+arrowLength,midOfy,midOfx+arrowLength-arrow,midOfy+arrow);

                arc(midOfx,midOfy,0,alpha*180/M_PI,80);
                arc(midOfx,midOfy,0,theta*180/M_PI,50);
                if(alpha>=(100*M_PI/180))
                {
                    line(midOfx,midOfy,xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat); //reach target according to initial velocity
                    line(xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat,xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat+arrow);
                    line(xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat,xcoordianate_According_to_vBoat+arrow,ycoordinate_According_to_vBoat+(arrow/2));
                    outtextxy(xcoordianate_According_to_vBoat-20,ycoordinate_According_to_vBoat+40,str_vBoat);

                }
                else if(alpha<=(80*M_PI/180))
                {
                    line(midOfx,midOfy,xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat); //reach target according to initial velocity
                    line(xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat,xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat+arrow);
                    line(xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat,xcoordianate_According_to_vBoat-arrow,ycoordinate_According_to_vBoat+(arrow/2));
                    outtextxy(xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat+60,str_vBoat);


                }
                else
                {
                    line(midOfx,midOfy,xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat); //reach target according to initial velocity
                    line(xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat,xcoordianate_According_to_vBoat-arrow,ycoordinate_According_to_vBoat+arrow/2);
                    line(xcoordianate_According_to_vBoat,ycoordinate_According_to_vBoat,xcoordianate_According_to_vBoat+arrow,ycoordinate_According_to_vBoat+(arrow/2));
                    outtextxy(xcoordianate_According_to_vBoat-40,ycoordinate_According_to_vBoat+40,str_vBoat);

                }


                // Draw the line for theta
                line(midOfx+25, midOfy-15, midOfx+25, midOfy+40);

                // Draw the arrow
                line(midOfx+25, midOfy-15,midOfx+25-7,midOfy-15+7);
                line(midOfx+25, midOfy-15, midOfx+25+7, midOfy-15+7);

                //Draw the line for alpha
                line(midOfx+65,midOfy-15, midOfx+65,midOfy+60);


                // Draw the arrow
                line(midOfx+65, midOfy-15, midOfx+65-7, midOfy-15+7);
                line(midOfx+65, midOfy-15, midOfx+65+7, midOfy-15+7);
                //Show wide of river
                line(originX+15,originY-5,originX+15,originY-river_magnificent+5);
                //arrow for down
                line(originX+15,originY-5,originX+15-10,originY-5-10);
                line(originX+15,originY-5,originX+15+10,originY-5-10);
                //arrow for up
                line(originX+15,originY-river_magnificent+5,originX+15-10,originY-river_magnificent+5+10);
                line(originX+15,originY-river_magnificent+5,originX+15+10,originY-river_magnificent+5+10);

                //line to display vFlow
                line(midOfx+150,midOfy-80,midOfx+80+150,midOfy-80);
                //arrow
                line(midOfx+150+80,midOfy-80,midOfx+80+150-20,midOfy-80-15);
                line(midOfx+150+80,midOfy-80,midOfx+80+150-20,midOfy-80+15);
                outtextxy(midOfx+150+80-20,midOfy-80-15-20,str_vFlow);



                outtextxy(originX+30,originY-70,str_river_wide);


                outtextxy(490, 545, str_theta);
                outtextxy(565, 565, str_angle);
                // circle(midOfx,midOfy,15);  // To identify starting point
                // setcolor(getbkcolor());
                swapbuffers();

                delay(100);

            }

            time+=time_increment;
            //   swapbuffers();
        }
        xcoordinate=midOfx,ycoordinate=midOfy;
        time=0;
        while(ycoordinate>midOfy-river_magnificent+50)
        {
            swapbuffers();
            xcoordinate+=xcomponent*0.8;
            ycoordinate-=ycomponent*0.8;
            circle(xcoordinate,ycoordinate,1);
            time+=time_increment;
            swapbuffers();

        }
        int resultantx=midOfx+(xcomponent*(time_needed_to_cross_the_river)/5);
        swapbuffers();

        outtextxy(40,30,"Formula available");
        outtextxy(40,30,"Formula available");
        outtextxy(40,30,"Formula available");
        outtextxy(40,50,"R=sqrt(p^2+q^2+2pqcos(alpha)");
        outtextxy(40,70,"tan(theta)=(qsin(alpha)/(p+qcos(alpha))");
        //  outtextxy(xcoordinate+15,ycoordinate+40,str_resultant_V);

        line(x_answer-60,y_answer,x_answer-60,y_answer+100);

        outtextxy(x_answer,y_answer,"Answer:");
        outtextxy(x_answer,y_answer+20,"Formula used:");


        if(operation==1)
        {
            outtextxy(x_answer,y_answer+40,"R=sqrt(p^2+q^2+2pqcos(alpha)");
            outtextxy(x_answer,y_answer+60,str_resultant_V);

        }
        else if(operation==2)
        {
            outtextxy(x_answer,y_answer+40,"tan(theta)=(qsin(alpha)/(p+qcos(alpha))");
            outtextxy(x_answer,y_answer+60,str_theta);

        }
        else if(operation==3)
        {
            outtextxy(x_answer,y_answer+40,"R=sqrt(p^2+q^2+2pqcos(alpha)");
            outtextxy(x_answer,y_answer+60,str_resultant_V);
            outtextxy(x_answer,y_answer+80,"tan(theta)=(qsin(alpha)/(p+qcos(alpha))");
            outtextxy(x_answer,y_answer+100,str_theta);


        }
        else if(operation==4)
        {
            outtextxy(x_answer,y_answer+40,"T=d/(qsin(alpha)");
            outtextxy(x_answer,y_answer+60,str_time);

        }
        else if(operation==5)
        {
            outtextxy(x_answer,y_answer+40,"X=T*(p+qcos(alpha)");
            outtextxy(x_answer,y_answer+60,str_displacement);

        }
        else if(operation==6)
        {
            outtextxy(x_answer,y_answer+40,"T=d/q");
            outtextxy(x_answer,y_answer+60,str_time);

        }
        else if(operation==7)
        {
            outtextxy(x_answer,y_answer+40,"cos(theta)=-(p/q);");
            outtextxy(x_answer,y_answer+60,str_angle);

        }

        swapbuffers();
        // line(originX,originY,originX+900,originY);
        //  line(originX,originY-river_magnificent,originX+900,originY-river_magnificent);


    }

    //line(originX,originY,originX+900,originY);
    //  line(originX,originY-river_magnificent,originX+900,originY-river_magnificent);


    return;
}



//Function for Resultant velocity of boat
double R_resultant(double vBoat,double vFlow,double alpha)
{
    if(vBoat<=0 || vFlow<=0 || alpha<=0)
    {
        printf("Error parameter  is not given correctly please try again\n");
        return 0;
    }

    double ResultantV=pow((vBoat*vBoat+vFlow*vFlow+2*vBoat*vFlow*cos(alpha)),0.5);
    return ResultantV;
}

//Function for Angle among of Resultant velocity and Flow
double  Angle_of_boat_with_respect_to_flow(double vBoat,double vFlow,double alpha)
{
    if(vBoat<=0 || vFlow<=0 || alpha<=0)
    {
        printf("Error parameter  is not given correctly please try again\n");
        return 0;
    }

    double value=((vBoat*sin(alpha))/(vFlow+(vBoat*cos(alpha))));
    double theta=atan(value);
    return theta;
}



double time_cross_river(double vBoat,double  alpha,double width_of_the_river)
{
    double time;
    if(vBoat>0.0 && alpha>0.0 && width_of_the_river>0.0)
    {
        // printf("vBoat=%lf alpha= %lf width=%lf\n",vBoat,alpha,width_of_the_river);
        time=(width_of_the_river/(vBoat*sin(alpha)));

    }
    else
    {
        printf("Invalid information! please try again\n");
        return -1;

    }
    return time;
}


//Vector analysis
void vector_Analysis()
{
start_here:
    print_Structure("Welcome to Vector world ! Here you will find solution of your desire problem with visualization"," ");
    double vBoat=-1,vFlow=-1,alpha=-1,Angle,R,width_of_the_river=-1,time_to_cross_the_river=-1;
    int t;
    print_Structure("Enter number of known parameter from below","1)Velocity of Boat(vBoat) 2) Alpha(with respect to flow) 3)Velocity of Flow(vFlow) 4) Width of the River");
    scanf("%d",&t);
    if(t<1 || t>4)
    {
        cin.ignore();
        cout<<"Enter a valid number : \n";
        goto start_here;
    }
    while(t--)
    {
        if(vBoat==-1)
            print_Structure("1. Velocity of Boat(m/s)","Press 1");

        if(vFlow==-1)
            print_Structure("2. Velocity of Flow","Press 2");
        if(alpha==-1)
            print_Structure("3. Alpha(with respect to flow)","Press 3");
        if(width_of_the_river==-1)
            print_Structure("4. Width of the River","Press 4");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter Velocity of Boat(m/s)\n");
            scanf("%lf",&vBoat);
        }
        else if(choice==2)
        {
            printf("Enter Velocity of Flow(m/s)\n ");
            scanf("%lf",&vFlow);
        }

        else if(choice==3)
        {
            printf("Enter angle with respect to Flow(Degree)\n");
            scanf("%lf",&alpha);

            alpha=(M_PI*alpha)/180;
        }

        else if(choice==4)
        {
            printf("Enter the width of the River(Max width 400)\n");
            scanf("%lf",&width_of_the_river);
        }


    }



    sprintf(str_vFlow,"%.2lf m/s",vFlow);
    sprintf(str_vBoat,"%.2lf m/s",vBoat);
    sprintf(str_river_wide,"%.2lf m",width_of_the_river);





    printf("What do you want ? choice an option\n");
    print_Structure("Resultant velocity of a Boat"," Press ->>1");
    print_Structure("Angle among with resultant velocity and flow","Press->>2");
    print_Structure("Both Resultant velocity and angle between resultant velocity and flow","Press->>3");
    print_Structure("Time  to cross the River","Press->>4");
    print_Structure("Displacement along with X-axis","Press->>5");
    print_Structure("Shortest Time to cross the River","Press->>6");
    print_Structure("Shortest Path to cross the River","Press->>7");


    scanf("%d",&operation);


    if(operation==1)
    {
        R= R_resultant(vBoat,vFlow,alpha);
        if(R!=0)
        {
            print_Structure("Used formula","R=Pow(p^2+q^2+2*p*q*cos(alpha),0.5)");
            printf("Resultant velocity of Boat is  : %lfm/s\n",R);
            sprintf(str_resultant_V,"R=%.1lf m/s",resultant_V);
        }
    }

    else if(operation==2)
    {
        Angle=Angle_of_boat_with_respect_to_flow(vBoat,vFlow,alpha);
        if(Angle!=0)
        {
            Angle=(Angle*180)/M_PI;
            print_Structure("Used formula","tan(theta)=(q*sin(alpha))/(p+q*cos(alpha))");
            printf("Angle among Resultant velocity and flow is : %lf (Degree)\n",Angle);
            sprintf(str_theta,"theta%=.1f°",Angle);


        }

    }
    else if(operation==3)
    {
        double R= R_resultant(vBoat,vFlow,alpha);
        Angle=Angle_of_boat_with_respect_to_flow(vBoat,vFlow,alpha);
        if(R!=0 && Angle!=0)
        {
            Angle=(180*Angle)/M_PI;

            print_Structure("Used formula of Resultant velocity","(R=Pow(p^2+q^2+2*p*q*cas(alpha),0.5))");
            print_Structure("Used formula  for theta","tan(theta)=(q*sin(alpha))/(p+q*cos(alpha))");

            printf("Resultant velocity of Boat is  : %lf m/s\n",R);
            sprintf(str_resultant_V,"R=%.1lf m/s",resultant_V);

            if(Angle<0)
            {
                printf("Angle among Resultant velocity and flow is : %lf (degree)\n",180+Angle);
                sprintf(str_angle,"theta=%.1f°",Angle);


            }
            else
            {
                printf("Angle among Resultant velocity and flow is : %lf (degree)\n",Angle);
                sprintf(str_theta,"theta=%.1f°",Angle);
            }


        }
    }
    else if (operation==4)
    {
        time_to_cross_the_river=time_cross_river(vBoat, alpha, width_of_the_river);
        if(time_to_cross_the_river>=0)
        {
            printf("Time to cross the river is : %lf s\n\n",time_to_cross_the_river);
            sprintf(str_time,"Time=%.1lf s",time_to_cross_the_river);

        }
    }
    else if(operation==5)
    {
        double x_component,y_component,displacement_x_axis=0;
        x_component=vFlow+(vBoat*cos(alpha));
        y_component=vBoat*sin(alpha);
        time_to_cross_the_river=time_cross_river(vBoat,alpha,width_of_the_river);
        displacement_x_axis=time_to_cross_the_river*x_component;
        if(displacement_x_axis>=0)
        {
            printf("Displacement along with X-axis : %lf m\n",displacement_x_axis);
            sprintf(str_displacement,"X=%.1f",displacement_x_axis);

        }
        else
        {
            printf("Invalid information please! Try again\n");
            sprintf(str_displacement,"X=%.1f",displacement_x_axis);

        }

    }

    else if(operation==6)
    {
        alpha=(90*M_PI/180);
        time_to_cross_the_river=time_cross_river(vBoat,alpha,width_of_the_river);
        if(time_to_cross_the_river>=0)
        {
            printf("Shortest time : %lf\n",time_to_cross_the_river);
            sprintf(str_time,"T=%.1f s",time_to_cross_the_river);

        }
        else
        {
            printf("Invalid information please try again!\n");
            sprintf(str_time,"T=%.1f s",time_to_cross_the_river);

        }
    }
    else if(operation==7)
    {
        if(vFlow<0 and vBoat>0)
        {
            printf("Velocity of Flow is not given! please try again\n");
        }
        else if(vFlow>=0 and vBoat<=0)
        {
            printf("Velocity of Boat is not given! please try again\n");
        }
        else if(vFlow<=0 and vBoat<=0)
        {
            printf("Velocity of Flow and Boat is not given ! please try again\n");
        }
        else
        {
            if(vBoat<=vFlow)
            {
                printf("Can't cross the river in Shortest path\n");
            }
            else
            {
                alpha=acos(-vFlow/vBoat);
                alpha=((alpha*180)/M_PI);
                printf("To cross the river in Shortest path Angle of Boat with respect to Flow(degree): %lf\n",alpha);
                sprintf(str_angle,"alpha=%.1f°",Angle);
                alpha=((alpha*M_PI)/180);
            }
        }

    }

//}
    int option;
    print_Structure("Are you want to visualize the graph","If Yes press    1 Otherwise press 2");
    scanf("%d",&option);
    if(option==1)
    {
        vector_graph (vBoat,vFlow,alpha,width_of_the_river);
    }



    return;
}

//---------------------------------------------------------------------------------------


void mechanics()
{
start_here:
    print_Structure("Welcome to Newtonian Mechanics ! Here you will be able to solve to related question of conservation of Momentum"," ");

    int choice;
    m1=-1,u1=-1,m2=-1,u2=-1,v1=-1,v2=-1;
    int t,k=1;
    // string temp;
    print_Structure("Enter number of known parameter given below","1) m1  2) u1  3) m2  4) u2  5) v1  6) v2 ");
    //cin>>temp;
    cin>>t;
    int p;
    // t = std::stoi()
    while(k)
    {
        if(t<1 || t>6)
        {
            printf("Invalid input : Try again %d\n",t);
            scanf("%d",&t);
            scanf("%d",&p);
            t=p;

            //goto start_here;
        }
        else
        {
            k=0;
        }

    }



    while(t--)
    {
        if(m1==-1)
            print_Structure("1. Mass of 1st object(kg)","Press 1");
        if(u1==-1)
            print_Structure("2. Initial velocity of 1st object (m/s)","Press 2");
        if(m2==-1)
            print_Structure("3. Mass of 2nd  object(kg)","Press 3");
        if(u2==-1)
            print_Structure("4. Initial velocity of 2nd object(m/s)","Press 4");
        if(v1==-1)
            print_Structure("5. Final velocity of the 1st object(m/s)","Press 5");
        if(v2==-1)
            print_Structure("6. Final velocity of the 2nd object(m/s)","Press 6");


        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Mass of 1st object(kg)\n");
            scanf("%lf",&m1);
        }

        else if(choice==2)
        {
            printf("Initial velocity of 1nd object (m/s)\n");
            scanf("%lf",&u1);

        }
        else if(choice==3)
        {
            printf("Mass of the 2nd object(kg)\n ");
            scanf("%lf",&m2);
        }
        else if (choice==4)
        {
            printf("Initial velocity of the 2nd object(m/s)\n");
            scanf("%lf",&u2);


        }
        else if(choice==5)
        {

            printf("Final velocity of the the 1st object(m/s)\n");
            scanf("%lf",&v1);
        }
        else if(choice==6)
        {
            printf("Final velocity of the 2nd object(m/s)\n");
            scanf("%lf",&v2);
        }

    }

    double finalV;
    int check=2;


    sprintf(str_u1,"u1=%.2lf m/s",u1);
    sprintf(str_u2,"u2=%.2lf m/s",u2);
    sprintf(str_v1,"v1=%.2lf m/s",v1);
    sprintf(str_v2,"v2=%.2lf m/s",v2);





    //printf("v1=%lf,v2=%lf\n",v1,v2);

    if(v1==-1.00 and v2==-1.00)
    {
        print_Structure("Are you want fo find Combined Volocity?","If Yes press 1 otherwise press 2");
        scanf("%d",&check);
    }
    if(check!=1 and (v1==-1 and v2==-1))
    {
        printf("Invalid Information! Final velocity is missing please try again\n");
        return;
    }
    if(check==1)
    {
        finalV=combined_velocity(m1,u1,m2,u2);
        printf("Final velocity  of 1st object is : %lf\n",finalV);
        printf("Final velocity of 2nd object is : %lf\n",finalV);


        sprintf(str_v1,"v1=%.2lf m/s",finalV);
        sprintf(str_v2,"v2=%.2lf m/s",finalV);

    }
    else if(v1==-1)
    {
        finalV=conservation_of_momentum(m1,u1,m2,u2,v2,m2);//second object final velocity is given
        if(finalV!=-1)
        {
            print_Structure("Formula used","m1*u1+m2*u2 = m1*v1+m2*v2");
            printf("Final velocity of the 1 st object is : %lf\n",finalV);
            sprintf(str_v1,"v1=%.2lf m/s",finalV);

        }


    }
    else if(v2==-1)
    {

        finalV=conservation_of_momentum(m1,u1,m2,u2,v1,m1);
        if(finalV!=-1)
        {
            print_Structure("Formula used","m1*u1+m2*u2 = m1*v1+m2*v2");
            printf("Final velocity of the 2nd object is : %lf\n",finalV);
            sprintf(str_v2,"v2=%.2lf m/s",finalV);


        }


    }

    print_Structure("Are you want to visualize the graph", "if Yes press 1 Otherwise press 2");
    int option;
    scanf("%d",&option);
    if(option ==1)
    {
        if(check==1)
        {
            graphcal_representation_of_mechanics( m1,u1,m2,u2,m2,finalV,finalV);

        }
        else if(v1==-1)
        {
            graphcal_representation_of_mechanics( m1,u1,m2,u2,m2,v2,finalV);
        }
        else
        {
            graphcal_representation_of_mechanics( m1,u1,m2,u2,m1,v1,finalV);
        }
    }

    //   graphcal_representation_of_mechanics( m1,u1,m2,u2,m,v,finalV);


    return;
}



double combined_velocity(double m1,double u1,double m2,double u2)
{
    if(u1==-1 || u2==-1)
    {
        printf("Parameter is invalid!! please try again\n");
        return -1;
    }
    else
    {
        double initial_momentum,combined_v;
        initial_momentum=m1*u1+m2*u2;
        combined_v=initial_momentum/(m1+m2);
        return combined_v;
    }

}

void  graph_for_momentum_simulation(double m1,double u1,double m2,double u2,double m,double v,double finalV,int condition)
{

    double time=0,distance1,distance2,distance,distance1_after_collision=0,distance2_after_collision=0;
    double time_after_collision=0, time_needed_to_collision=0;


    if(u1==-1 || 2==-1)
    {
        printf("Parameter is invalid!! please try again\n");
        return;
    }



    printf("Enter distance between two object\n");
    scanf("%lf",&distance);
    double arrow_length=12,printtextbefore=40,printtextup1=30,printtextafter=10;
    outtextxy(originX+distance1+distance1_after_collision-printtextbefore,originY- 100-printtextup1,str_v1);


    if(condition==1)
    {


        if(m1==m2)
        {

            //condition when there is no collision
            if(u1-u2<=0)
            {
                time_needed_to_collision=MAX_Time;
            }
            else
            {
                //distance=distance-40;
                time_needed_to_collision=(distance-40)/(u1-u2);

            }

        }

        else
        {
            //condition when there is no collision
            if(u1-u2<=0)
            {
                time_needed_to_collision=MAX_Time;
            }


            else
            {
                //distance=distance-35;
                time_needed_to_collision=(distance-35)/(u1-u2);

            }

        }





        while(time<70)
        {

            cleardevice();

            if(time<=time_needed_to_collision)
            {


                // line(originX,originY,originX+1000,originY);
                distance1=u1*time;
                distance2=u2*time;
                line(originX,originY,originX+1000,originY);
                if(m1>m2)
                {

                    // line draw for first object
                    line(originX+distance1,originY- 50,originX+distance1,originY-100);
                    //arrow
                    line(originX+distance1,originY- 50,originX+distance1-arrow_length,originY- 50-arrow_length);
                    line(originX+distance1,originY- 50,originX+distance1+arrow_length,originY- 50-arrow_length);
                    outtextxy(originX+distance1-printtextbefore,originY-100-printtextup1,str_u1);


                    //line draw for second object
                    line(originX+distance2+distance,originY-50,originX+distance2+distance,originY-100);
                    //arrow
                    line(originX+distance2+distance,originY-50,originX+distance2+distance-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance,originY-50,originX+distance2+distance+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+printtextafter,originY-100,str_u2);



                    circle(originX+distance1,originY-20,20);

                    circle(originX+distance2+distance,originY-15,15);
                }
                else if (m1<m2)
                {
                    // line draw for first object
                    line(originX+distance1,originY- 50,originX+distance1,originY-100);
                    //arrow
                    line(originX+distance1,originY- 50,originX+distance1-arrow_length,originY- 50-arrow_length);
                    line(originX+distance1,originY- 50,originX+distance1+arrow_length,originY- 50-arrow_length);
                    outtextxy(originX+distance1-printtextbefore,originY-100-printtextup1,str_u1);

                    //line draw for second object
                    line(originX+distance2+distance,originY-50,originX+distance2+distance,originY-100);
                    //arrow
                    line(originX+distance2+distance,originY-50,originX+distance2+distance-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance,originY-50,originX+distance2+distance+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+printtextafter,originY-100,str_u2);



                    circle(originX+distance1,originY-15,15);
                    circle(originX+distance2+distance,originY-20,20);
                }
                else
                {

                    // line draw for first object
                    line(originX+distance1,originY- 50,originX+distance1,originY-100);
                    //arrow
                    line(originX+distance1,originY- 50,originX+distance1-arrow_length,originY- 50-arrow_length);
                    line(originX+distance1,originY- 50,originX+distance1+arrow_length,originY- 50-arrow_length);
                    outtextxy(originX+distance1-printtextbefore,originY-100-printtextup1,str_u1);

                    //line draw for second object
                    line(originX+distance2+distance,originY-50,originX+distance2+distance,originY-100);
                    //arrow
                    line(originX+distance2+distance,originY-50,originX+distance2+distance-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance,originY-50,originX+distance2+distance+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+printtextafter,originY-100,str_u2);

                    circle(originX+distance1,originY-20,20);
                    circle(originX+distance2+distance,originY-20,20);
                }
                time+=time_increment;

            }
            else
            {
                distance1_after_collision=v*time_after_collision;
                distance2_after_collision=finalV*time_after_collision;

                line(originX,originY,originX+1000,originY);
                if(m1>m2)
                {
                    //line for first object after collition
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision,originY- 100);
                    //arrow
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision-arrow_length,originY- 50-arrow_length);
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision+arrow_length,originY- 50-arrow_length);
                    outtextxy(originX+distance1+distance1_after_collision-printtextbefore,originY- 100-printtextup1,str_v1);

                    //line for second object after collition
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision,originY-100);
                    //arrow
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+distance2_after_collision+printtextafter,originY-100,str_v2);

                    circle(originX+distance1+distance1_after_collision,originY-20,20);
                    circle(originX+distance2+distance+distance2_after_collision,originY-15,15);
                }
                else if (m1<m2)
                {
                    //line for first object after collition
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision,originY- 100);
                    //arrow
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision-arrow_length,originY- 50-arrow_length);
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision+arrow_length,originY- 50-arrow_length);
                    outtextxy(originX+distance1+distance1_after_collision-printtextbefore,originY- 100-printtextup1,str_v1);

                    //line for second object after collition
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision,originY-100);
                    //arrow
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+distance2_after_collision+printtextafter,originY-100,str_v2);


                    circle(originX+distance1+distance1_after_collision,originY-15,15);
                    circle(originX+distance2+distance+distance2_after_collision,originY-20,20);
                }
                else
                {

                    //line for first object after collition
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision,originY- 100);
                    //arrow
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision-arrow_length,originY- 50-arrow_length);
                    line(originX+distance1+distance1_after_collision,originY- 50,originX+distance1+distance1_after_collision+arrow_length,originY- 50-arrow_length);
                    outtextxy(originX+distance1+distance1_after_collision-printtextbefore,originY- 100-printtextup1,str_v1);

                    //line for second object after collition
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision,originY-100);
                    //arrow
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+distance2_after_collision,originY-50,originX+distance2+distance+distance2_after_collision+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+distance2_after_collision+printtextafter,originY-100,str_v2);

                    circle(originX+distance1+distance1_after_collision,originY-20,20);
                    circle(originX+distance2+distance+distance2_after_collision,originY-20,20);
                }


                time_after_collision+=time_increment;
                time+=time_increment;
            }





            swapbuffers();
            delay(10);

        }


    }


    //condition for -X axis
    else
    {
        if(m1==m2)
        {

            //condition when there is no collision
            if(u2-u1>=0)
            {
                time_needed_to_collision=MAX_Time;
            }
            else
            {
                //distance=distance-40;
                time_needed_to_collision=(distance-40)/(-(u2-u1));

            }

        }

        else
        {
            //condition when there is no collision
            if(u2-u1>=0)
            {
                time_needed_to_collision=MAX_Time;
            }


            else
            {
                //distance=distance-35;
                time_needed_to_collision=(distance-35)/(-(u2-u1));

            }

        }






        while(time<70)
        {



            // line(originX,originY,originX+1000,originY);
            cleardevice();
            if(time<=time_needed_to_collision)
            {


                // line(originX,originY,originX+600,originY);
                distance1=u1*time;
                distance2=u2*time;
                line(originX,originY,originX+1000,originY);
                if(m1>m2)
                {
                    //line for first object
                    line(originX+distance1+400,originY-50,originX+distance1+400,originY-100);
                    //arrow
                    line(originX+distance1+400,originY-50,originX+distance1+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance1+400,originY-50,originX+distance1+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance1+400-2*printtextbefore,originY-100-2*printtextup1,str_u1);


                    //line for second ogject
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400,originY-100);
                    //arrow
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+400+printtextafter,originY-100,str_u2);



                    circle(originX+distance1+400,originY-20,20);
                    circle(originX+distance2+distance+400,originY-15,15);
                }
                else if (m1<m2)
                {

                    //line for first object
                    line(originX+distance1+400,originY-50,originX+distance1+400,originY-100);
                    //arrow
                    line(originX+distance1+400,originY-50,originX+distance1+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance1+400,originY-50,originX+distance1+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance1+400-2*printtextbefore,originY-100-2*printtextup1,str_u1);

                    //line for second ogject
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400,originY-100);
                    //arrow
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+400+printtextafter,originY-100,str_u2);


                    circle(originX+distance1+400,originY-15,15);
                    circle(originX+distance2+distance+400,originY-20,20);
                }
                else
                {
                    //line for first object
                    line(originX+distance1+400,originY-50,originX+distance1+400,originY-100);
                    //arrow
                    line(originX+distance1+400,originY-50,originX+distance1+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance1+400,originY-50,originX+distance1+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance1+400-2*printtextbefore,originY-100-2*printtextup1,str_u1);

                    //line for second ogject
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400,originY-100);
                    //arrow
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+400,originY-50,originX+distance2+distance+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+400+printtextafter,originY-100,str_u2);


                    circle(originX+distance1+400,originY-20,20);
                    circle(originX+distance2+distance+400,originY-20,20);
                }
                time+=time_increment;

            }
            else
            {


                distance1_after_collision=v*time_after_collision;
                distance2_after_collision=finalV*time_after_collision;
                line(originX,originY,originX+1000,originY);
                if(m1>m2)
                {
                    //line for first object after collition
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400,originY-100);
                    //arrow
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance1+distance1_after_collision+400-2*printtextbefore,originY-100-2*printtextup1,str_v1);


                    //line for second object after collition
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400,originY-100);
                    //arrow
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+distance2_after_collision+400+printtextafter,originY-100,str_v2);



                    circle(originX+distance1+distance1_after_collision+400,originY-20,20);
                    circle(originX+distance2+distance+distance2_after_collision+400,originY-15,15);
                }
                else if (m1<m2)
                {
                    //line for first object after collition
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400,originY-100);
                    //arrow
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance1+distance1_after_collision+400-2*printtextbefore,originY-100-2*printtextup1,str_v1);


                    //line for second object after collition
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400,originY-100);
                    //arrow
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+distance2_after_collision+400+printtextafter,originY-100,str_v2);


                    circle(originX+distance1+distance1_after_collision+400,originY-15,15);
                    circle(originX+distance2+distance+distance2_after_collision+400,originY-20,20);
                }
                else
                {
                    //line for first object after collition
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400,originY-100);
                    //arrow
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance1+distance1_after_collision+400,originY-50,originX+distance1+distance1_after_collision+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance1+distance1_after_collision+400-2*printtextbefore,originY-100-2*printtextup1,str_v1);


                    //line for second object after collition
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400,originY-100);
                    //arrow
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400-arrow_length,originY-50-arrow_length);
                    line(originX+distance2+distance+distance2_after_collision+400,originY-50,originX+distance2+distance+distance2_after_collision+400+arrow_length,originY-50-arrow_length);
                    outtextxy(originX+distance2+distance+distance2_after_collision+400+printtextafter,originY-100,str_v2);


                    circle(originX+distance1+distance1_after_collision+400,originY-20,20);
                    circle(originX+distance2+distance+distance2_after_collision+400,originY-20,20);
                }


                time_after_collision+=time_increment;
                time+=time_increment;
            }



            swapbuffers();
            delay(10);



        }

    }


    line(originX,originY,originX+1000,originY);

    swapbuffers();
    // line to separate answer and description

    outtextxy(40,70,"Description\n");
    outtextxy(40,90,"----------------------------------------");
    outtextxy(40,110,"Formula abailable");
    outtextxy(40,130,"m1u1+m2u2=m1v1+m2v2");
    outtextxy(40,150,"m1=Mass of 1st object");
    outtextxy(40,170,"m2=Mass of 2nd object");
    outtextxy(40,190,"u1=initial velocity of 1st object");
    outtextxy(40,210,"u2=initial velocity of 2nd object");
    outtextxy(40,230,"v1=Final velocity of 1st object");
    outtextxy(40,250,"v2=Final velocity of 2nd object");
    outtextxy(40,270,"v2=Final velocity of 2nd object");
    line(490,70,490,210);

    outtextxy(510,70,"Solution:");
    outtextxy(510,90,"---------------");
    outtextxy(510,110,"Used formula");
    outtextxy(510,130,"m1*u1+m2*u2=m1*v1+m2*v2");
    if(v1==-1 and v2==-1)
    {
        outtextxy(510,150,str_v1);
        outtextxy(510,170,str_v2);
    }
    else if(v1==-1)
    {
        outtextxy(510,150,str_v1);
    }
    else if(v2==-1)
    {
        outtextxy(510,150,str_v2);


    }


    swapbuffers();

//outtextxy(60,)

    return;

}

//Graph for conservation of momentum
void graphcal_representation_of_mechanics( double m1,double u1,double m2,double u2,double m,double v,double finalV)
{
    if(u1>=0 )
    {
        // first object's final velocity given
        if(m1==m)
        {
            graph_for_momentum_simulation(m1, u1, m2, u2, m, v, finalV,1);


        }
        //second object final velocity given
        else
        {
            // graph_for_mechanics_when_both_object_direction_in_positive_X_axis_or_towards(m1,u1,m2,u2,m,finalV,v,1);
            graph_for_momentum_simulation(m1,u1,m2,u2,m,v,finalV,1);
        }

    }

    else//work for other portion
    {
        if(m1==m)
        {
            graph_for_momentum_simulation(m1, u1, m2, u2, m, v, finalV,2);


        }
        //second object final velocity given
        else
        {
            // graph_for_mechanics_when_both_object_direction_in_positive_X_axis_or_towards(m1,u1,m2,u2,m,finalV,v,2);
            graph_for_momentum_simulation(m1,u1,m2,u2,m,v,finalV,2);

        }
    }

}



//start of Mechanics
double conservation_of_momentum(double m1,double u1,double m2,double u2,double v,double m)
{
    // printf("m1=%lf u1=%lf m2=%lf u2=%lf v=%lf m=%lf\n",m1,u1,m2,u2,v,m);
    int option;
    double finalV;

    if(m1>0 && m2>0 && m>0)
    {
        if((u1<=u2 and u1>=0 and u2>=0) || (u1<=u2 and u1<0 and u2<=0))
        {
            printf("No collision\n");
            return -1;
        }
        else
        {
            finalV=((m1*u1)+(m2*u2));
            finalV=finalV-(v*m);

            finalV=finalV/(m1+m2-m);
            return finalV;
        }

    }
    else
    {
        printf("Mass of object can't be negative ! Please try again\n");
        return -1;
    }

}


//printing the interface
void print_Structure(string first,string second)
{
    string firstString="*   "+first+"   *";
    string secondString="*   "+second+"   *";
    string bigString;
    if(firstString.length()>=secondString.length())
    {
        bigString=firstString;
        int structureLength=bigString.length();
        for(int i=0; i<structureLength; i++)
            printf("*");
        printf("\n");
        printf("*");
        for(int i=0; i<structureLength-2; i++)
            printf(" ");
        printf("*");
        printf("\n");
        cout<<bigString;
        printf("\n");
        printf("*");
        for(int i=0; i<structureLength-2; i++)
            printf(" ");
        printf("*");
        printf("\n");
        printf("*   ");
        cout<<second;
        int extraSpace=bigString.length()-secondString.length();
        for(int i=0; i<extraSpace+3; i++)
            printf(" ");
        printf("*");
        printf("\n");
        printf("*");
        for(int i=0; i<structureLength-2; i++)
            printf(" ");
        printf("*\n");
        for(int i=0; i<structureLength; i++)
            printf("*");
        printf("\n");

    }
    else if(firstString.length()<secondString.length())
    {
        bigString=secondString;
        int structureLength=bigString.length();
        for(int i=0; i<structureLength; i++)
            printf("*");
        printf("\n");
        printf("*");
        for(int i=0; i<structureLength-2; i++)
            printf(" ");
        printf("*");
        printf("\n*   ");
        cout<<first;
        int extraSpace=bigString.length()-firstString.length();
        for(int i=0; i<extraSpace+3; i++)
            printf(" ");
        printf("*\n*");
        for(int i=0; i<structureLength-2; i++)
            printf(" ");
        printf("*\n");
        cout<<bigString;
        printf("\n");
        printf("*");
        for(int i=0; i<structureLength-2; i++)
            printf(" ");
        printf("*\n");
        for(int i=0; i<structureLength; i++)
            printf("*");
        printf("\n");


    }
}

int main()
{
    printf("                                      ------Welcome to  LearnPhysics world-------\n");
    printf("                                 ---------------------------------------------------------------\n");

    print_Structure("Welcome to LearnPhysics","Press ENTER to begin :");
    printf("==>>");
    cin.get();


    printf("This project will help the students who are Secondary and Higher secondary students\n");
    printf("Now we will start\n");
    printf("Choice Option that you want to perfrom\n");


    int task=1;
    initwindow(1000,600,"SPL_01" );
    setlinestyle(SOLID_LINE, 0, 4);
    //   int gd=DETECT,gm;
    // initgraph(&gd,&gm,"");


    setcolor(YELLOW);   //color for the graph
    while(task)
    {
        print_Structure("1. Projectile Motion","Press 1" );
        print_Structure("2. Vector Analysis","Press 2");
        print_Structure("3. Mechanics","Press 3");

        //  freopen("file.txt","r", stdin);
        int choice;

        printf("Choose  an Option that you want to perform\n");//add more word for highlighting this project

        scanf("%d",&choice);
        if(choice==1)
        {
            cleardevice();
            projectile_Motion();
        }
        else if(choice==2)
        {
            cleardevice();
            vector_Analysis();
        }
        else if(choice==3)
        {
            cleardevice();
            mechanics();
        }
        else
        {
            printf("Invalid choice! please try again\n");
            cin.ignore();
        }
        print_Structure("Please choose an option","For continue press 1 Exit press 0");
        scanf("%d",&task);
    }
    getch();
    closegraph();

    return 0;
}
/*
1
2
1
70
2
45
1
1
2


3
5
1
20
2
25
3
15
4
16
5
15
1
100

*/

