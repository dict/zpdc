

#if 1
#include <stdio.h>

int (*foo())[2] 
{
	static int a[2][2];
	return a;
}

int main()
{
	foo()[1][1] = 10;
}

#endif
#if 0
#include <stdio.h>

int (*)[2] foo()
{
	static int a[2][2];
	return a;
}

int main()
{
	int (*p)[2] = foo();
	p[1][1] = 10;
}

#endif
#if 0
#include <stdio.h>
void foo( int (*a)[2][2]  )
{
	a[1][1][1] = 10;
}

int main()
{
	int a[2][2][2];

	foo(a);

}
#endif
#if 0
#include <stdio.h>
void foo( int (*a)[2] )
{
	a[1][1] = 10;
}

int main()
{
	int a[2][2];

	foo(a);

}
#endif
#if 0
#include <stdio.h>
int main()
{
	int a[2][2] = {1,2,3,4};
	int (*p)[2]  = a;

	p[1][1] = 10;

}
#endif
#if 0
#include <stdio.h>
int main()
{
	int a[2][2] = {1,2,3,4};
	int **p = a;

	p[1][1] = 10;

}
#endif
#if 0
#include <stdio.h>
int main()
{
	int a[2][2] = {1,2,3,4};
	int *p = a;

	p[1][1] = 10;

}
#endif
#if 0
#include <stdio.h>
int main()
{
	int a[4]  = {1,2,3,4};
	int (*p)[4]  = &a;  
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a[4] = {1,2,3,4};
	int **p = &a;  
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int a[4] = {1,2,3,4};
	int *p = a;  
	printf("sizeof(p)=%lu\n", sizeof(p) );
	printf("sizeof(int*)=%lu\n", sizeof(int*) );
	printf("sizeof(a)=%lu\n", sizeof(a) );
	printf("sizeof(int[4])=%lu\n", sizeof(int[4]) );
}
#endif


#if 0
#include <stdio.h>
int main()
{
	int a[2] = {1,2};
	int *p = a;  
	printf("sizeof(p)=%lu\n", sizeof(p) );
	printf("sizeof(a)=%lu\n", sizeof(a) );
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int ip = 0x12345678;
	char *p = (char*)&ip;
	int i;
	for(i=0; i<4; i++ )
		printf("%x\n", p[i] );
}
#endif
#if 0
int main()
{
	char a=10;
	int *b = &a;

	*b = 10;
}
#endif

#if 0
int main()
{
	char a=10;

	int b = a;
}
#endif
