 #include <bits/stdc++.h>
#include<graphics.h>
#include "print_Structure.h"
#include "projectile_Motion.h"
#include "vector_Analysis.h"
#include "mechanics.h"


using namespace std;

#define originX 50
#define originY  500
#define MAX_Time 999
#define time_increment 0.1
//double m1,m2,u1,u2,v1,v2;

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
    while(task){
    print_Structure("1. Projectile Motion","Press 1" );
    print_Structure("2. Vector Analysis","Press 2");
    print_Structure("3. Mechanics","Press 3");

  //  freopen("file.txt","r", stdin);
    int choice;

    printf("Choose an Option that you want to perform\n");//add more word for highlighting this project

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
