#include<ctype.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

FILE *fp;
char ch,*fname,*temp="";
int why;

void eol()
{
	why=wherey();
	if (why==24)
	{
		gotoxy(1,25);printf("Press any key to continue...");
		getch();
		clrscr();
	}
}

void lex(char c)
{
//newline,space,tab
	if(isspace(c));
//Terminator
	else if(c=='.')
	{
		printf("%c  ->Terminator\n",c);eol();
	}
//Comment
	else if (c=='!')
	{
		do
		{
			putchar(ch);eol();
		}while((ch=getc(fp))!='\n');
		printf("  ->Comment\n");eol();
	}
//String
	else if (c=='\"')
	{
		do
		{
			putchar(ch);eol();
		}
		while((ch=getc(fp))!='\"');
		printf("%c  ->String\n",ch);eol();
	}
//Integer
	else if (isdigit(c))
	{
		while(isdigit(ch))
		{
			putchar(ch);eol();
			ch=getc(fp);
		}
		if (isalpha(ch))
		{
			while(isalpha(ch))
			{
				putchar(ch);eol();
				ch=getc(fp);
			}
			printf("  ->Undefined\n");eol();
		}
		else
		{
			printf("  ->Integer\n");eol();lex(ch);
		}
	}
//Symbols
	else if (c=='+'){printf("%c  ->Addition operator\n",c);eol();}
	else if (c=='*'){printf("%c  ->Multiplication operator\n",c);eol();}
	else if (c=='/'){printf("%c  ->Division operator\n",c);eol();}
	else if (c=='='){printf("%c  ->Assignment operator\n",c);eol();}
	else if (c=='['){printf("%c  ->Open statement\n",c);eol();}
	else if (c==']'){printf("%c  ->Close statement\n",c);eol();}
	else if (c=='('){printf("%c  ->Open operation\n",c);eol();}
	else if (c==')'){printf("%c  ->Close operation\n",c);eol();}
//Keywords
	else if (c=='-')
	{
		//-ma
		if((ch=getc(fp))=='m')
		{
			if((ch=getc(fp))=='a')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-ma  ->Keyword\n");eol();
				}
			}
		}
		//-bl
		else if(ch=='b')
		{
			if((ch=getc(fp))=='l')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-bl  ->Keyword\n");eol();
				}
			}
		}
		//-ch
		else if(ch=='c')
		{
			if((ch=getc(fp))=='h')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-ch  ->Keyword\n");eol();
				}
			}
		}
		//-fa
		else if(ch=='f')
		{
			if((ch=getc(fp))=='a')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-fa  ->Keyword\n");eol();
				}
			}
		}
		//-if
		else if(ch=='i')
		{
			if((ch=getc(fp))=='f')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-if  ->Keyword\n");eol();
				}
			}
			//-in
			else if(ch=='n')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-in  ->Keyword\n");eol();
				}
			}
		}
		//-rd
		else if(ch=='r')
		{
			if((ch=getc(fp))=='d')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-rd  ->Keyword\n");eol();
				}
			}
		}
		//-st
		else if(ch=='s')
		{
			if((ch=getc(fp))=='t')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-st  ->Keyword\n");eol();
				}
			}
		}
		//-tr
		else if(ch=='t')
		{
			if((ch=getc(fp))=='r')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-tr  ->Keyword\n");eol();
				}
			}
		}
		//-wh
		else if(ch=='w')
		{
			if((ch=getc(fp))=='h')
			{
				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-wh  ->Keyword\n");eol();
				}
			}
			//-wr
			else if(ch=='r')
			{				ch=getc(fp);
				if ((ch=='\n')||(ch=='\t')||(ch==' '))
				{
					printf("-wr  ->Keyword\n");eol();
				}
			}
		}

		else
		{
			printf("%c  ->Subtraction operator\n",c);
			eol();
			lex(ch);
		}
	}
//Indentifier
	else if (isalpha(c))
	{
		while((isalpha(ch))||(isdigit(ch)))
		{
			putchar(ch);eol();
			ch=getc(fp);
		}
		printf("  ->Indentifier\n");eol();
		lex(ch);
	}
//Undefined
	else
	{
		printf("%c  ->Undefined\n",c);eol();
	}
}


void main()
{
clrscr();
printf("BEBE Lexical Analyzer Version 1.00 Copyleft (c) 2007 Ethanium Intergalactic\n\n");
start:
printf("Enter file name: ");
gets(fname);
if ((fp=fopen(fname,"r"))==NULL)
{
	perror("Error");
	gotoxy(1,25);
	printf("Retry?(Y/N)");
	if (tolower(getch())=='y')
	{
		clrscr();
		goto start;
	}
	exit(0);
}
clrscr();
puts("--------------------------------------BOF---------------------------------------");
while ((ch=fgetc(fp))!=EOF)
{
	putchar(ch);
	eol();
}
puts("");
puts("");
puts("--------------------------------------EOF---------------------------------------");
fclose(fp);
gotoxy(1,25);printf("Press any key to analyze...");
getch();
clrscr();
fp=fopen(fname,"r");
while ((ch=fgetc(fp))!=EOF)
{
	lex(ch);
}
fclose(fp);
gotoxy(1,25);
printf("Another round?(Y/N)");
if (tolower(getch())=='y')
{
	clrscr();
	goto start;
}
}

