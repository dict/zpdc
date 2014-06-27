#if 1
// step 10-1.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node *next;
	struct _node *prev;
} NODE;

void __insert_data( NODE *temp, NODE *prev, NODE *next  )
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front( NODE *temp, NODE *head )
{
	__insert_data(temp, head, head->next  );
}

void insert_back( NODE *temp, NODE *head )
{
     __insert_data(temp, head->prev, head  );
}

#define   list_entry( ptr, type, member )                   \
   ((type*)((char*)ptr - (unsigned long)&((type*)0)->member))

//-----------------------------------------------------

typedef struct
{
	NODE list;
	char name[20];
	int  sid;
} SAWON;

void display( NODE *head )
{
	NODE *temp;
	SAWON  *s;
	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head  ; temp = temp->prev )
	{
		s = list_entry( temp, SAWON, list );

		printf("<->[%s]", s->name );
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	SAWON s[2] = { {{0,},"홍길동",}, { {0,},"이순신",} };
	NODE head = { &head , &head };

	display(&head);
	for(i=0; i<2; i++ )
	{
		insert_back( &s[i].list, &head);
		display(&head);
	}
	return 0;
}
#endif 
#if 0
// step 10.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node *next;
	struct _node *prev;
} NODE;

void __insert_data( NODE *temp, NODE *prev, NODE *next  )
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front( NODE *temp, NODE *head )
{
	__insert_data(temp, head, head->next  );
}

void insert_back( NODE *temp, NODE *head )
{
     __insert_data(temp, head->prev, head  );
}


//-----------------------------------------------------

typedef struct
{
	NODE list;
	char name[20];
	int  sid;
} SAWON;

void display( NODE *head )
{
	NODE *temp;
	SAWON  *s;
	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head  ; temp = temp->prev )
	{
		s = (SAWON*)((char*)temp - (unsigned long)&((SAWON*)0)->list); 

		printf("<->[%s]", s->name );
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	SAWON s[2] = { {{0,},"홍길동",}, { {0,},"이순신",} };
	NODE head = { &head , &head };

	display(&head);
	for(i=0; i<2; i++ )
	{
		insert_back( &s[i].list, &head);
		display(&head);
	}
	return 0;
}
#endif 
#if 0
// step 9.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node *next;
	struct _node *prev;
} NODE;

void __insert_data( NODE *temp, NODE *prev, NODE *next  )
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front( NODE *temp, NODE *head )
{
	__insert_data(temp, head, head->next  );
}

void insert_back( NODE *temp, NODE *head )
{
     __insert_data(temp, head->prev, head  );
}


//-----------------------------------------------------

typedef struct
{
	char name[20];
	int  sid;
	NODE list;
} SAWON;

void display( NODE *head )
{
	NODE *temp;
	SAWON  *s;
	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head  ; temp = temp->prev )
	{
		//s = (SAWON*)((char*)temp - 24);
		s = (SAWON*)((char*)temp - (sizeof(SAWON)-sizeof(NODE)));

		printf("<->[%s]", s->name );
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	SAWON s[2] = { {"홍길동",}, {"이순신",} };
	NODE head = { &head , &head };

	display(&head);
	for(i=0; i<2; i++ )
	{
		insert_back( &s[i].list, &head);
		display(&head);
	}
	return 0;
}
#endif 
#if 0
// step 8.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	void * data;
	struct _node *next;
	struct _node *prev;
} NODE;

void __insert_data( NODE *temp, NODE *prev, NODE *next  )
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front( NODE *temp, NODE *head )
{
	__insert_data(temp, head, head->next  );
}

void insert_back( NODE *temp, NODE *head )
{
     __insert_data(temp, head->prev, head  );
}


//-----------------------------------------------------

typedef struct
{
	char name[20];
} SAWON;

void display( NODE *head )
{
	NODE *temp;
	SAWON  *s;
	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head  ; temp = temp->prev )
	{
		s = (SAWON*)temp->data;
		printf("<->[%s]", s->name );
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[2];
	SAWON s[2] = { "홍길동", "이순신" };
	NODE head = { 0, &head , &head };

	display(&head);
	for(i=0; i<2; i++ )
	{
		temp[i].data = s+i;
		insert_back( temp+i, &head);
		display(&head);
	}
	return 0;
}
#endif 
#if 0
// step 7-2.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
	struct _node *prev;
} NODE;

void __insert_data( NODE *temp, NODE *prev, NODE *next  )
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front( NODE *temp, NODE *head )
{
	__insert_data(temp, head, head->next  );
}

void insert_back( NODE *temp, NODE *head )
{
     __insert_data(temp, head->prev, head  );
}


//-----------------------------------------------------

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head  ; temp = temp->prev )
		printf("<->[%d]", temp->data );
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	NODE head = { 0, &head , &head };

	display(&head);
	for(i=0; i<7; i++ )
	{
		temp[i].data = i+1;
		insert_back( temp+i, &head);
		display(&head);
	}
	return 0;
}
#endif 
#if 0
// step 7-1.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
	struct _node *prev;
} NODE;

void insert_front( NODE *temp, NODE *head  )
{
	temp->next = head->next;
	head->next = temp;
	temp->prev = temp->next->prev;
	temp->next->prev = temp;
}

//-----------------------------------------------------

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head  ; temp = temp->prev )
		printf("<->[%d]", temp->data );
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	NODE head = { 0, &head , &head };

	display(&head);
	for(i=0; i<7; i++ )
	{
		temp[i].data = i+1;
		insert_front( temp+i, &head);
		display(&head);
	}
	return 0;
}
#endif 
#if 0
// step 7.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

void insert_data( NODE *temp, NODE *head  )
{
	temp->next = head->next;
	head->next = temp;
}

void reverse( NODE *head )
{
	NODE *prev = head;
	NODE *curr = prev->next;
	NODE *next; 

	while( curr != head )
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head->next = prev;
}
//-----------------------------------------------------

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head  ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	NODE head = { 0, &head };
	NODE head1 = { 0, &head1 };

	display(&head1);
	for(i=0; i<7; i++ )
	{
		temp[i].data = i+1;
		insert_data( temp+i, &head1);
		display(&head1);
	}
	reverse( &head1 );
	display(&head1);
	reverse( &head1 );
	display(&head1);
	return 0;
}
#endif 
#if 0
// step 6-1.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

void insert_data( NODE *temp, NODE *head  )
{
	temp->next = head->next;
	head->next = temp;
}
//-----------------------------------------------------

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head  ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	NODE head = { 0, &head };
	NODE head1 = { 0, &head1 };

	display(&head1);
	for(i=0; i<7; i++ )
	{
		temp[i].data = i+1;
		insert_data( temp+i, &head1);
		display(&head1);
	}
	return 0;
}
#endif 
#if 0
// step 6.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE head;

void init( NODE *head )
{
	head->next = head;
}

void insert_data( NODE *temp, NODE *head  )
{
	temp->next = head->next;
	head->next = temp;
}
//-----------------------------------------------------

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head  ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	init(&head);
	display(&head);
	for(i=0; i<7; i++ )
	{
		temp[i].data = i+1;
		insert_data( temp+i, &head);
		display(&head);
	}
	return 0;
}
#endif 
#if 0
// step 5-1.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE head;

void init()
{
	head.next = &head;
}

void insert_data( NODE *temp )
{
	temp->next = head.next;
	head.next = temp;
}
//-----------------------------------------------------

void display()
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head.next; temp != &head  ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	init();
	display();
	for(i=0; i<7; i++ )
	{
		temp[i].data = i+1;
		insert_data( temp+i );
		display();
	}
	return 0;
}
#endif 
#if 0
// step 5.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE head;

void init()
{
	head.next = &head;
}

void insert_data( NODE *temp )
{
	temp->next = head.next;
	head.next = temp;
}
//-----------------------------------------------------

void display()
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head.next; temp != &head  ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE *temp;
	init();
	display();
	for(i=0; i<7; i++ )
	{
		temp = (NODE*)malloc(sizeof(NODE));
		temp->data = i+1;
		insert_data( temp );
		display();
	}
	return 0;
}
#endif 
#if 0
// step 4.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE *head;

void init()
{
	head = (NODE*)malloc(sizeof(NODE));
	head->next = head;
}

void insert_data( int data )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}
//-----------------------------------------------------

void display()
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next;  ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	int i;
	init();
	display();
	for(i=0; i<7; i++ )
	{
		insert_data( i+1 );
		display();
	}
	return 0;
}
#endif 
#if 0
// step 3.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE *head, *tail;

void init()
{
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	head->next = tail;
	tail->next = tail;
}

void insert_data( int data )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}
//-----------------------------------------------------

void display()
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; temp = tail ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[tail]\n");
	getchar();
}

int main()
{
	int i;
	init();
	display();
	for(i=0; i<7; i++ )
	{
		insert_data( i+1 );
		display();
	}
	return 0;
}
#endif 
#if 0
// step 2.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE *head;

void init()
{
	head = (NODE*)malloc(sizeof(NODE));
	head->next = 0;
}


void insert_data( int data )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}
//-----------------------------------------------------

void display()
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head->next; ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("\n");
	getchar();
}

int main()
{
	int i;
	init();
	display();
	for(i=0; i<7; i++ )
	{
		insert_data( i+1 );
		display();
	}
	return 0;
}
#endif 
#if 0
// step 1.
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE *head;


void insert_data( int data )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head;
	head = temp;
}
//-----------------------------------------------------

void display()
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for( temp = head; temp != 0 ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("\n");
	getchar();
}

int main()
{
	int i;
	display();
	for(i=0; i<7; i++ )
	{
		insert_data( i+1 );
		display();
	}
	return 0;
}
#endif 






