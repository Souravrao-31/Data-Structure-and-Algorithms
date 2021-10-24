#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define MAX 20
void push(int);
char pop();
void infix_to_prefix();
int precedence (char);
char stack[20],infix[20],prefix[20];
int top = -1;

int main()
{
printf("\nINPUT THE INFIX EXPRESSION : ");
scanf("%s",infix);
infix_to_prefix();
return 0;
}
void push(int pos)
{
if(top == MAX-1)
{
printf("\nSTACK OVERFLOW\n");
}
else {
top++;
stack[top] = infix[pos];
}}

char pop()
{
char ch;
if(top < 0)
{
printf("\nSTACK UNDERFLOW\n");
exit(0);
}
else
{
ch = stack[top];
stack[top] = '\0';
top--;
return(ch);
}
return 0;
}
void infix_to_prefix()
{
int i = 0,j = 0;
strrev(infix);
while(infix[i] != '\0')
{
if(infix[i] >= 'a' && infix[i] <= 'z')
{
prefix[j] = infix[i];
j++;
i++;
}
else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
{
push(i);
i++;
}
else if(infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
{
if(infix[i] == '(')
{
while(stack[top] != ')')
{
prefix[j] = pop();
j++;
}
pop();
i++;
}
else if(infix[i] == '[')
{
while(stack[top] != ']')
{
prefix[j] = pop();
j++;
}
pop();
i++;
}
else if(infix[i] == '{')
{
while(stack[top] != '}')
{
prefix[j] = pop();
j++;
}
pop();
i++;
}}
else
{
if(top == -1)
{
push(i);
i++;
}
else if( precedence(infix[i]) < precedence(stack[top]))
{
prefix[j] = pop();
j++;
while(precedence(stack[top]) > precedence(infix[i])){
prefix[j] = pop();
j++;
if(top < 0) {
break;
}}
push(i);
i++;
}

else if(precedence(infix[i]) >= precedence(stack[top]))
{
push(i);
i++;
}}}
while(top != -1)
{
prefix[j] = pop();
j++;
}
strrev(prefix);
prefix[j] = '\0';
printf("EQUIVALENT PREFIX NOTATION : %s ",prefix);
}



int precedence(char alpha)
{
if(alpha == '+' || alpha =='-')
{
return(1);
}

if(alpha == '*' || alpha =='/')
{
return(2);
}
return 0;
}
