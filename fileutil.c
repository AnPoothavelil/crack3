#include <stdio.h>
#include <string.h>

// Max char length
#define STR_MAX 100

// Function prototypes
int stringLength(char m[]);
void reverse(char m[]);
void trim(char m[]);

// Main function
int main()
{
    char input[STR_MAX];
	
    // Loop until we break out
    while (1)
    {
        printf("Enter a string: ");
        fgets(input, STR_MAX, stdin);  

        if (input[0] == '.')  // Break out of loop when first char is '.'
        {
            break;
        }
		
        // Trim the newline
        trim(input);

        // Print the trimmed string
        printf("After trim: %s\n", input);
		
        // Reverse the string
        reverse(input);
		
        // Print the reversed string
        printf("Reversed: %s\n", input);
    }
}

// Function to find the string length
int stringLength(char m[])
{
    int length = 0;
    while (m[length] != '\0')
    {
        length++;
    }
    return length;
}

// Function to reverse the string
void reverse(char m[])
{
    int len = stringLength(m);
    for (int i = 0; i < len / 2; ++i)
    {
        char temp = m[i];
        m[i] = m[len - i - 1];
        m[len - i - 1] = temp;
    }
}

// Function to trim the newline character
void trim(char m[])
{
    int len = stringLength(m);
    if (len > 0 && m[len - 1] == '\n')
    {
        m[len - 1] = '\0';
    }
}
