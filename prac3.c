#include<stdio.h>

int list[5],tos=-1,size=4,ch;
void main()
{
    void push();
    void display();
    void pop();
    void peep();
    void update();
   
    printf("\n1:Push Operation");
    printf("\n2:Display");
    printf("\n3:Pop Operation");
    printf("\n4:Peep Operation");
    printf("\n5:Update Operation");
    printf("\n0:Exit");
    do
    {
      printf("\nEnter The Above Choice:->");
      scanf("%d",&ch);
      switch(ch)
      {
    case 0:
           exit(0);
       case 1:
           push();
           break;
       case 2:
           display();
           break;
       case 3:
           pop();
           break;
       case 4:
           peep();
           break;
       case 5:
          update();
          break;
     }
     }
     while(ch!=0);
}
void push()
{
   int value;
   if(tos>=size)
   {
     printf("\nThe Stack is Overflow...");
     return;
   }
   else
   {
      printf("\nEnter The Value:->");
      scanf("%d",&value);
      tos=tos+1;
      list[tos]=value;
   }
}
void display()
{
   int i;
   if(tos==-1)
   {
     printf("\nThere is Element not Avaible...");
     return;
   }
   else
   {
      for(i=0;i<=tos;i++)
      printf("\nThe Element is:->%d",list[i]);
   }
}
void pop()
{
  if(tos==0)
  {
    printf("\nThe stack is Underflow...");
    return;
  }
  else
  {
    tos=tos-1;
   printf("\nElement Delete Successfull.....");
 }
}
void peep()
{
   int s;
   printf("\nEnter Position for search:->");
   scanf("%d",&s);
   if(tos-s<=-1)
   {
      printf("\nThe Stack is Overflow...");
      return;
   }
   else
   {
     printf("\nThe Element is:->%d",list[tos-s]);
   }
}

void update()
{
   int it1,it2;
      printf("\nEnter Position for change:->");
     scanf("%d",&it1);
     printf("\nEnter Number For Update:->");
     scanf("%d",&it2);
   if(tos-it1<=-1)
   {
      printf("\nThe Stack Underflow...");
      return;
   }
   else
   {


     list[tos-it1]=it2;
     printf("\nUpdte Successfull.....");

   }
}












prac 4

/* This program converts infix expression to postfix expression.
 * This program assume that there are Five operators: (*, /, +, -,^) 
	in infix expression and operands can be of single-digit only.
 * This program will not work for fractional numbers.
 * Further this program does not check whether infix expression is 
 valid or not in terms of number of operators and operands.*/

#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

#define SIZE 100


/* declared here as global variable because stack[]
* is used by more than one fucntions */
char stack[SIZE];
int top = -1;

/* define push operation */

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

/* define pop operation */
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

/* define function that is used to determine whether any symbol is operator or not
(that is symbol is operand)
* this fucntion returns 1 if symbol is opreator else return 0 */

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

/* define fucntion that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this fucntion we assume that higher integer value
* means higher precendence */

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);
			/* because just above while loop will terminate we have
			oppped one extra item
			for which condition fails and loop terminates, so that one*/

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}

/* main function begins */
int main()
{
	char infix[SIZE], postfix[SIZE];         /* declare infix string and postfix string */

	/* why we asked the user to enter infix expression
	* in parentheses ( )
	* What changes are required in porgram to
	* get rid of this restriction since it is not
	* in algorithm
	* */
	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	gets(infix);

	InfixToPostfix(infix,postfix);                   /* call to convert */
	printf("Postfix Expression: ");
	puts(postfix);                     /* print postfix expression */

	return 0;
}




























prac 5 
	
	
	#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 5  
void insert();  
void delete();  
void display();  
int front = -1, rear = max;  
int queue[maxsize];  
void main ()  
{  
    int choice;   
    while(choice != 4)   
    {     
         
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert();  
            break;  
            case 2:  
            delete();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
void insert()  
{  
    int item;  
    printf("\nEnter the element\n");  
    scanf("\n%d",&item);      
    if(rear == maxsize)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == max)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\nValue inserted ");  
      
}  
void delete()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\nvalue deleted ");  
    }  
      
      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("\n%d\n",queue[i]);  
        }     
    }  
}  
