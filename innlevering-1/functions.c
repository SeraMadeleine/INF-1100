#include <stdio.h> // use to get functions like printf and scanf 
#include <string.h> // use in task 6, serlen 

/*
Puts the name of all the functions on top so i can have main right after. 
When doing this the functions are readeble even though they are further down 
in the script 
*/ 

void compare_values(int x, int y);
void myTriangles(int numlines);
int myPrimeFactor(int number, int primeFactor); 
void myNumbers(int startnum, int endnum);
int myLog2(unsigned int n);
void reverseString(char str[]);

/*---------------------------------- MAIN ------------------------------------------*/
int main (void) {
    int choice; // "Choise" is the value the user puts in when choosing from the menu  
    int startnum, endnum, primeFactor; // Numbers i had to declear outside the if else statement to make the function run

/* 
Use a while loop whit if else statments to make a menu. By using scanf the user can 
choose which task to run. The while loop will run as long as the user don´t chooses
0 - which will brake the loop. 
*/
    while (1){ // The menu is printet before you choose which program to run
        printf ("---- MENY ---- \n"); 
        printf ("0: Exit \n");
        printf ("1: Compare values \n"); 
        printf ("2: Print a triangel \n");
        printf ("3: Primefactor \n");
        printf ("4: Odd or even \n");
        printf ("5: log2 and bits \n");
        printf ("6: Revers string \n \n");
        printf ("Enter your choice: \n"); 
        scanf ("%d", &choice); // User input to decide which function to run

        if (choice == 0){ 
            break; // breakes you out of the loop 
        }  

        else if (choice == 1) { 
            int x = 3; // Declares the valu of x and y
            int y = 9; 
            compare_values(x, y); // Calls on the function from task 1 to compare x and y
        }   

        else if (choice == 2) { 
            int numlines; 
            printf("Enter the number of rows in the triangle: ");
            scanf("%d", &numlines); // The user chose who many rows the triangle will have 
            myTriangles(numlines); // Calls on the function from task 2, to make the triangel 
            }
            
        else if (choice == 3) {  
                int number, primeFactor;    // declares the numbers i will use in this function 
                printf("Write a number:"); 
                scanf("%d", &number); // User puts in the number he wants to check 

                printf("Whrite a prime factor:"); // User puts in a primenumber 
                scanf("%d", &primeFactor);

                /* Calls on the function from task 3 to check if the prime factor is a primefactor 
                in the given number */
                printf("%d \n", myPrimeFactor(number, primeFactor) ); 
        }

        else if (choice == 4) {     
            printf("Enter a integer to start with: "); 
            scanf("%d", &startnum); // User gives the program a startnumber 

            printf("Enter a integer to end with: "); 
            scanf("%d", &endnum);   // User gives the program a endnumber 

            /* Calls on the function from task 4 */
            myNumbers(startnum, endnum);  
        }

        else if (choice == 5) {
            int n = 8; // The number you want to find the binary logarithm of n(log2n)
            myLog2(n); // Calls on the function that gives you the binary logarithm of n(log2n)
        }

        else if (choice == 6) {
            char str[1000]; // Defines who long the string can be
            printf("Write in the string you want to reverse: \n");
            scanf("%[\n]s", str);   // %[\n] - read everything until a new line appears
            fgets (str, sizeof(str), stdin); // fgets gets a string and prints it whit spaces 
            
            reverseString(str); // Calls on the function from task 6
            printf("String After Reverse: \n  %s \n", str);
        }
        
        else { // If user input is somthing else then the numbers 0-6, you will get a message telling you that you input is not valid 
            printf("Your input is not valid \n \n");
        }
        
    }
    return 0; 
}

/*--------------------------- THE FUNCTIONS --------------------------------*/

// Task 1. The function should compare two numbers, and tell you which is the bigges or if they are eqaul. 
void compare_values(int x, int y) {
    if(x > y) // If x is the biggest numer, x will be printed 
        printf("%d is the biggest number \n", x); 

    else if (x == y) // If x and y are equal, the following will be printed;  
       printf("%d = %d, the numbers are equal.\n", x, y); 
    
    else // // If y is the biggest numer, y will be printed 
        printf("%d is the biggest number \n", y); 
}

// Task 2. The function will print a triangel whit a given number of rows 
void myTriangles(int numlines) { // Makes a nested forloop
    int i, j; //declare the values i = rows , j = colums
   for (i = 1; i <= numlines; i++){ /* the outer loop, tells the program to add 1 to 
                                    i for eatch time the look runs, as long as i is less 
                                    or eqal to numline */
      for (j = 1; j <= i; j++){ /* the inner loop, tells the program to add 1 to 
                                    j for eatch time the look runs, as long as j is less or
                                    eqal to j, and for prints "*"" equal to the value of j*/
         printf("*"); // Prints * for each row (1 in row 1, 2 in row 2, and so on.)
      }
      printf("\n"); // Tells the program to jump to a new line befor running the loop all over again 
   }
}

// Task 3. The fuction will tell if the given primefactor is a primefactor in the given number 
int myPrimeFactor(int number, int primeFactor) {
    if (number%primeFactor == 0) {  /* If the prime number adds up perfectly the result of the modulus operation 
                                    eqals 0, then we asks for the reuturn of 1 (means that it is true). 
                                    If the modulo operation gives you anything else the output will be 0 (false)*/
        return 1; // If it is a primefactor it returns 1 to the terminal 
        }
    else {
        return 0; // If it is not a primefactor it returns 0 to the terminal 
        }
}

/* Task 4. The function will tell you if the given numbers in a string is odd or 
even and if they have a given primenumber */
void myNumbers(int startnum, int endnum) {
    int primeFactor = 5; 
    for (int i = startnum; i <= endnum; i++) { /*The for-loop will run as long as 
    the conditions are true, and for each time it runs it will add 1 to the number (i) */
        if (i%2 == 0) { // The number is even if it is perfectly divisible by 2
            printf("%d is even", i); } 
        else {
            printf("%d is odd", i);}

        if (myPrimeFactor (i, primeFactor) == 0) { /* Calles on the function from task 3 
        to evaluate if the given primenumer is a primnumber in the given number */
            printf (" and %d is not a prime number. \n", primeFactor); } 
        else 
            printf (" and %d is a prime number. \n", primeFactor);
    }
}

// Task 5. 
int myLog2(unsigned int n) {
    int i, j; // declare the values
    while(n != 0) {
        n = n >> 1;  
        j = i++; // Put j = i++ to prevent it from counting the first time the loop is run 
    }
    printf("%d \n", j); // prints the number of the times the loop runs. 
    /* you may also use printf("%d \", i - 1) insted of j. It will give the same result. */ 
    
return 0;
}

// Task 6 
void reverseString(char str[])
{
  int n = strlen(str); // declare the values, strlen calculates the length of the string

  for (int i = 0; i < n / 2; i++) // swap the characters of the string
  {
    char ch = str[i]; // declare char as a sting whit i characters
    str[i] = str[n - i - 1]; // jumps to the last character and reads from their 
    str[n - i - 1] = ch; // Updates the string 
  }
}