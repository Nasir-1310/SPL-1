#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
//#define  height_of_projectile(v0,theta,time,aacceleration) ((v0)*sin(theta)*(time)+0.5*(aacceleration)*(time)*(time))
//#define horizontal_distance_of_projectile(v0,theta,time)  (v0*cos(theta)*time)
using namespace std;

void projectile_Motion()
{
    printf("Welcome to Dynamics\n");



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
    printf("Welcome to Geometrical Optics\n");


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
            printf("*\n");
            printf("*   ");
            cout<<second;
            int extraSpace=bigString.length()-secondString.length();
            for(int i=0;i<extraSpace+3;i++)
                printf(" ");
            printf("*\n*");
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

int main()
{
    printf("                                      ------Welcome to  LearnPhysics game world-------\n");
    printf("                                 ---------------------------------------------------------------\n");

   print_Structure("Welcome to LearnPhysics","Press ENTER to begin :");
   printf("==>>");
   cin.get();
   print_Structure("1. Projectile Motion","Press 1" );
   print_Structure("2. Vector Analysis","Press 2");
   print_Structure("3. Mechanics","Press 3");
   print_Structure("4. Geometrical Optics","Press 4");
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
          circle(horizontal_distance+100,height+100,10);
          swapbuffers();
          time+=1.00;
         delay(100);
      }


    getch();
    closegraph();
*/

printf("i am end\n");

    return 0;
}

/*
20
-9.8
90
0
*/
