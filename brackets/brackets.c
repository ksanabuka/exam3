#include <unistd.h>

int isBracket(char c)
{
	return (c == '(' || c == ')' || c == '{'  || c == '}' || c == '[' || c == ']') ? 1 : 0 ;	
}

int isCBracket (char c)
{
	return (c == ')' || c == '}' || c == ']') ? 1 : 0 ;	
}

int CheckPair (char open, char close)
{
	return ((close == ')' && open == '(') || (close == '}' && open == '{') || (close == ']' && open == '[')) ? 1 : 0;
}

int findReplaceOB (char *s, int Closeindex)
{
	if (Closeindex == 0)
		return 0;

	int i = Closeindex - 1;

	while (i >= 0)
	{
		while (i >= 0 && !isBracket(s[i]))
			i--;
		if (Closeindex >= 0 && isBracket(s[i]) && CheckPair(s[i], s[Closeindex]))
		{
			s[i] = ' ';
			s[Closeindex] = ' ';
			return 1;
		}
		else
			return 0;
	}
	return 0;
 }

int okStrforBrackets(char *s)
{
	while (*s)
	{

		if (!isBracket(*s))
			s++;
		else 
			return 0;
	}
	return 1;
}

void traverseString(char *s)
{
	int i = 0;
	while (s[i])
	{

		if (isCBracket(s[i]))
		{
			findReplaceOB(s, i);
		}
		i++; 
	}
}

int main(int ac, char ** av)
{
	if (ac == 1)
	{
		write(1, "\n", 1);
		return 0;
	}

	int i = 1;
	while (i < ac)
	{
		traverseString(av[i]);
		(okStrforBrackets(av[i])) ? write(1, "OK\n", 3) :  write(1, "Error\n", 6);
		i++;
	}
	return 0;
}

