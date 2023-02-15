#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
using namespace std;
void print_Structure(string first,string second);
double Tmaximum(double v0,double theta,double g);
double Rmaximum(double v0,double theta,double g);
double Hmaximum(double v0,double theta,double g);


void   graph(double v0,double theta,double g)
{

    if(v0==-1 && theta==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and theta(with respect to horizontal)\n");
        return;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return;
    }
    else if(theta==-1)
    {
        printf("Sorry theta(with respect to horizontal) is not given\n");
        return;
    }
    else
    {
        double Ttotal;
        Ttotal=Tmaximum(2*v0,theta,g);
       // double t_half=Ttotal/2;
        double t=0;
        // int gd=DETECT,gm;
        // initgraph(&gd,&gm,"");
        double x,y,y1,increment=0.2;

        print_Structure("Are you want to show step by step calculation?","If Yes press 1 otherwise press 2");
        int option;

        scanf("%d",&option);
        if(option==1)
            printf("Time(t)\t Horizontal Range(R)\t Height(H)\n");
        double Rmax=Rmaximum(v0,theta,g);
        double arcx=(((Rmax)/2)+15);
        double arcy=453,radious;
        double xcoordinate,ycoordinate;

        while(t<=Ttotal)
        {

            x=v0*cos(theta)*t;
            y=(v0*sin(theta)*t)-(0.5*g*t*t);

            y1=-y;

               cleardevice();
              //rectangle(60+x,350+y1,90+x,380+y1);
              line(15,453,620,453);
            circle((x+15),(y1+450),12);
            xcoordinate=pow((arcx-x-15),2);
            ycoordinate=pow((arcy-y-453),2);
            radious=pow((xcoordinate+ycoordinate),0.5);

            //arc(arcx,arcy,-0,-180,radious);
            swapbuffers();
            t+=increment;
            delay(60);

        }


        x=v0*cos(theta)*Ttotal;
        y=(v0*sin(theta)*Ttotal)-(0.5*g*Ttotal*Ttotal);
        y1=-y;
        if(option==1)
        printf("%lf     %lf     %lf\n",Ttotal,x,y);

       // rectangle(x+10,,x+30,(y1+400),(y1+380));
         circle((x+15),(y1+450),12);
       // rectangle(60+x,350+y1,90+x,380+y1);
          line(15,453,400,453);


    }
    return;
}


//Function for finding Tmax
double Tmaximum(double v0,double theta,double g)
{

    if(v0==-1 && theta==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and theta(with respect to horizontal)\n");
        return 0;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return 0;
    }
    else if(theta==-1)
    {
        printf("Sorry theta(with respect to horizontal) is not given\n");
        return 0;
    }
    else
    {
        double T_max=(v0*sin(theta))/g;
        // printf("Maximum Time  Tmax is : %lf\n",T_max);
        return  T_max;


    }
}
//Function for Rmax
double Rmaximum(double v0,double theta,double g)
{
    if(v0==-1 && theta==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and theta(with respect to horizontal)\n");
        return 0;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return 0;
    }
    else if(theta==-1)
    {
        printf("Sorry theta(with respect to horizontal) is not given\n");
        return 0;
    }
    else
    {
        double R_max=((v0*v0*sin(2*theta))/g);
        // printf("Maximum height Rmax is : %lf\n",R_max);

        return  R_max;
        // graph(v0,theta,g)


    }
}


//Function for Hmax
double Hmaximum(double v0,double theta,double g)
{

    if(v0==-1 && theta==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and theta(with respect to horizontal)\n");
        return 0;
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
        return 0;
    }
    else if(theta==-1)
    {
        printf("Sorry ! theta(with respect to horizontal) is not given\n");
        return 0;
    }
    else
    {
        double H_max=(v0*v0*pow(sin(theta),2)/(2*g));
        // graph(v0,theta,g);
        // printf("Maximum height Hmax is : %lf\n",H_max);

        return H_max;


    }
}
void projectile_Motion()
{
    print_Structure("Welcome to Dynamics world here you will find solution of your desire problem with visualization","  ");
    printf("Enter how many parameter you know\n");
    int Number_of_parameter;
    double Hmax,H,Rmax,g=9.8,Tmax,theta,v0,R,t;
    H=theta=v0=R=Hmax=Rmax=Tmax=t=-1;
    int choice,known;

    scanf("%d",&Number_of_parameter);
    known=Number_of_parameter;
    while(known--)
    {
        if(v0==-1)
            print_Structure("1. Initial velocity(m/s)","Press 1");
        if(theta==-1)
            print_Structure("2. Angle(with respect to horizontal)","Press 2");
        if(t==-1)
            print_Structure("3. Time","Press 3");

        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter Initial velocity(v0)\n");
            scanf("%lf",&v0);
        }

        else if(choice==2)
        {
            printf("Enter angle with respect to Horizontal\n");
            scanf("%lf",&theta);
            theta=(M_PI*theta)/180;
        }
        else if(choice==3)
        {
            printf("Enter time in which you want to see velocity\n ");
            scanf("%lf",&t);
        }


    }
    printf("What do you want to determine\n");
    print_Structure("1. Maximum horizontal Range(Rmax)","Press 1");
    print_Structure("2. Maximum Height(Hmax)","Press 2");
    print_Structure("3. Time to reach Maximum height(Tmax)","Press 3");
    print_Structure("4. Total Time(2Tmax)","Press 4");
    line(10,450,600,450);

    int operation;
    scanf("%d",&operation);
    if(operation==1)
    {
        Rmax= Rmaximum(v0,theta,g);
        if(Rmax!=0)
        {
        print_Structure("Used formula","Rmax=(((vo^2)*sin(2*theta))/g)");
        printf("Maximum height Rmax is : %lf\n",Rmax);
        }
    }
    else if(operation==2)
    {
        Hmax=Hmaximum(v0,theta,g);
        if(Hmax!=0){
        print_Structure("Used formula","Hmax=(vo^2*sin(theta)^2)/(2*g)");
        printf("Maximum height Hmax is : %lf\n",Hmax);
        }

    }
    else if(operation==3)
    {
        Tmax= Tmaximum(v0,theta,g);
        if(Tmax!=0)
        {
        print_Structure("Used formula","Tmax=(vo*sin(theta)/g)");
        printf("Maximum Time  Tmax is : %lf\n",Tmax);
        }
    }
    else if(operation==4)
    {
        Tmax=Tmaximum(2*v0,theta,g);
        if(Tmax!=0){
        print_Structure("Used formula","Tmax=(2*vo*sin(theta)/g)");
        printf("Maximum Time  2*Tmax is : %lf\n",Tmax);
        }
    }
    else
        printf("Invalid choice!\n");


    //graph implementation
    print_Structure("Are you want to visualize the graph", "if Yes press 1 Otherwise press 2");
    int option;
    scanf("%d",&option);
    if(option ==1)
        graph(v0,theta,g);




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
//Vector analysis
void vector_Analysis()
{
    print_Structure("Welcome to Vector world ! Here you will find solution of your desire problem with visualization"," ");
    double vBoat=-1,vFlow=-1,alpha=-1,Angle,R;
    int t;
    printf("\nEnter number of known parameter\n");
    scanf("%d",&t);
    while(t--){
        if(vBoat==-1)
            print_Structure("1. Velocity of Boat(m/s)","Press 1");
        if(alpha==-1)
            print_Structure("2. Alpha(with respect to flow)","Press 2");
        if(vFlow==-1)
            print_Structure("3. Velocity of Flow","Press 3");
         int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter Velocity of Boat(m/s)\n");
            scanf("%lf",&vBoat);
        }

        else if(choice==2)
        {
            printf("Enter angle with respect to Flow(m/s)\n");
            scanf("%lf",&alpha);
           alpha=(M_PI*alpha)/180;
        }
        else if(choice==3)
        {
            printf("Enter Velocity of Flow\n ");
            scanf("%lf",&vFlow);
        }
    }

    printf("What do you want ? choice an option\n");
    print_Structure("Resultant velocity of a Boat"," Press ->>1");
    print_Structure("Angle among with resultant velocity and flow","Press->>2");
    print_Structure("Both Resultant velocity and angle","Press->>3");

    int operation;
    scanf("%d",&operation);
     if(operation==1)
    {
        R= R_resultant(vBoat,vFlow,alpha);
        if(R!=0)
        {
        print_Structure("Used formula","R=Pow(p^2+q^2+2*p*q*cos(alpha),0.5)");
        printf("Resultant velocity of Boat is  : %lf\n",R);
        return;
        }
    }

    else if(operation==2)
    {
        Angle=Angle_of_boat_with_respect_to_flow(vBoat,vFlow,alpha);
        if(Angle!=0){
                Angle=(Angle*180)/M_PI;
                print_Structure("Used formula","tan(theta)=(q*sin(alpha))/(p+q*cos(alpha))");
                printf("Angle among Resultant velocity and flow is : %lf\n",Angle);
                return;
        }

    }
    else if(operation==3)
    {
       double R= R_resultant(vBoat,vFlow,alpha);
      Angle=Angle_of_boat_with_respect_to_flow(vBoat,vFlow,alpha);
        if(R!=0 && Angle!=0)
        {
            Angle=(180*Angle)/M_PI;

        print_Structure("Used formula","R=Pow(p^2+q^2+2*p*q*cas(alpha),0.5) and (tan(theta)=(q*sin(alpha))/(p+q*cos(alpha)) )");
                printf("Resultant velocity of Boat is  : %lf\n",R);
                printf("Angle among Resultant velocity and flow is : %lf\n",Angle);


        }
    }



    return;
}

double conservation_of_momentum(double m1,double u1,double m2,double u2,double v,double m)
{
   // printf("m1=%lf u1=%lf m2=%lf u2=%lf v=%lf m=%lf\n",m1,u1,m2,u2,v,m);
    print_Structure("Are you want to visualize the graph", "if Yes press 1 Otherwise press 2");
     int option;
    scanf("%d",&option);
    if(option ==1)
      //  graph();// visualization start


    double finalV=((m1*u1)+(m2*u2));
    //printf("m+m is %lf\n",finalV);
    double finalV=finalV-(v*m);
    //printf("m-mv is %lf\n",finalV);

   // finalV=finalV/(m1+m2-m);
    printf("v=%lf\n",finalV);
    return finalV;
}

// Function of Mechanics
void Mechanics()
{
    print_Structure("Welcome to Newtonian Mechanics ! Here you will be able to solve to related question of conservation of Momentum"," ");

    double m1,m2,u1,u2,v1,v2;
     double p=u2;
    m1=u1=m2=u2=v1=v2=-1;
      int choice;
    int t;
    printf("\nEnter number of known parameter\n");
    scanf("%d",&t);
    while(t--){
        if(m1==-1)
            print_Structure("1. Mass of 1st object(kg)","Press 1");
        if(u1==-1)
            print_Structure("2. Initial velocity of 1st object (m/s)","Press 2");
        if(m2==-1)
            print_Structure("3. Mass of 2nd  object(kg)","Press 3");
        if(u2==-1)
            print_Structure("4. Initial velocity of 2nd object(m/s)","Press 4");
        if(v1==-1)
                print_Structure("5. Final velocity of the 1st object","Press 5");
        if(v2==-1)
                print_Structure("6. Final velocity of the 2nd object","Press 6");


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
            printf("Mass of the 2nd object\n ");
            scanf("%lf",&m2);
        }
        else if (choice==4)
        {
            printf("Initial velocity of the 2nd element\n");
            scanf("%lf",&u2);


        }
        else if(choice==5)
        {

            printf("Final velocity of the the 1st object\n");
            scanf("%lf",&v1);
        }
        else if(choice==6)
        {
            printf("Final velocity of the 2nd object\n");
            scanf("%lf",&v2);
        }

    }
    double finalV;
    if(v1==-1)
    {
         finalV=conservation_of_momentum(m1,u1,m2,u2,v2,m2);
        if(finalV!=0)
        {
            printf("Final velocity of the 1 st object is : %lf\n",finalV);
            return;
        }
    }
    else {

         finalV=conservation_of_momentum(m1,u1,m2,u2,v1,m1);
          if(finalV!=0)
        {
            printf("Final velocity of the 2 nd object is : %lf\n",finalV);
            return;
        }
    }




    return;
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

    int task=1;
     int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    while(task){
    print_Structure("1. Projectile Motion","Press 1" );
    print_Structure("2. Vector Analysis","Press 2");
    print_Structure("3. Mechanics","Press 3");

  //  freopen("file.txt","r", stdin);
    int choice;

    printf("Choose Your an Option that you want to perform\n");//add more word for highlighting this project

    scanf("%d",&choice);
    if(choice==1)
    {
        projectile_Motion();
    }
    else if(choice==2)
    {
        vector_Analysis();
    }
    else if(choice==3)
    {
        Mechanics();
    }
    else
    {
        printf("Invalid choice! please try again\n");

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
*/


