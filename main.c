#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

int main(){

printf("\n\t\tWelcome to Deawoo Terminal\n\n");

int choice;
printf("1. Admin\n2. Customer\n\n Choice : ");
scanf("%d",&choice);
getchar();

system("cls");

if(choice==1){

printf("\nPress L for login or S for Signup\n");

char c;
printf("\nChoice : ");
scanf("%c",&c);
getchar();

int a;

system("cls");

if(c=='S'||c=='s'){

signup();


printf("\nPress 1 for login : ");
scanf("%d",&a);
getchar();

}

if(c=='l'||c=='L'||a==1){

if (login())
{
    printf("\n_______Log In Successfully______");

fetch_details_from_file();

printf("\n\n1. View Your Account Details\n2. Add New Routes\n3. Update Fair\n\n Choice : ");
scanf("%d",&a);

switch(a){

    case 1:
    system("cls");
print_user_details();
break;

case 2:
 system("cls");
add_routes();

}

}

else{printf("\n_____Incorrect ID or Password_____");}
  
}

}

}
