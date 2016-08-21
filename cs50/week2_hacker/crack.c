#define _XOPEN_SOURCE       
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <cs50.h>

int sSize(string s)
{
	int n = 0;
	while(s[n])
		++n;
	return n;
}

int iLen(int i)
{
	int n = 1;
	while((i /= 10) > 0)
		++n;
	return n;
}

string intToStr(int n)
{
    if (n == 0) return "0";
    
    int len = iLen(n); 
    char str[len+1];
    snprintf(str, len+1, "%d", n);
    
    string s = str;
    return s;
}

char sEquals(string s1, string s2)
{
    if (sSize(s1) != sSize(s2))
        return false;
        
    for (int i = 0; i < sSize(s1); i++)
    {
        if (s1[i] != s2[i])
            return false;    
    }
    
    return true;
}

string makeHash(string psswd, string salt)
{
    return crypt(psswd, salt);
}

void findPswd(string hash, string salt)
{
    char found = false;
    
    for (int i = 0; !found && i < 100000; i++)
    {
        string temp = intToStr(i);
        string tHash = makeHash(temp, salt);
        if (sEquals(hash, tHash))
        {
            found = true;
            printf("%i \n", i);
        }
    }
    
    FILE *fp;
    
    int size = 1024, pos;
    int c;
    char *buffer = (char *)malloc(size);

    fp = fopen("/usr/share/dict/words", "r");

    if(fp) {
        do {
            pos = 0;
            do{
                c = fgetc(fp);
                if(c != EOF && c != '\n') buffer[pos++] = (char)c;
                if(pos >= size - 1) {
                    size *=2;
                    buffer = (char*)realloc(buffer, size);
                }
            }while(c != EOF && c != '\n');
            buffer[pos] = 0;
            
            string tHash = makeHash(buffer, salt);
            if (sEquals(hash, tHash))
            {
                found = true;
                printf("%s \n", buffer);
            }
        } while(!found && c != EOF); 
    }
    
    free(buffer);

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {  
            printf("Improper command-line arguments\n");
                return 1;
    }

    char salt[3] = "xx";
    
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    
    findPswd(argv[1], salt);
}