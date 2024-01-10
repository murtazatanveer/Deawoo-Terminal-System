#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include"functions.h"

struct details
{

   char name[30];
   char address[50];
   char password[20];

} person[40];

struct routes{

char origin[30];
char destination[30];
int fair;
char time[20];

}rou[40];

struct seat{

 char name[30];
 char origin[30];
char destination[30];
int r_id;
int seatno;

}s;

int entered_id;
int route_id;
  
void fetch_details_from_file(){


FILE *pt = fopen("details.txt","r");

for(int i=0;i< (count_lines()/3) ;i++){

fgets(person[i].name , sizeof(person[i].name ) , pt );
fgets(person[i].address , sizeof(person[i].address ) , pt );
fgets(person[i].password , sizeof(person[i].password ) , pt );

}

fclose(pt);



}

void signup()
{
       int id;

   id = (count_lines()) / 3;

   int i;

   for (i = 0; i < 40; i++)
   {

      if ((id) == i)
      {

         printf("\nEnter Your Name : ");
         gets(person[i].name);

         printf("\nEnter Your Address : ");
         gets(person[i].address);


         
         
         while(1){
printf("\nlength of Password must be 5 digits or characters");
         printf("\nGenerate your password : ");
        gets(person[i].password);

  system("cls");


        if(strlen(person[i].password)==5){

break;

        }

printf("Password Length not meet");
         }

         FILE *ptr = fopen("details.txt", "a");

         fprintf(ptr, "%s\n%s\n%s\n", person[i].name, person[i].address, person[i].password);

         fclose(ptr);

         break;
      }
   }

 
   printf("YOUR ID is : %d\n", id+10);
   printf("YOUR PASS is : %s\n", person[i].password);

   FILE *p = fopen("id,pass.txt", "a");

   fprintf(p,"%d,%s\n", id+10, person[i].password);

   fclose(p);

   return;
}

int login()
{

   char id_pass[9];
   printf("\nEnter your ID and PASS\n\nIn format (id,pass) : ");
   gets(id_pass);

char i_d[3];

strncpy(i_d,id_pass,2);
i_d[2]='\0';

entered_id=atoi(i_d);

     char buffer[9];

   FILE *ptr = fopen("id,pass.txt", "r");

while (!feof(ptr)){
          
            fgets(buffer, sizeof(buffer), ptr);

            if((strcmp(id_pass,buffer)) == 0){

               system("cls");

            fclose(ptr);

               return 1;

            }

            
        }
   

   return 0;
}


void print_details(struct details per){

   printf("\nName       : %s",per.name);
printf("Address    : %s",per.address);
printf("ID         : %d",entered_id);
printf("\nPassword   : %s",per.password);


}

int count_lines(){

FILE *ptr = fopen("details.txt", "r");
   char ch;
 int linescounter = 0;
   
   do
   {

      ch = fgetc(ptr);

      if (ch == '\n' || ch == EOF)
      {

         linescounter++;
      }

   } while (ch != EOF);

   fclose(ptr);

   return linescounter;

}

void print_user_details(){print_details(person[entered_id-10]);}

void add_routes(){

 while (getchar() != '\n');

int route_id=(route_linescounter())/4;


for(int i=0;i<40;i++){

if(route_id == i){



printf("\nEnter Route Origin : ");
gets(rou[i].origin);
 
printf("\nEnter Route Destination : ");
gets(rou[i].destination);
 


printf("\nEnter Fair You want to Set : ");
scanf("%d",&rou[i].fair);
getchar();

printf("\nEnter Time you Want to set : ");
gets(rou[i].time);

FILE *p = fopen("rou_details.txt","a");
fprintf(p,"%s\n%s\n%d\n%s\n",rou[i].origin,rou[i].destination,rou[i].fair,rou[i].time);
fclose(p);


FILE *ptr = fopen("route.txt","a");

fprintf(ptr,"Route ID : %d , Origin : %s , Destination : %s , Fair : %d , Time : %s\n",route_id+10,
rou[i].origin,rou[i].destination,rou[i].fair,rou[i].time);


fclose(ptr);

break;

}

}

system("cls");

printf("\n____Route Added____");
printf("\n\nRoute ID is : %d\n",route_id+10);

return;

}

int route_linescounter(){

FILE *ptr = fopen("rou_details.txt", "r");
   char ch;
 int linescounter = 0;
   
   do
   {

      ch = fgetc(ptr);

      if (ch == '\n')
      {

         linescounter++;
      }

   } while (ch != EOF);

   fclose(ptr);

   return linescounter;


}


void fetch_route_details(){


FILE *ptr;
ptr = fopen("rou_details.txt","r");

if(ptr==NULL){printf("\nerrorin opening file\n");}

// for(int i=0;i<(route_linescounter() / 4) ; i++){

// fgets(rou[i].origin,sizeof(rou[i].origin),ptr);
// // puts(rou[i].origin);

// fgets(rou[i].destination,sizeof(rou[i].destination),ptr);
// // puts(rou[i].destination);

// fscanf(ptr,"%d",&rou[i].fair);
// // printf("\n%d",rou[i].fair);

// fgets(rou[i].time,sizeof(rou[i].time),ptr);
// puts(rou[i].time);
// }

for (int i = 0; i < (route_linescounter() / 4); i++) {
        
        fgets(rou[i].origin, sizeof(rou[i].origin), ptr);
        strtok(rou[i].origin, "\n"); 

      
        fgets(rou[i].destination, sizeof(rou[i].destination), ptr);
        strtok(rou[i].destination, "\n");

      
        fscanf(ptr, "%d", &rou[i].fair);
        fscanf(ptr, " "); 
        fgets(rou[i].time, sizeof(rou[i].time), ptr);
        strtok(rou[i].time, "\n"); 

    }

fclose(ptr);

}

void print_available_routes(){


printf("\nEnter Route ID: ");
scanf("%d",&route_id);

printf("\nOrigin      : %s",rou[route_id-10].origin);
printf("\nDestination : %s",rou[route_id-10].destination);
printf("\nFair        : %d",rou[route_id-10].fair);
printf("\nTime        : %s",rou[route_id-10].time);


}

void reserve_seat(){

 while (getchar() != '\n');

int view_list;

printf("\nPress 1 to view Routes List : ");
scanf("%d",&view_list);

printf("\n");
system("cls");

FILE *ptr = fopen("route.txt","r");

char buffer[200];

while(!feof(ptr)){

fgets(buffer,sizeof(buffer),ptr);

puts(buffer);

}

fclose(ptr);

printf("\n\nEnter Route ID you want to Travel : ");
scanf("%d",&s.r_id);

int a=s.r_id;

printf("\n\nYour Fair is : %d",rou[a-10].fair);

 srand((unsigned int)time(NULL));

    s.seatno = rand() % 33;

strcpy(s.name,person[entered_id-10].name);
strcpy(s.origin,rou[a-10].origin);
strcpy(s.destination,rou[a-10].destination);

int cho;
printf("\n\nPress 1 to Pay or 0 to not : ");
scanf("%d",&cho);

system("cls");

if(cho==1){

   printf("\nFair Paid Now press 1 to Print Ticket : ");
scanf("%d",&cho);
system("cls");

if(cho==1){system("cls");print_ticket();}

}
else if(cho==0){printf("\n\n\t____THANKS for Visiting Deawoo Terminal___");}

}

void print_ticket(){

printf("\n\n____Your Ticket____\n\n");

printf("Name        : %s",s.name);
printf("Origin      : %s",s.origin);
printf("\nDestination : %s",s.destination);
printf("\nRoute ID    : %d",s.r_id);
printf("\nSeat no     : %d\n",s.seatno);

}