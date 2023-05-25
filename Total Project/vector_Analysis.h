#include<bits/stdc++.h>
using namespace std;

#define originX 50
#define originY  500
#define MAX_Time 999
#define time_increment 0.1
#define river_magnificent 350
char str_vBoat[30], str_vFlow[30],str_river_wide[30],str_angle[20],str_theta[20],str_resultant_V[30],str_time[30],str_displacement[30];
//int operation,resultant_V;
int resultant_V;


double R_resultant(double vBoat,double vFlow,double alpha);
double  Angle_of_boat_with_respect_to_flow(double vBoat,double vFlow,double alpha);
double time_cross_river(double vBoat,double  alpha,double width_of_the_river);
void  vector_graph(double vBoat,double vFlow,double alpha,double width_of_the_river);



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
     outtextxy(xcoordinate+15,ycoordinate+40,str_resultant_V);

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



