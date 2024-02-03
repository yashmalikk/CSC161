/*
* Author: Yash Malik
* Class: CSC161 w/ Prof. Jimenez 
* Date: Feb. 3rd, 2024
* Function: Theatre ticket price calculator 
*/
#include <stdio.h>
#include <string.h> /*Needed for strcpy()*/
int main(){
    int a;              /*Initializing age variable*/
    int total=0;        /*Initializing total charge variable*/
    int p = 0;          /*Initializing charge per person variable*/
    int s;              /*Initializing section of theatre variable*/
    int t;              /*Initializing time of day variable*/
    int n;              /*Initializing number of tickets variable*/
    char time[20];      /*Initializing time of day string variable*/
    char sec[20];       /*Initializing section of theatre string variable*/
    printf("Enter number of tickets: ");
    scanf("%d", &n);
    if (n>0){                                           /*Verifying that a positive number of tickets has been entered*/
        while(n!=0)                                     /*Runs code the number of times a person wants a ticket*/
        {
            printf("Enter time of show: (1 for maintee, 2 for evening): ");
            scanf("%d", &t);
            if (t==1){                                   /*Factors in time of day to ticket price*/
                strcpy(time, "Matinee");
                p-=n*5;
            }
            else if (t==2){
                strcpy(time, "Evening");
            }
            else{
                printf("Not a valid time selection.");
            }
            
            printf("Which section would you like to seat in (Enter 1 for Main floor - middle section, 2 for Main floor - sides and 3 for Balcony): ");
            scanf("%d", &s);
            if (s==1){                                   /*Factors in section of theatre to ticket price*/
                strcpy(sec, "Main mid.");
                p+=30;
            }
            else if (s==2)
            {
                strcpy(sec,"Main side");
                p+=25;
            }
            else if (s==3)
            {
                strcpy(sec, "Balcony");
                p+=20;
            }
            else{
                printf("Invalid section picked");
            }

            printf("How many years old is the viewer: ");               /*Factors in age to ticket price*/
            scanf("%d", &a);
            if (a>-1 && a<151){
                if (a<6){
                    printf(" Ticket is free for viewers under 5!\n");
                    p=0;
                }
                else if (a>5 && a<11 || a>54)
                {
                    p-=5;
                    
                }
                
            }
            else{
                printf("Invalid age entered.(Age should be no more than 150) \n");

            }
            n--;
            printf("************************************************\n");                                       /*Prints details entered and price for 1 ticket*/
            printf("Age:    %d  Type of Show:   %s  Theatre Section:    %s\n", a, time,sec);
            printf("Price for this ticket: $%d.00\n", p);
            printf("************************************************\n");
            total+=p;
            p=0;
            }
        }
    

    else{
        printf("Invalid number entered(Cannot buy negative tickets) \n");
    }


    printf("Total price for order is: $%d.00", total);                  /*Prints total order value*/
    return 0;
}