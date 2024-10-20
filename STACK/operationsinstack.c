#include <stdio.h>
#define size 5

struct stack
{
	int a[size], top;
	int temp[size];
} s;

// PUSH Operation

void push()
{
	int value;
	printf(" Enter value to be pushed: ");
	scanf("%d", &value);
	s.top = s.top + 1;
	s.a[s.top] = value;
}
// POP Operation

void pop()
{
	printf(" Popped element is %d\n", s.a[s.top]);
	s.top = s.top - 1;
}

// PEEP Operation

void peep()
{
	printf(" The value at top position is : %d\n", s.a[s.top]);
}

// DISPLAY Operation

void display()
{
	int i;
	printf(" The stack contains: ");
	for (i = s.top; i >= 0; i--)
	{
		printf("\t%d", s.a[i]);
	}
	printf("\n");
}

// CHANGE Operation

void change(int index, int new_element)
{
	int i, j = -1;
	for (i = s.top; i > index; i--)
	{
		s.temp[++j] = s.a[s.top--];
	}
	s.a[s.top] = new_element;
	for (i = j; i > -1; i--)
	{
		s.a[++s.top] = s.temp[j--];
	}
}

void main()
{
	s.top = -1;
	int choice, index, new_element;
	do
	{
		printf("\n STACK IMPLEMENTATION PROGRAM");
		printf("\n 1. PUSH 2. POP 3. PEEP 4. CHANGE 5. DISPLAY 0. EXIT\n");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			if (s.top == size - 1)
			{
				printf("\tSTACK OVERFLOW\n");
			}
			else
			{
				push();
			}
			break;
		case 2:
			if (s.top == -1)
			{
				printf("\tSTACK UNDERFLOW\n");
			}
			else
			{
				pop();
			}
			break;
		case 3:
			if (s.top == -1)
			{
				printf("\tStack is empty.\n");
			}
			else
			{
				peep();
			}
			break;
		case 4:
			printf(" Enter index no : ");
			scanf("%d", &index);

			if (index < 0 || index > s.top)
			{
				printf("\tINVALID INDEX NUMBER\n");
			}
			else
			{
				printf(" Enter new element: ");
				scanf("%d", &new_element);
				change(index, new_element);
			}
			break;
		case 5:
			if (s.top == -1)
			{
				printf("\t Stack is empty.\n");
			}
			else
			{
				display();
			}
			break;
		case 0:
			printf("\tEND OF PROGRAM");
			break;
		default:
			printf("\tINVALID CHOICE\n");
		}

	} while (choice != 0);
}