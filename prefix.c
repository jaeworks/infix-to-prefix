#include <stdio.h>
#include <string.h>
char infix[100],prefix[100],stack[100];
char expression[100]="";
char character,popped_from_stack,x;
int i,n,top=-1,top2,count=0;
void reverse()
{
    for(i=0;infix[i]!='\0';i++)
    {
        expression[n-i-1]=infix[i];
        if(infix[i]=='(')
            expression[n-i-1]=')';
        else if(infix[i]==')')
            expression[n-i-1]='(';
        else
            expression[n-i-1]=infix[i];
    }
}
void push_prefix(char x)
{
	prefix[++top2]=x;
}
void push_stack(char x)
{
	stack[++top]=x;
}
char pop_stack()
{
	if (top==-1)
		return -1;
	else
		return stack[top--];
}
char pop_prefix()
{
	if (top2==-1)
		return -1;
	else
		return prefix[top2--];
}
int ISpriority(char x)
{
	if (x=='+'||x=='-')
		return 2;
	if (x=='*'||x=='/')
		return 4;
	if (x=='^')
		return 5;
	if (x>='a' && x<='z' || x>='A' && x<='Z' || x>='1' && x<='9')
		return 8;
	if (x=='(')
		return 0;
}
int ICpriority(char x)
{
	if (x=='+'||x=='-')
		return 1;
	if (x=='*'||x=='/')
		return 3;
	if (x=='^')
		return 6;
	if (x>='a' && x<='z' || x>='A' && x<='Z' || x>='1' && x<='9')
		return 7;
	if (x=='(')
		return 9;
	if (x==')')
		return 0;
}
int main() 
{
    printf("Enter expression: ");
    scanf("%s",infix);
    n=strlen(infix);
    reverse();
    for(i=0;i<n;i++)
    {
        character=expression[i];
        if (character=='(')
            push_stack(character);
        else if (isalnum(character))
        {
            push_prefix(character);
            count++;
        }
        else if (character==')')
        {
            x=pop_stack();
            while(x!='(')
            {
                push_prefix(x);
                count++;
                x=pop_stack();
            }
        }
        else
        {
            if (ISpriority(stack[top])>=ICpriority(character))
			{
				popped_from_stack=pop_stack();
				push_prefix(popped_from_stack);
				count++;
			}
			push_stack(character);
        }
    }
    while(top!=-1)
    {
        x=pop_stack();
        push_prefix(x);
    }
    printf("Prefix Expression: ");
    while(top2!=-1 && count>0)
    {
        printf("%c ",pop_prefix());
        count--;
    }
    printf("\n");
    return 0;
}
