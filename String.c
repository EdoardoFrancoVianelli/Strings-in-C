#include <stdio.h>
#include <stdlib.h>

typedef struct stringCharacter{ 
	char current;
	struct stringCharacter *next;
	struct stringCharacter *prev;
} stringCharacter;

typedef struct String{ 
	int length;
	stringCharacter *start;
} String;

String * initString(){ 
	String *s = malloc(sizeof(String));
	s->length = 0;
	s->start = 0;
	return s;
}

char removeCharacter(String **s, int i){ 
	char ret;
	int length = (*s)->length;
	if (i < 0 || i >= length){ 
		return -1;
	}
	stringCharacter *cur = (*s)->start;
	int k;
	for (k = 0; k < i - 1; k++){ 
		cur = cur->next;
	}
	stringCharacter *to_remove = cur->next;
	printf("removing %c\n", ret = cur->next->current);
	cur->next = cur->next->next;
	free(to_remove);
	return ret;
}

void addCharacter(String **s, char c){ 
	stringCharacter *newCharacter = malloc(sizeof(stringCharacter));
	newCharacter->current = c;
	newCharacter->next = 0;
	newCharacter->prev = 0;

	if ((*s)->start == 0){ 
		(*s)->start = newCharacter;
		(*s)->length++;
		return;
	}

	stringCharacter *cur = (*s)->start;

	while (cur->next != 0 && cur != 0){
		cur = cur->next;
	}

	newCharacter->prev = cur;
	cur->next = newCharacter;
	(*s)->length++;
}

void addString(String **s, char *str){ 
	while (*str){ 
		addCharacter(s, *str++);
	}
}

void printString(String *s){ 

	if (s == 0) return;

	stringCharacter * c = (s->start);

	while (c != NULL){ 
		putchar(c->current);
		c = c->next;
	}
	putchar('\n');
}













