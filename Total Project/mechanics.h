#include<bits/stdc++.h>
using namespace std;
#define originX 50
#define originY  500
#define MAX_Time 999
#define time_increment 0.1
char str_v1[50],str_v2[50],str_u1[50],str_u2[50];
double m1=-1,u1=-1,m2=-1,u2=-1,v1=-1,v2=-1;


void  graph_for_momentum_simulation(double m1,double u1,double m2,double u2,double m,double v,double finalV,int condition);
void graphcal_representation_of_mechanics( double m1,double u1,double m2,double u2,double m,double v,double finalV);
double conservation_of_momentum(double m1,double u1,double m2,double u2,double v,double m);
double combined_velocity(double m1,double u1,double m2,double u2);





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
   while(k){
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

