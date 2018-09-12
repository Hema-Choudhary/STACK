#include<stdio.h>
#include<malloc.h>

typedef struct stack
{
 int no;
 struct stack *down;
}stk;

stk *top=NULL;

void push(int no)
{
 stk *new;
 new = (stk*)malloc(sizeof(stk));
 new->no=no;
 new->down=NULL;
 if(top==NULL)
 {
  top=new; 
 }
 else
 {
  new->down=top;
  top=new;
 } 
}

int isempty()
{
 if(top==NULL)
  return 1;
 else 
  return 0;
}

int pop()
{
 int x;
 stk *tmp;
 tmp=top;
 x=top->no;
 top=top->down;
 free(tmp); 
 return x;
}

int peek()
{
 if(!isempty())
  return top->no;
 else 
  return -100;
}

int main(void)
{
 int op,no;
 do
 {
  fprintf(stdout,"\n1)Push\n2)Pop\nEnter:");
  fscanf(stdin,"%d",&op);
  switch(op)
  {
  case 1: fprintf(stdout,"\nEnter no:");
          fscanf(stdin,"%d",&no);
	  push(no);
	  fprintf(stdout,"\n TOP: %d",peek());
	  break;

  case 2: if(!isempty())
 	   fprintf(stdout,"\n%d",pop());
	  else
 	    fprintf(stdout,"\nEmpty!");
          fprintf(stdout,"\n TOP: %d",peek());
	  break;
  }
 }while(op<=2);
 return 0;
} 
