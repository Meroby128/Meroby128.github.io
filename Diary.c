	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdbool.h>
	#include <string.h>
	
	int enter;
	int choice;
	int diaryNumber;
	char diaryName[100]={'\0'},diaryName1[100];
	char review[100], content[100];
	char account;
	char passWord[100],userName[100];
	char passWord1[100],userName1[100];
	int n=3;
	bool x = true;
	void fancyPrintf(char fps[]){
	int i;
	for(i=0;i<strlen(fps);i++){
	printf("%c",fps[i]);
	usleep(1000);
	}
	
	}
	
	void UserName(){
	FILE *id;
	id=fopen("userName.txt","w");
	fprintf(id,"%s",userName);
	fclose(id);
	}
	void Password(){
	FILE *pass;
	pass=fopen("password.txt","w");
	fprintf(pass,"%s",passWord);
	fclose(pass);
	}
	void Check(){
	FILE *id;
	FILE *pass;
	id=fopen("userName.txt","r");
	pass=fopen("password.txt","r");
	fgets(userName,sizeof(userName),id);
	fgets(passWord,sizeof(passWord),pass);
	fclose(id);
	fclose(pass);
	if(strcmp(userName,userName1)==0 && strcmp(passWord,passWord1)==0 ){
	sleep(1);
	system("cls");
	printf("\n\nENTANCE IS SUCCESSFULLY :)");
	x=false;
	sleep(1);
	system("cls");
	}
	else{
	system("cls");
	printf("\n USERNAME OR PASSWORD IS WRONG :(\n");
	sleep(2);
	system("cls");
	while(x && n>0){
		printf("\n\n You have %d chances to try so ",n);
		n--;
			printf("Please enter username and password corectly.. \n\n");
	printf("|||||||||||||||||||||||||\n");
	printf("|||||| USERNAME |||||||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
	scanf(" %s",&userName1);
	printf("------------------------\n");
	printf("\n\n|||||||||||||||||||||||||\n");
	printf("||||||| PASSWORD ||||||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
		scanf(" %s",&passWord1);
	printf("------------------------\n");
	Check();
		
	}
	if(n==0){
		printf("\n\nSORRY SYSTEM IS CLOSED :(");
		exit(-1);
	}
	}
	}
	void Entrance(){
	printf("**********************************************************************\n");
	printf("************************ WELLCOME TO DIARY ***************************\n");
	printf("**********************************************************************\n\n");
	fancyPrintf((char*)"Hello !!! ...\n");
	fancyPrintf((char*)"This system was made to write diaries day by day...\n");
   fancyPrintf((char*)"Also you can manage your diary like rewrite,read,delete....\n");
	fancyPrintf((char*)"So let's gets started.\n");
	fancyPrintf((char*)"Do you have account? <Y/N> ");
	scanf("%c",&account);
	system("cls");
	if(account=='y' || account=='Y'){
	printf("\n\nHelllo !!\n\n");
	printf("Please enter your user name password to go on\n\n");
	printf("|||||||||||||||||||||||||\n");
	printf("|||||| USERNAME |||||||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
	scanf(" %s",&userName1);
	printf("------------------------\n");
	printf("\n\n|||||||||||||||||||||||||\n");
	printf("||||||| PASSWORD ||||||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
		scanf(" %s",&passWord1);
	printf("------------------------\n");
	Check();
	
	}
	else{
	fancyPrintf("\n\nHelllo !!\n\n");
	fancyPrintf("Let's create new account..\n\n");
	printf("please enter user name:\n");
	printf("|||||||||||||||||||||||||\n");
	printf("|||||| USERNAME |||||||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
	scanf(" %s",&userName);
	printf("------------------------\n");
	printf("\nplease enter Password:\n");
	printf("|||||||||||||||||||||||||\n");
	printf("||||||| PASSWORD ||||||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
		scanf(" %s",&passWord);
	printf("------------------------\n");
	sleep(2);
	system("cls");
	printf("\n\n ACCOUNT IS CREATING");
	printf("!");sleep(1);printf("!");sleep(1);printf("!");sleep(1);
	
	
	system("cls");
	printf("\n\n ACCOUNT CREATED SUCCESSFULLY !");
	sleep(2);
	
	system("cls");
	UserName();
	Password();
	
	}
	
	printf("\nPlease enter to '0' to go MAIN MENU... ");
	scanf(" %d",&enter);
	system("cls");
	
	}
	int Menu(){
	printf("\n\n\n       MAIN MENU:  \n");
	printf("    MAKE NEW DIARY:   [1]\n");
	printf("    VIEW  RECORD:     [2]\n");
	printf("    EDIT RECORD:      [3]\n");
	printf("    EDIT PASSWORD:    [4]\n");
	printf("    EXIT              [5]\n\n");
	printf("              ENTER YOUR CHOICE: ");
	scanf(" %d",&choice);
	system("cls");
	return choice;
	}
	void Selection(int selection){
	   FILE *fpnt;
	   char date[100],note[100],time[10],place[50];
	switch(selection){
	case 1:
	
	   
	
		fancyPrintf((char*)"\n                              MAKE NEW DIARY    \n");
		fancyPrintf((char*)"---------------------------------------------------------------------------------------\n\n");
	
		printf("DIARY NUMBER:");scanf(" %d",&diaryNumber);
		sprintf(diaryName,"diary%d.txt",diaryNumber);
	
		fpnt=fopen(diaryName, "w");
		fprintf(fpnt,"DIARY NAME %s",diaryName);
	
		printf("DATE:[dd-mm-yyyy]: ");
		fflush(stdin);
		fgets(date,sizeof(date),stdin);
		fprintf(fpnt,"\nDATE %s",date);
	
		printf("\nTIME: ");
	     fgets(time,sizeof(time),stdin);
		fprintf(fpnt,"TIME %s",time);
	
		printf("\nPLACE: ");
	     fgets(place,sizeof(place),stdin);
		fprintf(fpnt,"PLACE %s",place);
	
		printf("\n\n \t\t\t\t\t\tWRITE YOUR DIARY:\n");
		fgets(note,sizeof(note),stdin);
		fprintf(fpnt,"NOTE %s",&note);
	
		fclose(fpnt);
	
		system("cls");
	
		printf("---------------------------------------------------------------------------------------\n\n");
		printf("------------------------ %d DIARY CREATED SUCCESSFULLY :) -----------------------------\n\n",diaryNumber);
		printf("---------------------------------------------------------------------------------------\n\n");
	
		sleep(1);
	
		printf("\n Please enter '0' to go MAIN MENU ");
		scanf(" %d",&enter);
	
		system("cls");
	
		Selection(Menu());
	
		break;
	case 2: 
		printf("---------------------------------------------------------------------------------------\n");
		printf("\n                              REVIEW DIARY   \n");
		printf("---------------------------------------------------------------------------------------\n\n");
	
		printf("Please enter the number of diary you want to display");
	
		scanf(" %d",&diaryNumber);
		sprintf(diaryName,"diary%d.txt",diaryNumber);
	
		if ((fpnt = fopen(diaryName, "r")) == NULL) {
	
			printf("Error! File cannot be opened.");
			// Program exits if the file pointer returns NULL.
			exit(-1);
		}
	
		while(!feof(fpnt)){
			fread(content, sizeof(content), 1, fpnt);
			printf("\n%s",content);
		}
	
		fclose(fpnt);
			sleep(1);
	
		printf("\n Please enter '0' to go MAIN MENU ");
		scanf(" %d",&enter);
	
		system("cls");
	
		Selection(Menu());
	
		break;
	
	case 3:
	
		printf("---------------------------------------------------------------------------------------\n");
		printf("\n                              EDIT  DIARY   \n");
		printf("---------------------------------------------------------------------------------------\n\n");
	
		printf("please enter number which  dairy you want to edit ...");
	
		scanf("%d",&diaryNumber);
		sprintf(diaryName,"diary%d.txt",diaryNumber);
	
		fpnt=fopen(diaryName,"r");
		
	
			fgets(diaryName1, sizeof(diaryName1), fpnt);
			fgets(date, sizeof(date), fpnt);
			fgets(time, sizeof(time), fpnt);
			fgets(place, sizeof(place), fpnt);
			fgets(note, sizeof(note), fpnt);
		fclose(fpnt);
	
		printf("DATE		[1]\n");
		printf("TIME		[2]\n");
		printf("PLACE		[3]\n");
		printf("NOTE		[4]\n");
		printf("    ENTER YOUR CHOICE:  ");
		scanf(" %d",&choice);
	      fflush(stdin);
		fpnt=fopen(diaryName, "w");	
		switch(choice){
	
			case 1:
	
	              printf("Date:");
	              fgets(date,sizeof(date),stdin);
				fprintf(fpnt,"DIARY NAME %s",diaryName);
				fprintf(fpnt,"\nDATE %s",date);
				fprintf(fpnt,"%s",time);
				fprintf(fpnt,"%s",place);
				fprintf(fpnt,"%s",&note);
				 break;
		    case 2:
	
				printf("TIME:");
	              fgets(time,sizeof(time),stdin);
				fprintf(fpnt,"DIARY NAME %s",diaryName);
				fprintf(fpnt,"\n%s",date);
				fprintf(fpnt,"TIME %s",time);
				fprintf(fpnt,"%s",place);
				fprintf(fpnt,"%s",&note);
	
				break;
			case 3:
			    
				printf("PLACE:");
	              fgets(place,sizeof(place),stdin);
				fprintf(fpnt,"DIARY NAME %s",diaryName);
				fprintf(fpnt,"\n%s",date);
				fprintf(fpnt,"%s",time);
				fprintf(fpnt,"PLACE %s",place);
				fprintf(fpnt,"%s",&note);
	
				break;
		    case 4:
			    
				printf("NOTE:");
	              fgets(note,sizeof(note),stdin);
				fprintf(fpnt,"DIARY NAME %s",diaryName);
				fprintf(fpnt,"\n%s",date);
				fprintf(fpnt,"%s",time);
				fprintf(fpnt,"%s",place);
				fprintf(fpnt,"NOTE %s",&note);
	
				break;
		}  
		fclose(fpnt);
		printf("\n");
		sleep(1);
	
		printf("\n Please enter '0' to go MAIN MENU ");
		scanf(" %d",&enter);
	
		system("cls");
	
		Selection(Menu());
		break;
	case 4:
		
		fancyPrintf((char*)"---------------------------------------------------------------------------------------\n");
		fancyPrintf((char*)"                              EDIT PASSWORD  \n");
		fancyPrintf((char*)"---------------------------------------------------------------------------------------\n\n\n\n");
	printf("|||||||||||||||||||||||||\n");
	printf("|||||| NEW USERNAME |||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
	scanf(" %s",&userName);
	printf("------------------------\n");
	
	printf("|||||||||||||||||||||||||\n");
	printf("||||| NEW PASSWORD ||||||\n");
	printf("|||||||||||||||||||||||||\n\n");
	printf("------------------------\n         ");
		scanf(" %s",&passWord);
	printf("------------------------\n");
	sleep(2);
	system("cls");
	printf("\n\n  PASSWORD IS EDITING");
	printf("!");sleep(1);printf("!");sleep(1);printf("!");sleep(1);printf("!");sleep(1);printf("!");sleep(1);
	system("cls");
	printf("\n\n PROGRESS IS SUCCESSFUL ");
	sleep(2);
	system("cls");
	UserName();
	Password();
			sleep(1);
	
		printf("\n Please enter '0' to go MAIN MENU ");
		scanf(" %d",&enter);
	
		system("cls");
	
		Selection(Menu());
	   	break;
	case 5:
	   	printf("\n\nProgram closed successfully :)");
	   	system("cls");
	   	exit(-1);
	   	break;
	}
	}
	int main(int argc, char *argv[]) {
	
	Entrance();
	Selection(Menu());
	return 0;
}
