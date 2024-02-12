/**
 * A program to calculate credit card payoffs with daily interest.
* Author: Yash Malik
* Class: CSC161 w/ Prof. Jimenez 
* Date: Feb. 12th, 2024
*/

#include <stdio.h>
float calculations(float a,float b,float c){a+=b;a-=c;return a;}                                      /*Function to seperate interest calculation from presentation*/
int main() {
  int starting_month = 9;                                                                  /*This variable can be changed to change starting month*/
  float initial_balance =500;                                                              /*Variable to change due amount*/
  float working_balance=initial_balance;                                                   /*Seperates the variable that we are working with from the original*/
  float APR=18;                                                                            /*Variable for annual percentage rate*/
  int time=1;                                                                              /*This variabe should NOT be changed. It allows the program to run*/
  double DPR=APR/36500;                                                                   /*Changes APR to a daily rate*/
  float monthly_interest=0;                                                               /*Initializes variable for monthly interest*/
  float total_interest = 0;                                                               /*Variable keeps count of total interest*/
  float monthly_minimum=35;                                                                /*Variable can be changed to change the monthly minimum payment*/   
  printf("Cycle   Month   Interest      Payment          Balance\n");
  for (int i = 0; i < time; i++){                                               /*This loop counts the cycles*/
    if (working_balance>=monthly_minimum){                                      /*If statements runs program until the last cycle when payment is more than what is owed*/
      time+=1;
      if (starting_month==1 || starting_month==3 || starting_month==5 || starting_month==7 || starting_month==8 || starting_month==10 || starting_month==12){         /*calculates interest for months with 31 days*/
        monthly_interest=DPR*working_balance*31;
        total_interest+=monthly_interest;
        working_balance=calculations(working_balance,monthly_interest,monthly_minimum);
        printf("%d        %d        $%-.2f",i, starting_month, monthly_interest);printf("        $%.2f        $%-.2f\n", monthly_minimum,working_balance);
        starting_month+=1;
        if (starting_month==13){starting_month=1;}                                  /*If month is december, sets month to jan instead of going to 13th month which doesn't exist*/
        }
      else if (starting_month==2){                                          /*Calculates interest for febuary*/
        monthly_interest=DPR*working_balance*28;
        total_interest+=monthly_interest;
        working_balance=calculations(working_balance,monthly_interest,monthly_minimum);
        printf("%d        %d        $%-.2f",i, starting_month, monthly_interest);printf("        $%.2f        $%-.2f\n", monthly_minimum,working_balance);
        starting_month+=1;
        if (starting_month==13){starting_month=1;}                                /*If month is december, sets month to jan instead of going to 13th month which doesn't exist*/
        }
      else{                                                 /*Calculates interest for months with 30 days*/
        monthly_interest=DPR*working_balance*30;
        total_interest+=monthly_interest;
        working_balance=calculations(working_balance,monthly_interest,monthly_minimum);
        printf("%d        %d        $%-.2f",i, starting_month, monthly_interest);printf("        $%.2f        $%-.2f\n", monthly_minimum,working_balance);
        starting_month+=1;                                      /*If month is december, sets month to jan instead of going to 13th month which doesn't exist*/
        if (starting_month==13){starting_month=1;}
        }
    }
    else{                     /*Prints final cycle, when payment is more than what is owed.*/
    int days;                 /*same If loop for calculating interest as above*/
    if (starting_month==1 || starting_month==3 || starting_month==5 || starting_month==7 || starting_month==8 || starting_month==10 || starting_month==12){
      days=31;
    }
    else if (starting_month==2){
      days=28;
    }
    else{
      days=30;
    }
    monthly_interest=DPR*working_balance*days;
    total_interest+=monthly_interest;
    working_balance+=monthly_interest;
    monthly_minimum=working_balance;
    working_balance=0;
    printf("%d        %d        $%-.2f",i, starting_month, monthly_interest);printf("        $%.2f          $%.2f\n", monthly_minimum,working_balance);
    break;
    }
  }
  printf("After %d months, you paid $%.2f on an initial balance of $%.2f\n",time , total_interest + initial_balance ,initial_balance);
  return 0;
}
