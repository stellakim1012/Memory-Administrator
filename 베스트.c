/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
int total = 0;
int fail = 0;

typedef struct chunk {
	int start;		// 메모리 덩어리의 시작 주소
	int size;		// 메모리 덩어리 크기
	struct chunk* link;		// 다음 빈 공간에 대한 링크
}Chunk;

Chunk* head;

void Init_available(Chunk* available)
{
	available->start = 0;
	available->size = MAX;
	available->link = NULL;
	head = available;

	printf("%d \n", available->start);
	printf("%d \n\n", available->size);
}

int myalloc(Chunk* available, int request_size)
{
	total += 1;

	int temp = 0;

	Chunk* before;
	Chunk* current;
	before = head;
	current = head;

	int index = 0;
	int best = 0;
	int min = MAX;

	while (current != NULL)
	{
		if (((current->size - request_size) < min) && (current->size >= request_size))
		{
			temp = current->start;
			min = current->size - request_size;
			best = index;
			current = current->link;
		}
		else
		{
			if (current->link == NULL && before->size < request_size)
			{
				fail += 1;
				return -1;
				break;
			}
			current = current->link;
		}
		index += 1;
	}

	before = head;
	current = head;

	for (int i = 0; i < best; i++)
	{
		before = current;
		current = current->link;
	}

	if (min == 0)
	{
		before->link = current->link;
		current = current->link;
		if (head->size == request_size)
		{
			head = head->link;
		}
	}
	else
	{
		temp = current->start;
		current->start += request_size;
		current->size -= request_size;
	}

	return temp;
}

void myfree(Chunk* available, int start_address, int return_size)
{
	Chunk* newchunk = (Chunk*)malloc(sizeof(Chunk));
	newchunk->start = start_address;
	newchunk->size = return_size;

	Chunk* temp;
	Chunk* temp2;
	temp = available;
	temp2 = temp;
	Chunk* next;
	Chunk* next2;
	next = temp->link;
	next2 = next;

	int case_num = 0;
	int case_num2 = 0;

	if (next == NULL)
	{
		case_num = 1;
		case_num2 = 1;
	}

	switch (case_num)
	{
	case 0:
		while (1)
		{
			if (next == NULL || (next->start > newchunk->start))
			{
				newchunk->link = temp->link;
				temp->link = newchunk;
				break;
			}
			else
			{
				temp = next;
				next = next->link;
			}
		}
		break;
	case 1:
		temp->link = newchunk;
		newchunk->link = NULL;
		break;
	}

	switch (case_num2)
	{
	case 0:
		while (next2 != NULL)
		{
			if (temp2->start + temp2->size == next2->start)
			{
				temp2->link = next2->link;
				temp2->size += next2->size;
				next2 = next2->link;
			}
			else
			{
				temp2 = next2;
				next2 = next2->link;
			}
		}
		break;
	case 1:
		break;
	}
}

void display(Chunk* available)
{
	Chunk* temp;
	temp = head;
	float success = total - fail;
	if (temp == NULL)
	{
		printf("현재까지의 할당 성공률: %f \n", success / total);
		printf("가용 가능한 메모리가 없습니다!\n\n");
		return 0;
	}
	while (temp->link != NULL)
	{
		printf("start: %d size: %d \n", temp->start, temp->size);
		temp = temp->link;
	}
	printf("start: %d size: %d \n", temp->start, temp->size);
	printf("현재까지의 할당 성공률: %f \n\n", success/total);
}


void main()
{
	Chunk available;
	Init_available(&available);

	int a = myalloc(&available, 40);
	printf("a: %d \n", a);
	display(&available);
	int b = myalloc(&available, 20);
	printf("b: %d \n", b);
	display(&available);
	int c = myalloc(&available, 30);
	printf("c: %d \n", c);
	display(&available);
	printf("free b\n");
	myfree(&available, b, 20);
	display(&available);
	int d = myalloc(&available, 10);
	printf("d: %d \n", d);
	display(&available);
	printf("free d\n");
	myfree(&available, d, 10);
	display(&available);
	int e = myalloc(&available, 10);
	printf("e: %d \n", e);
	display(&available);
	int f = myalloc(&available, 20);
	printf("f: %d \n", f);
	display(&available);
}
*/