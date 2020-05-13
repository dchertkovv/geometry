#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOLVE 200
#define SPACE ' '
#define NUM 6
#define BRCKT_O '('
#define BRCKT_C ')'
#define COMMA ','

void input(char*);
char* checking_spaces(char* p);
char* checking_symbol(char* p, char symbol);

struct point {
    long int x;
    long int y;
};

struct circle {
    struct point pt1;
    double radius;
};

int main()
{
    const char str2[10] = "circle";
    char str1[VOLVE];
    struct circle circ;

    input(str1);

    char* p = str1;

    p = checking_spaces(p);

    if (strncmp(p, str2, NUM) != 0) {
        printf("Error in the word:'circle'. Try again.\n");
        return 0;
    } else
        printf("The word '%s' is written correctly\n", str2);
    p = p + NUM;

    p = checking_spaces(p);

    p = checking_symbol(p, BRCKT_O);

    circ.pt1.x = strtol(p, &p, 10);
    if (circ.pt1.x == 0) {
        printf("The first coordinate is missing or inappropriate characters "
               "are enter. Try again.\n");
        return 0;
    } else
        printf("The first coordinate is entered correctly\n");

    circ.pt1.y = strtol(p, &p, 10);
    if (circ.pt1.y == 0) {
        printf("The second coordinate is missing or inappropriate characters "
               "are enter. Try again.\n");
        return 0;
    } else
        printf("The second coordinate is entered correctly\n");
    p = checking_spaces(p);

    p = checking_symbol(p, COMMA);

    p = checking_spaces(p);

    char array[200];
    char* ptr = array;
    while (('0' <= *p) && (*p <= '9')) {
        *ptr = *p;
        p++;
        ptr++;
    }
    if (*p == '.') {
        *ptr = *p;
        p++;
        ptr++;
    }
    while (('0' <= *p) && (*p <= '9')) {
        *ptr = *p;
        p++;
        ptr++;
    }
    if (ptr == array) {
        printf("The radius was not found or is in the wrong place. Try "
               "again.\n");
        return 0;
    }

    circ.radius = atof(array);
    p = checking_spaces(p);
    p = checking_symbol(p, BRCKT_C);

    printf("x = %ld\n", circ.pt1.x);
    printf("y = %ld\n", circ.pt1.y);
    printf("r = %f\n", circ.radius);
    return 0;
}

void input(char* str1)
{
    printf("Input the circle's coordinate and radius\n");
    printf("Input in this format: 'circle(x y, r)'\n");

    fgets(str1, VOLVE, stdin);
}

char* checking_spaces(char* p)
{
    while (*p == SPACE) {
        p++;
    }

    return p;
}

char* checking_symbol(char* p, char symbol)
{
    if (*p != symbol) {
        printf("The symbol '%c' was not found or is in the wrong place. Try "
               "again.\n",
               symbol);
        exit(0);
    } else {
        printf("The symbol '%c' is written correctly\n", symbol);
        p++;
        return p;
    }
}

/*char* checking_cor(char* p, struct circle* tr)
{
    tr -> pt1.x = strtol(p, &p, 10);
    if (tr -> pt1.x == 0)
    {
        printf ("The first coordinate is missing or inappropriate characters are
entered. Try again.\n"); return 0;
    }
    else
        printf("The first coordinate is entered correctly\n");

     tr -> pt1.y = strtol(p, &p, 10);
    if (tr -> pt1.y == 0)
    {
        printf ("The second coordinate is missing or inappropriate characters
are entered. Try again.\n"); return 0;
    }
    else
        printf("The second coordinate is entered correctly\n");
    return p;
}*/
