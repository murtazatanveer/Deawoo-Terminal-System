#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"functions.h"

struct details
{

   char name[30];
   char address[50];
   char password[20];

} person[40];

struct routes{

char origin[20];
char destination[20];
int fair;

}rou[40];

int entered_id;
  
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

while (1)
        {
          

            fgets(buffer, sizeof(buffer), ptr);

            if((strcmp(id_pass,buffer)) == 0){

               system("cls");

            fclose(ptr);

               return 1;

            }

            if (strlen(buffer) == 0)
            {
                break;
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

FILE *ptr = fopen("route.txt","a");

for(int i=0;i<40;i++){

    
}



}