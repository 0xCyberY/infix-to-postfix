#include <stdio.h>
#define SIZE 20
#include <ctype.h>
char stack[SIZE];
int top = -1;
push (char elem)
{
    stack[++top] = elem;
}
char pop ()
{
    return (stack[top--]);
}
int precedence (char elem)
{
   switch(elem)
   {
	case '#': return 0;
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
   }
}
void main()
{
   char infix[50],postfix[50],ch,elem;
   int i = 0,j = 0;
   printf("\n\n Valid Infix Expression: ");
   scanf("%s",infix);
   push('#');
   while((ch = infix[i++]) != '\0')
   {
	if(ch == '(')
	push(ch);
	else
	{
	if(isalnum(ch))
		postfix[j++] = ch;
	else
		if(ch == ')')
		{
			while(stack[top] != '(')
				postfix[j++] = pop();
				pop();
		}
		else
		{
			while(precedence(stack[top])>=precedence(ch))
				postfix[j++] = pop();
				push(ch);
		}
	}
   }
while(stack[top] !='#')
   postfix[j++] = pop();
   postfix[j] = '\0';
   printf("\n Given Infix Expression : %s", infix);
   printf("\n Corresponding Postfix Expression : %s \n\n",postfix);
}
