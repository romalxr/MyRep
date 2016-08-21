#include <cs50.h>
#include <stdio.h>

int sSize(string s)
{
	
	int n = 0;
	while(s[n])
		++n;
	return n;
}

int isAlpha(char c)
{
	if (c >= 65 && c <= 90)
		return true;
	if (c >= 65+32 && c <= 90+32)
		return true;
	return false;
}

char toUpper(char c)
{
	if (c >= 65+32 && c <= 90+32)
		c -= 32;
	
	return c;
}

void printInitials(string name)
{
	int n = sSize(name);
	int wordStarted = false;
	int count = 0;
	char res[10];
	
	for(int i = 0; i < n; i++)
	{
		if (isAlpha(name[i]))
		{
			if (!wordStarted)
			{
				wordStarted = true;
				res[count++] = toUpper(name[i]);	
			}
		}
		else
		{
			wordStarted = false;	
		}
	}
	res[count] = '\0';
	printf("%s\n", res);
}

int main(void)
{
	string name = GetString();
	printInitials(name);

	return 0;
}
