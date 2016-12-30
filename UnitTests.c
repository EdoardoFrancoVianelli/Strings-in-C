

void addUnitTest(){ 

	String *s = initString();

	char *test_empty_add = "this is a string";

	printf("Adding [%s] to empty string\n", test_empty_add);

	while (*test_empty_add)	{ 
		addCharacter(&s, *test_empty_add++);
	}

	printString(s);

	char *test_non_empty_add = " that I made";

	printf("Adding [%s]\n", test_non_empty_add);

	addString(&s, test_non_empty_add);

	printString(s);
}