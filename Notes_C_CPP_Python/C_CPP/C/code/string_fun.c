/*strlen():counts the length ofgiven string */
unsigned int my_strlen(const char *s)
{
    unsigned int count = 0;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}


/*
strcpy(): char* strcpy(char* destination, const char* source);
The strcpy() function copies the null-terminated C-string pointed to by source to the
memory pointed to by destination
*/
// Function to implement `strcpy()` function
char* strcpy(char* destination, const char* source)
{
    // take a pointer pointing to the beginning of the destination string
    char *ptr = destination;
 
    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    // include the terminating null character
    *destination = '\0';
 
    // the destination is returned by standard `strcpy()`
    return ptr;
}
 