#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cctype>
using namespace std;
void check_num(int random);
int check_answer(int random,char ans);
char correct_answer(int random);
void display_question(int random);
void start_quiz();
int a[10],count=0,n=0;
char an[10];
void start_quiz()
{
	int random,i,c,k;
    char ans[1];
    i=0;
	while(i<10)
    {
        random=(rand()%30)+1;
		a[i]=random;
		display_question(a[i]);
		cout<<"enter your answer:";
		cin>>ans;
		an[n]=ans[0];
		n++;
		c=check_answer(a[i],ans[0]);
		i++;
	}
	cout<<"congratulations you have successfully completed the quiz\n"<<endl;
	cout<<"you got "<<c<< "marks out of 10 marks"<<endl;
	cout<<"Here are the answers...\n";
	for(i=0;i<10;i++)
	{
	    k=0;
		display_question(a[i]);
		cout<<"correct answer:"<<correct_answer(a[i])<<"\n"<<endl;
		cout<<"your answer:"<<an[i]<<"\n"<<endl;
		if(correct_answer(a[i])==an[i])
        {
            k=1;
        }
		cout<<"marks obtained:"<<k<<endl;

	}
}
int check_answer(int random,char ans)
{
	char ch,r[2];
	r[0]=random/10+'0';
	r[1]=random%10+'0';
	std::ifstream fp;
	fp.open("quiz.txt");
	fp>>ch;
	while(ch!='@')
	{
		if(ch==r[0])
		{
			fp>>ch;
			if(ch==r[1])
			{
				while(ch!='-')
				{
					fp>>ch;
				}
				if(ch=='-')
				{
					fp>>ch;
					if(ch==ans)
					{
						count++;
						break;
					}
				}
			}
		}
		fp>>ch;
	}
    return count;
}
char correct_answer(int random)
{
	char ch,r[2];
	r[0]=random/10+'0';
	r[1]=random%10+'0';
    std::ifstream fp;
	fp.open("quiz.txt");
	fp>>ch;
	while(ch!='@')
	{
		if(ch==r[0])
		{
			fp>>ch;
			if(ch==r[1])
			{
				while(ch!='-')
				{
					fp>>ch;
				}
				if(ch=='-')
				{
					fp>>ch;
					return ch;
					break;
				}
			}
		}
		fp>>ch;
	}

}
void display_question(int a)
{
	char ch;
	string r;
	r[0]=a/10+'0';
	r[1]=a%10+'0';
    std::ifstream fp;
	fp.open("quiz.txt");
	string data;
	while(data!="@")
    {
        getline(fp,data);
        if(data[0]==r[0] && data[1]==r[1])
        {
            getline(fp,data);
            while(data!="#")
            {
                cout<<data<<endl;
                getline(fp,data);
            }
            break;
        }

    }
}
int main()
{
	char ch;
	cout<<"\n******Welcome to the quiz******\n";
	cout<<"This quiz will be very interesting you will be displayed 10 questions one after the other\n";
	cout<<"Each question contains four options you have to select one among them\n";
	cout<<"At the end your score will be displayed\n";
	cout<<"Press S to start the quiz Q to quit:\t";
	cin>>ch;
	if(ch=='S' || ch=='s')
	{
		start_quiz();
	}
	else if(ch=='Q' || ch=='q')
	{
		cout<<"successfully quitted";
	}
	else
	{
		cout<<"invalid option";
	}
}
