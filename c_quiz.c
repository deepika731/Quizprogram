#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void check_num(int random);
void check_answer(int random,char ans);
char correct_answer(int random);
void display_question(int random);
void start_quiz(char name[10]);
void check_category(int a);
void categorywise_marks();
int a[10],count[10],n=0,t=0,c=0,s=0,g1=0,g2=0,co1=0,co2=0,ci1=0,ci2=0,h1=0,h2=0,e1=0,e2=0,s1=0,s2=0,a1=0,a2=0,sp1=0,sp2=0;
char an[10],ans[1],m[10][10],cat[10];
FILE *fp;
void start_quiz(char name[10])
{
	int random,i,co=0;
    char ans[1];
    i=0;
	while(i<10)
    {
        random=(rand()%30)+1;
		a[i]=random;
		display_question(a[i]);
		printf("enter your answer:");
		scanf("%s",ans);
		an[n]=ans[0];
		n++;
		check_answer(a[i],ans[0]);
		i++;
	}
	printf("congratulations %s you have successfully completed the quiz\n",name);
	printf("you got %d correct out of 10 questions",c);
	printf("the answers are:\n");
	for(i=0;i<10;i++)
	{
	    int k=0;
		display_question(a[i]);
		printf("correct answer:%c\n",correct_answer(a[i]));
		printf("your answer:%c\n",an[i]);
		printf("marks obtained:%d\n",count[i]);
		co+=count[i];
	}
	printf("total marks awarded:%d\n",co);
	printf("category wise marks are...\n");
	categorywise_marks();
	if(co2!=0)
    {
        printf("you got %d marks out of %d marks in computer category\n",co1,co2);
    }
    if(g2!=0)
    {
        printf("you got %d marks out of %d marks in general category\n",g1,g2);
    }
    if(ci2!=0)
    {
        printf("you got %d marks out of %d marks in civics category\n",ci1,ci2);
    }
    if(e2!=0)
    {
        printf("you got %d marks out of %d marks in economics category\n",e1,e2);
    }
    if(a2!=0)
    {
        printf("you got %d marks out of %d marks in awards category\n",a1,a2);
    }
    if(sp2!=0)
    {
        printf("you got %d marks out of %d marks in sports category\n",sp1,sp2);
    }
    if(h2!=0)
    {
        printf("you got %d marks out of %d marks in history category\n",h1,h2);
    }
    if(s1!=0)
    {
        printf("you got %d marks out of %d marks in science category\n",s1,s2);
    }

}
void check_answer(int random,char ans)
{
	char ch,r[2];
	r[0]=random/10+'0';
	r[1]=random%10+'0';
	fp=fopen("quiz.txt","r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		if(ch==r[0])
		{
			ch=fgetc(fp);
			if(ch==r[1])
			{
				while(ch!='-')
				{
					ch=fgetc(fp);
				}
				if(ch=='-')
				{
					ch=fgetc(fp);
					if(ch==ans)
					{
                        c++;
						check_category(random);
                        if(strcmp(cat,"computer")==0 || strcmp(cat,"science")==0)
                        {
                            count[s]=3;
                        }
                        else if(strcmp(cat,"general")==0 || strcmp(cat,"sports")==0 || strcmp(cat,"awards")==0)
                        {
                            count[s]=1;
                        }
                        else if(strcmp(cat,"economics")==0 || strcmp(cat,"civics")==0 || strcmp(cat,"History")==0)
                        {
                            count[s]=2;
                        }
                        s++;
						break;
					}
					else
                    {
                        check_category(random);
                        count[s]=0;
                        s++;
                        break;
                    }
				}
			}
		}
		ch=fgetc(fp);
	}
}
char correct_answer(int random)
{
	char ch,r[2];
	r[0]=random/10+'0';
	r[1]=random%10+'0';
	fp=fopen("quiz.txt","r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		if(ch==r[0])
		{
			ch=fgetc(fp);
			if(ch==r[1])
			{
				while(ch!='-')
				{
					ch=fgetc(fp);
				}
				if(ch=='-')
				{
					ch=fgetc(fp);
					return ch;
					break;
				}
			}
		}
		ch=fgetc(fp);
	}

}
void display_question(int a)
{
	char ch,r[2];
	r[0]=a/10+'0';
	r[1]=a%10+'0';
	fp=fopen("quiz.txt","r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{

		if(ch==r[0])
		{
			ch=fgetc(fp);
			if(ch==r[1])
			{
				ch=fgetc(fp);
				while(ch!='#')
				{
					printf("%c",ch);
					ch=fgetc(fp);
				}
				printf("\n");
				break;
			}
		}
		ch=fgetc(fp);
	}
}
void check_category(int a)
{
    char ch,r[2];
    int i;
	r[0]=a/10+'0';
	r[1]=a%10+'0';
	fp=fopen("quiz.txt","r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{

		if(ch==r[0])
		{
			ch=fgetc(fp);
			if(ch==r[1])
			{
				ch=fgetc(fp);
				while(ch!=':')
				{
					ch=fgetc(fp);
				}
				i=0;
				ch=fgetc(fp);
				while(ch!='\n')
                {
                    m[t][i]=ch;
                    cat[i]=ch;
                    i++;
                    ch=fgetc(fp);
                }
                m[t][i]='\0';
                cat[i]='\0';
                t++;
				break;
			}
		}
		ch=fgetc(fp);
	}
}
void categorywise_marks()
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(m[i],"computer")==0)
        {
            co1+=count[i];
            co2+=3;
        }
        else if(strcmp(m[i],"general")==0)
        {
            g1+=count[i];
            g2+=1;
        }
        else if(strcmp(m[i],"civics")==0)
        {
            ci1+=count[i];
            ci2+=2;
        }
        else if(strcmp(m[i],"History")==0)
        {
            h1+=count[i];
            h2+=2;
        }
        else if(strcmp(m[i],"science")==0)
        {
            s1+=count[i];
            s2+=3;
        }
        else if(strcmp(m[i],"awards")==0)
        {
            a1+=count[i];
            a2+=1;
        }
        else if(strcmp(m[i],"economics")==0)
        {
            e1+=count[i];
            e2+=2;
        }
        else if(strcmp(m[i],"sports")==0)
        {
            sp1+=count[i];
            sp2+=1;
        }
    }
}
int main()
{
	char ch,name[10];
	printf("\n******Welcome to the quiz******\n");
	printf("This quiz will be very interesting you will be displayed 10 questions one after the other\n");
	printf("Each question contains four options you have to select one among them\n");
	printf("At the end your score will be displayed\n");
	printf("Press S to start the quiz Q to quit:\t");
	scanf("%c",&ch);
	if(ch=='S' || ch=='s')
	{
		printf("enter your name:");
		scanf("%s",name);
		start_quiz(name);
	}
	else if(ch=='Q' || ch=='q')
	{
		printf("successfully quitted");
	}
	else
	{
		printf("invalid option");
	}
}
