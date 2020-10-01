/*
 *  lab2exe_B.c
 *
 *  ENSF 619 Fall 2020 Lab 2 Exercise B
 *
 */

int my_strlen(const char *s);
/*  Duplicates strlen from <string.h>, except return type is int.
 *  REQUIRES
 *     s points to the beginning of a string.
 *  PROMISES
 *     Returns the number of chars in the string, not including the
 *     terminating null.
 */

void my_strncat(char *dest, const char *source, int);
/*  Duplicates strncat from <string.h>, except return type is void.
 */
int my_strcmp(const char* str1, const char* str2);

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void)
{
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char* str3 = "-toe";
    
    /* point 1 */
    char str5[] = "ticket";
    char my_string[100]="";
    int bytes;
    int length;
    
    /* using my_strlen C libarary function */
    length = (int) my_strlen(my_string);
    printf("\nLine 1: my_string length is %d.", length);
    
    /* using sizeof operator */
    bytes = sizeof (my_string);
    printf("\nLine 2: my_string size is %d bytes.", bytes);
    
    /* using strcpy C libarary function */
    strcpy(my_string, str1);
    printf("\nLine 3: my_string contains: %s", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nLine 4: my_string length is %d.", length);
    
    my_string[0] = '\0';
    printf("\nLine 5: my_string contains:\"%s\"", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nLine 6: my_string length is %d.", length);
    
    bytes = sizeof (my_string);
    printf("\nLine 7: my_string size is still %d bytes.", bytes);
    printf("\n %s",my_string);
    /* my_strncat append the first 3 characters of str5 to the end of my_string */
    my_strncat(my_string, str5, 3);
    printf("\nLine 8: my_string contains:\"%s\"", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nLine 9: my_string length is %d.", length);
    
    my_strncat(my_string, str2,  4);
    printf("\nLine 10: my_string contains:\"%s\"", my_string);
    
    /* my_strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
    my_strncat(my_string, str3, 6);
    printf("\nLine 11: my_string contains:\"%s\"", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nLine 12; my_string has %d characters.", length);
    
    printf("\n\nUsing my_strcmp - C library function: ");
    
    printf("\n\"ABCD\" is less than \"ABCDE\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABCDE"));
    printf("\n\"ABCD\" is less than \"ABND\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABND"));
    printf("\n\"ABCD\" is equal than \"ABCD\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABCD"));
    printf("\n\"ABCD\" is less than \"ABCd\" ... my_strcmp returns: %d",
           my_strcmp("ABCD", "ABCd"));
    printf("\n\"Orange\" is greater than \"Apple\" ... my_strcmp returns: %d\n",
           my_strcmp("Orange", "Apple"));
    
    return 0;
}
int my_strlen(const char* s) {
    int i = 0;
    
    while (*s!='\0'){
        i++;
        s += sizeof(char);

    
    }
    
    return i;
}
void my_strncat(char* dest, const char* source, int size) {
    int k = 0;
    while(dest [k]!='\0')
    {
        
        k++;
    }
    
   
    for (int i = 0;i < size;i++) {
        
       
        dest[k+i] = source[i];
      
    }
    dest[k + size] = '\0';
}
int my_strcmp(const char* str1, const char* str2) {

    int value_str1 = 0;
    int value_str2 = 0;
    int k = 0;
    while (str1[k] != '\0')
    {
        value_str1 += (int)str1[k];
        k++;
    }
    k = 0;
    while (str2[k] != '\0')
    {
        value_str2 += (int)str2[k];
        k++;
    }
    if (value_str1 > value_str2)
        return 1;
    else if (value_str1 < value_str2)
        return -1;
    else
        return 0;

}
