#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
using namespace std;
void print_Structure(string first,string second);
double Tmaximum(double v0,double theta,double g);
double Rmaximum(double v0,double theta,double g);
double Hmaximum(double v0,double theta,double g);


//#define  height_of_projectile(v0,theta,time,aacceleration) ((v0)*sin(theta)*(time)+0.5*(aacceleration)*(time)*(time))
//#define horizontal_distance_of_projectile(v0,theta,time)  (v0*cos(theta)*time)

void   graph(double v0,double theta,double g)
{

    if(v0==-1 && theta==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and theta(with respect to horizontal)\n");
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
    }
    else if(theta==-1)
    {
        printf("Sorry theta(with respect to horizontal) is not given\n");
    }
   else
    {
       double Ttotal;
       Ttotal=Tmaximum(2*v0,theta,g);
       double t=0;
       // int gd=DETECT,gm;
   // initgraph(&gd,&gm,"");
    double x,y,y1,increment=0.2;
    printf("Time(t)\t Horizontal Range(R)\t Height(H)\n");
  //  line(10,450,Rmaximum(v0,theta,g),Hmaximum(v0,theta,g));
       while(t<=Ttotal)
       {

           x=v0*cos(theta)*t;
           y=(v0*sin(theta)*t)-(0.5*g*t*t);

           y1=-y;
           printf("%lf     %lf     %lf\n",t,x,y);
            cleardevice();
           circle(x+10,(y1+450),12);
          swapbuffers();
          t+=increment;
         delay(50);

       }


        x=v0*cos(theta)*Ttotal;
        y=(v0*sin(theta)*Ttotal)-(0.5*g*Ttotal*Ttotal);
        printf("%lf     %lf     %lf\n",Ttotal,x,y);
        circle(x+10,(y1+450),12);
        line(10,450,Rmaximum(v0,theta,g)+10,450);
        //   closegraph();

    }
}


//Function for finding Tmax
double Tmaximum(double v0,double theta,double g)
{

    if(v0==-1 && theta==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and theta(with respect to horizontal)\n");
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
    }
    else if(theta==-1)
    {
        printf("Sorry theta(with respect to horizontal) is not given\n");
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
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
    }
    else if(theta==-1)
    {
        printf("Sorry theta(with respect to horizontal) is not given\n");
    }
    else
    {
       double R_max=((v0*v0*sin(2*theta))/g);
      // printf("Maximum height Rmax is : %lf\n",R_max);

       return  R_max;
       // graph(v0,theta,g)


       // ----------------------------------

    }
}


//Function for Hmax
double Hmaximum(double v0,double theta,double g)
{

    if(v0==-1 && theta==-1 )
    {
        printf("Not enough Information\nPlease give the value for v0(initial velocity) and theta(with respect to horizontal)\n");
    }
    else if(v0==-1)
    {
        printf("Sorry ! v0(initial velocity) is not given\n");
    }
    else if(theta==-1)
    {
        printf("Sorry ! theta(with respect to horizontal) is not given\n");
    }
    else
    {
        double H_max=(v0*v0*pow(sin(theta),2)/(2*g));
       // graph(v0,theta,g);
      // printf("Maximum height Hmax is : %lf\n",H_max);

       return H_max;


       // ----------------------------------

    }
}
void projectile_Motion()
{
    printf("Welcome to Dynamics\n");
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
     line(10,450,Rmaximum(v0,theta,g)+10,450);

    int operation;
    scanf("%d",&operation);
    if(operation==1){
      Rmax= Rmaximum(v0,theta,g);
      print_Structure("Used formula","Rmax=(((vo^2)*sin(2*theta))/g)");
     printf("Maximum height Rmax is : %lf\n",Rmax);
    }
    else if(operation==2){
        Hmax=Hmaximum(v0,theta,g);
        print_Structure("Used formula","Hmax=(vo^2*sin(theta)^2)/(2*g)");
        printf("Maximum height Hmax is : %lf\n",Hmax);

    }
     else if(operation==3){
        Tmax= Tmaximum(v0,theta,g);
        print_Structure("Used formula","Tmax=(vo*sin(theta)/g)");
         printf("Maximum Time  Tmax is : %lf\n",Tmax);
     }
    else if(operation==4){
        Tmax=Tmaximum(2*v0,theta,g);
        print_Structure("Used formula","Tmax=(2*vo*sin(theta)/g)");
        printf("Maximum Time  2*Tmax is : %lf\n",Tmax);
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
void vector_Analysis()
{
    printf("Welcome to Vector world\n");


    return;
}
void Mechanics()
{
    printf("Welcome to Mechanics\n");


    return;
}
void geometrical_Optics()
{
    printf("Welcome to  Optics world\n");


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
          for(int i=0;i<structureLength;i++)
            printf("*");
            printf("\n");
          printf("*");
          for(int i=0;i<structureLength-2;i++)
            printf(" ");
            printf("*");
            printf("\n");
            cout<<bigString;
            for(int i=0;i<structureLength-2;i++)
                printf(" ");
            printf("*");
            printf("\n");
            printf("*   ");
            cout<<second;
            int extraSpace=bigString.length()-secondString.length();
            for(int i=0;i<extraSpace+3;i++)
                printf(" ");
            printf("*");
            printf("\n");
            printf("*");
            for(int i=0;i<structureLength-2;i++)
                printf(" ");
                printf("*\n");
                for(int i=0;i<structureLength;i++)
                    printf("*");
            printf("\n");

      }
      else if(firstString.length()<secondString.length())
      {
          bigString=secondString;
          int structureLength=bigString.length();
          for(int i=0;i<structureLength;i++)
            printf("*");
            printf("\n");
          printf("*");
          for(int i=0;i<structureLength-2;i++)
            printf(" ");
            printf("*");
            printf("\n*   ");
            cout<<first;
            int extraSpace=bigString.length()-firstString.length();
            for(int i=0;i<extraSpace+3;i++)
                printf(" ");
            printf("*\n*");
            for(int i=0;i<structureLength-2;i++)
                printf(" ");
            printf("*\n");
            cout<<bigString;
            printf("\n");
            printf("*");
            for(int i=0;i<structureLength-2;i++)
                printf(" ");
                printf("*\n");
                for(int i=0;i<structureLength;i++)
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
   print_Structure("1. Projectile Motion","Press 1" );
   print_Structure("2. Vector Analysis","Press 2");
   print_Structure("3. Mechanics","Press 3");
   print_Structure("4. Geometrical Optics","Press 4");
   int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
   int choice;

    printf("Choose Your an Option that you want to perform\n");//add more word for highlighting this project

   scanf("%d",&choice);
   if(choice==1)
    projectile_Motion();
   else if(choice==2)
    vector_Analysis();
   else if(choice==3)
    Mechanics();
   else if(choice==4)
    geometrical_Optics();



/*

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
          circle(horizontal_distance+100,height+100,10);
          swapbuffers();
          time+=1.00;
         delay(100);
      }


    getch();
    closegraph();
*/

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
