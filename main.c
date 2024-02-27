#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

int main(){

char  str_1[300] = "\n\t\tWelcome to Deawoo Terminal\n\n";

printToConsole(str_1);

int choice;

char  str_2[300] = "1. Admin\n2. Customer\n\n Choice : ";

printToConsole(str_2);

scanf("%d",&choice);
getchar();

system("cls");

int a;
// Admin code.................................

if(choice==1){

char  str_3[300] = "\nPress L for login or S for Signup\n";

printToConsole(str_3);

char c;

char  str_4[300] = "\nChoice : ";

printToConsole(str_4);

scanf("%c",&c);
getchar();

system("cls");

if(c=='S'||c=='s'){

signup();


char str_5[300] = "\nPress 1 for login : ";

printToConsole(str_5);

scanf("%d",&a);
getchar();

}

if(c=='l'||c=='L'||a==1){

if (login()){

    char str_6[300] = "\n_______LogIn Successfully______";

printToConsole(str_6);

fetch_details_from_file();
fetch_route_details();


char str_7[2000] = "\n\n1. View Your Account Details.\n2. Check Available Routes.\n3. Add New Routes.\n\n Choice : ";

printToConsole(str_7);

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

else{

char str_8[1500] = "\n_____Incorrect ID or Password_____";

printToConsole(str_8);

}
  
}

}

// customer code...............................

if(choice==2){

char  str_9[300] = "\nPress L for login or S for Signup\n";

printToConsole(str_9);

char c;
printf("\nChoice : ");
scanf("%c",&c);
getchar();

int a;

system("cls");

if(c=='S'||c=='s'){

signup();

char str_10[300] = "\nPress 1 for login : ";

printToConsole(str_10);

scanf("%d",&a);
getchar();

}

if(c=='l'||c=='L'||a==1){

if (login()){

    char str_11[300] = "\n_______LogIn Successfully______";

printToConsole(str_11);

fetch_details_from_file();
fetch_route_details();

char str_12[1500] = "\n\n1. View Your Account Details.\n2. Reserve Seat.\n\n Choice : ";
printToConsole(str_12);

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

else{
    char str_8[1500] = "\n_____Incorrect ID or Password_____";

printToConsole(str_8);}

}

// end
}

}



