#include <stdio.h>
#include <string.h>

int checkISBN(char isbn[])
{
    int I[10], T = 0;

    if (strlen(isbn) != 10)
    {
        printf("Do dai ISBN khong hop le, ISBN phai co 10 chu so.\n");
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (isbn[i] < '0' || isbn[i] > '9')
        {
            printf("Khong hop le. ISBN chi chua cac chu so.\n");
            return 0;
        }
        I[i] = isbn[i] - '0';
    }

    for (int i = 0; i < 9; i++)
    {
        T += I[i] * (10 - i);
    }
    
    T += I[9];

    return (T % 11 == 0);
}

int main()
{

    char isbn[] = "0003194876";
    if (checkISBN(isbn))
        printf("ISBN hop le: %s\n", isbn);
    else
        printf("ISBN khong hop le: %s\n", isbn);

    return 0;
}
