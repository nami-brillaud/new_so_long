#include <unistd.h>
#include <stdio.h>

int	char_count(char *line, char c)
{
	int	count;

	count = 0;
	while (*line != '\0')
	{
		if (*line++ == c)
			count++;
	}
	return (count);
}

int main(void)
{
	char line[] = "1P0011EE00001";

	printf("number of 1 is %d\n", char_count(line, '1'));
	printf("number of E is %d\n", char_count(line, 'E'));
	printf("number of C is %d\n", char_count(line, 'C'));
	printf("number of 0 is %d\n", char_count(line, '0'));
	printf("number of P is %d\n", char_count(line, 'P'));
	return (0);

}