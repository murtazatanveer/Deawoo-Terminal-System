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

int a;
// Admin code

if(choice==1){

printf("\nPress L for login or S for Signup\n");

char c;
printf("\nChoice : ");
scanf("%c",&c);
getchar();



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
    printf("\n_______LogIn Successfully______");

fetch_details_from_file();
fetch_route_details();

printf("\n\n1. View Your Account Details.\n2. Check Available Routes.\n3. Add New Routes.\n\n Choice : ");
scanf("%d",&a);

switch(a){

    case 1:
    system("cls");
print_user_details();
break;

case 3:
 system("cls");
add_routes();
break;

case 2:
system("cls");
print_available_routes();
break;
}

}

else{printf("\n_____Incorrect ID or Password_____");}
  
}

}

// customer code

if(choice==2){

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
    printf("\n_______LogIn Successfully______");

fetch_details_from_file();
fetch_route_details();

printf("\n\n1. View Your Account Details.\n2. Reserve Seat.\n\n Choice : ");
scanf("%d",&a);

switch(a){

    case 1:
    system("cls");
   print_user_details();
    break;

case 2:
 system("cls");
reserve_seat();
break;

}

}

else{printf("\n_____Incorrect ID or Password_____");}


}


// end
}

}



