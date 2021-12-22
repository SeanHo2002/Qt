#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char* school;
	char* name;
}student;
void a(void* param)
{
	char* n = ((student*)param)->name;
	char* s = ((student*)param)->school;
	int i;
	for (i = 0; i < 20; i++)
	{
		printf("%d:I'm %s,my school is %s\n",i, n, s);
		Sleep(500);
	}
}
int main(void)
{
	char n[20];
	char s[20];
	printf("Name:");
	scanf("%s", n);
	printf("School:");
	scanf("%s", s);
	student in = { .name = n,.school = s };
	_beginthread(a, 0, &in);
	for (int i = 0; i < 10; i++)
	{
		printf("I'm Main thread, i = %d\n", i);
		Sleep(1000);
	}
	return 0;
}