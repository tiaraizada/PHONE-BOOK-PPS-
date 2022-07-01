#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>

// function declare
void menu(void);
void password(void);
void namefunc(void);
void searchfunc(void);
void listfunc(void);
void modifyfunc(void);
void deletefunc(void);
void exitfun(void);

void GOTOxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
	system("color A");
	password();
	getch();
}

void password(void)
{
	char passwords[20] = {"tiaraizada"};
	GOTOxy(22, 2);
	int j;
	int z;
	char name[40] = "SRM PPS Mini Project";
	z = strlen(name);
	for (j = 0; j <= 16; j++)
	{
		Sleep(50);
		printf("\xDB");
	}
	for (j = 0; j <= z; j++)
	{
		Sleep(60);
		printf(" %c", name[j]);
	}
	for (j = 0; j <= 16; j++)
	{
		Sleep(50);
		printf("\xDB");
	}
	GOTOxy(30, 4);
	printf("Password:");
	char ch, pass[20];
	char w = '*';
	int i = 0;
	while (ch != 13)
	{
		ch = getch();
		if (ch != 13 && ch != 8)
		{
			printf("%c", w);
			pass[i] = ch;
			i++;
		}
	}
	pass[i] = '\0';
	if (strcmp(pass, passwords) == 0)
	{
		GOTOxy(30, 6);
		printf("Correct Password.");
		Sleep(1000);
		menu();
	}
	else
	{
		GOTOxy(30, 6);
		printf("You entered the wrong password.");
		Sleep(700);
		system("cls");
		password();
	}
}
void menu()
{
	system("cls");
	GOTOxy(30, 1);
	printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PHONEBOOK DIRECTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
	GOTOxy(31, 4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1.Add New");
	GOTOxy(31, 7);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2.Search");
	GOTOxy(31, 10);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3.List");
	GOTOxy(31, 13);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4.Modify");
	GOTOxy(31, 16);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5.Delete");
	GOTOxy(31, 19);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6.Exit");

	switch (getch())
	{
	case '1':
		namefunc();
		break;
	case '2':
		searchfunc();
		break;
	case '3':
		listfunc();
		break;
	case '4':
		modifyfunc();
		break;
	case '5':
		deletefunc();
		break;
	case '6':
		exitfun();
		break;
	default:
		system("cls");
		printf("Invalid Enter.");
		getch();
	}
}

void namefunc()
{
	system("cls");
	GOTOxy(31, 4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	FILE *fptr;
	char name[100];
	char address[100];
	char Email[100];
	double phone;
	char gender[8];
	fptr = fopen("data.txt", "ab+");
	if (fptr == NULL)
	{
		printf("Failed to create the required file.");
	}
	else
	{
		GOTOxy(31, 6);
		printf("Name:\t");
		GOTOxy(52, 6);
		gets(name);
		GOTOxy(31, 7);
		printf("Address:\t");
		GOTOxy(52, 7);
		gets(address);
		GOTOxy(31, 8);
		printf("Gender:\t");
		GOTOxy(52, 8);
		gets(gender);
		GOTOxy(31, 9);
		printf("Email:\t");
		GOTOxy(52, 9);
		gets(Email);
		GOTOxy(31, 10);
		printf("Phone Number:\t");
		GOTOxy(52, 10);
		scanf("%lf", &phone);
		fprintf(fptr, "%s %s %s %s %.0lf\n", name, address, gender, Email, phone);
	}
	fclose(fptr);
	system("cls");
	char ch;
	GOTOxy(31, 4);
	printf("Enter 'm' to return to Main Menu: ");
	Sleep(1000);
	fflush(stdin);
	while ((ch = getch()) == 'm')
	{
		menu();
	}
}

void searchfunc()
{
	FILE *fptr;
	int flag = 0;
	int res;
	char name[100];
	char address[100];
	char Email[100];
	double phone;
	char gender[8];
	char name1[100];
	system("cls");
	fflush(stdin);
	GOTOxy(18, 2);
	printf("\xDB\xDB\xDB Search for Name :: ");
	gets(name1);
	fptr = fopen("data.txt", "r");
	while (fscanf(fptr, "%s %s %s %s %lf\n", name, address, gender, Email, &phone) != EOF)
	{
		res = strcmp(name, name1);
		if (res == 0)
		{
			GOTOxy(39, 4);
			printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			GOTOxy(28, 5);
			printf("----------------------------------------");
			GOTOxy(31, 6.5);
			printf("\xB3\xB2\xB2\xB2 Name:\t%s", name);
			GOTOxy(31, 7);
			printf("\xB3\xB2\xB2\xB2 Address:\t%s", address);
			GOTOxy(31, 8);
			printf("\xB3\xB2\xB2\xB2 Gender:\t%s", gender);
			GOTOxy(31, 9);
			printf("\xB3\xB2\xB2\xB2 Email:\t%s", Email);
			GOTOxy(31, 10);
			printf("\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf", phone);
			GOTOxy(31, 11);
			printf("----------------------------------------");
			flag = 1;
			Sleep(1000);
			GOTOxy(18, 12);
			printf("Enter 'm' for menu option.");
			while (getch() == 'm')
			{
				menu();
			}
		}
	}
	if (flag == 0)
	{
		system("cls");
		GOTOxy(39, 4);
		printf("No record found.");
		;
		GOTOxy(39, 6);
		printf("Enter 's' to search again:");
		if (getch() == 's')
		{
			system("cls");
			searchfunc();
		}
	}

	fclose(fptr);
}

void listfunc()
{
	FILE *fptr;
	char name[100], address[100], Email[100], gender[8];
	double phone;
	int f;
	fptr = fopen("data.txt", "r");
	system("cls");
	GOTOxy(31, 2);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	printf("\n");
	while (fscanf(fptr, "%s %s %s %s %lf", name, address, gender, Email, &phone) != EOF)
	{

		printf("------------------------------------------\n");
		printf("Name:%s\n", name);
		printf("Address:%s\n", address);
		printf("Gender:%s\n", gender);
		printf("Email:%s\n", Email);
		printf("Phone:%.0lf\n", phone);
		f = 1;
		printf("------------------------------------------");
		printf("\n\n");
	}
	Sleep(1000);
	printf("Enter 'm' to return to Main Menu:");
	while (getch() == 'm')
	{
		menu();
	}
	fclose(fptr);
}

void modifyfunc()
{
	FILE *fptr, *fptr1;
	char name[100], address[100], Email[100], Email1[100], address1[100], name1[100], gender[8], gender1[8];
	int res, f = 0;
	double phone, phone1;
	fptr = fopen("data.txt", "r");
	fptr1 = fopen("temp.txt", "a");
	system("cls");
	GOTOxy(31, 4);
	printf("Enter the name: ");
	gets(name1);
	system("cls");
	while (fscanf(fptr, "%s %s %s %s %lf\n", name, address, gender, Email, &phone) != EOF)
	{
		res = strcmp(name, name1);
		if (res == 0)
		{
			f = 1;
			GOTOxy(31, 4);
			printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			GOTOxy(31, 6);
			printf("Enter the new address:");
			scanf("%s", address1);
			GOTOxy(31, 7);
			printf("Enter the gender:");
			scanf("%s", gender1);
			GOTOxy(31, 8);
			printf("Enter the new Email:");
			scanf("%s", Email1);
			GOTOxy(31, 9);
			printf("Enter the new phone number:");
			scanf("%lf", &phone1);
			fprintf(fptr1, "%s %s %s %s %.0lf\n", name, address1, gender1, Email1, phone1);
		}
		else
		{
			fprintf(fptr1, "%s %s %s %s %.0lf\n", name, address, gender, Email, phone);
		}
	}
	if (f == 0)
	{
		printf("Record Not found.");
	}
	fclose(fptr);
	fclose(fptr1);
	fptr = fopen("data.txt", "w");
	fclose(fptr);
	fptr = fopen("data.txt", "a");
	fptr1 = fopen("temp.txt", "r");
	while (fscanf(fptr1, "%s %s %s %s %lf\n", name, address, gender, Email, &phone) != EOF)
	{
		fprintf(fptr, "%s %s %s %s %.0lf\n", name, address, gender, Email, phone);
	}

	fclose(fptr);
	fclose(fptr1);
	fptr1 = fopen("temp.txt", "w");
	fclose(fptr1);
	printf("\n\nPress 'm' for menu option.");
	fflush(stdin);
	if (getch() == 'm')
	{
		menu();
	}
}
void deletefunc()
{
	FILE *fptr, *fptr1;
	char name[100], address[100], Email[100], Email1[100], address1[100], name1[100], gender[8];
	int res, f = 0;
	double phone, phone1;
	fptr = fopen("data.txt", "r");
	fptr1 = fopen("temp.txt", "a");
	system("cls");
	GOTOxy(31, 4);
	printf("Enter the CONTACT name that you want to delete: ");
	gets(name1);
	system("cls");
	while (fscanf(fptr, "%s %s %s %s %lf\n", name, address, gender, Email, &phone) != EOF)
	{
		res = strcmp(name, name1);
		if (res == 0)
		{
			f = 1;
			printf("Record deleted successfully");
		}
		else
		{
			fprintf(fptr1, "%s %s %s %s %.0lf\n", name, address, gender, Email, phone);
		}
	}
	if (f == 0)
	{
		printf("Record Not found.");
	}
	fclose(fptr);
	fclose(fptr1);
	fptr = fopen("data.txt", "w");
	fclose(fptr);
	fptr = fopen("data.txt", "a");
	fptr1 = fopen("temp.txt", "r");
	while (fscanf(fptr1, "%s %s %s %s %lf\n", name, address, gender, Email, &phone) != EOF)
	{
		fprintf(fptr, "%s %s %s %s %.0lf\n", name, address, gender, Email, phone);
	}

	fclose(fptr);
	fclose(fptr1);
	fptr1 = fopen("temp.txt", "w");
	fclose(fptr1);
	printf("\n\nPress 'm' for menu option.");
	fflush(stdin);
	if (getch() == 'm')
	{
		menu();
	};
}
void exitfun()
{
	system("cls");
	GOTOxy(31, 4);
	printf("\xDB\xDB\xDB\xDB Made with love \xDB\xDB\xDB\xDB");
	GOTOxy(31, 6);
	printf("\xDB\xDB\xDB\xDB  By Tia Raizada");
}
