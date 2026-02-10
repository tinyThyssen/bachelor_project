#include <stdio.h>
#include <stdbool.h>

// guide to C programming language using C17 standard
// I have examples of variable declarations and print statements and other things so i can remember later

int main(){ // main function - starting point of the program

    // this is a comment
    // how to make multi line comments in C
    /*
    this
    is
    also
    a
    comment
    */

    // --- Print Statements ---
    printf("Hello, World\n"); // print "Hello, World" to the console. include \n for new line

    // --- Variables ---
    // variable is a container for a value. Behaves like the value itself
    int age = 23; // integer variable
    float gpa = 2.5; // floating point variable
    double pi = 3.141592653589793; // double precision floating point variable
    char grade = 'A'; // char variable to store a single character
    char name[] = "Christian"; // store more text using string (array of characters)
    bool isStudent = true; // boolean variable to store true/false value
    // to print variables, use format specifiers in printf
    printf("I am %d years old.\n", age); // %d for integer
    printf("My GPA is %f.\n", gpa); // %f for float
    printf("The value of pi is %lf.\n", pi); // %lf for double
    printf("Your grade is %c.\n", grade); // %c for char
    printf("My name is %s.\n", name); // %s for string
    printf("Am I a student? %s.\n", isStudent ? "Yes" : "No"); // print boolean
    if(isStudent){ // conditional statement. print the boolean value
        printf("You are a student.\n");
    } else{
        printf("You are not a student.\n");
    }

    // --- Format specifiers --- 
    int num1 = 1;
    int num2 = 10;
    int num3 = -100;
    float price1 = 19.99;
    float price2 = 3.5;
    float price3 = -123.4567;
    printf("%4d\n", num1); // interger with minimum width of 4 characters
    printf("%-4d\n", num2); // interger with minimum 4 width on the left (left aligned)
    printf("%04d\n", num2);  // interger with mimimum width of 4, empy spaces become 0s
    printf("%+d\n", num3); // interger with sign always displayed
    printf("%.1f\n", price2); // display 1 decimal place
    printf("%+5.3f\n", price3); // we can also combine width and precision

    // --- Arithmetic Operations ---
    int x = 2;
    int y = 3;
    int z = 0;

    // z = x + y, // Addition
    // z = x - y; // Subtraction
    // z = x * y; // multiplication
    // z = x / y; // division. We have to make z and y a floating point number, bc int cannot store decimal values. Also we must divide by a float to get a float result
    z = x % y; // modulus operator gives remainder of division. only works with integers
    x++; // increment x by 1
    y--; // decrement y by 1

    // other shortcuts
    // x = x + 2; // simple
    // x += 2; // same result as above, but shorter
    // y = y - 3 ; // simple
    // y -= 3; // same result as above, but shorter
    x *= 2; // multiply x by 2 and store result in x
    y /= 3; // divide y by 3 and store result in y

    // condition ? value_if_true : value_if_false
    // ternary operator. shorthand for if-else statement
    int max = (x > y) ? x : y; // assign max to x if x is greater than y, otherwise assign max to y


    // --- User input in C ---
    // int age; // declare variable to store age. printing this will lead to undefined behavior
    int age = 0; // Instead initialize to 0
    float gpa = 0.0f; // initialize to 0.0 to avoid undefined behavior. f tells compiler it's a float
    char grade = '\0'; // initialize to null character
    char name[30] = ""; // initialize to empty string

    printf("%d\n", age);
    printf("%f\n", gpa);
    printf("%c\n", grade);
    printf("%s\n", name);

    // instead of printf we use scanf to get user input
    printf("Enter your age: ");
    scanf("%d", &age); // & is the adress of operator
    // now print age and see that it works

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    printf("Enter your grade: ");
    scanf(" %c", &grade); // note the space before %c to consume any leftover whitespace

    // printf("Enter your name: ");
    // scanf("%s", name); // cannot read white spaces with scanf. Stops at first whitespace

    getchar(); // This line consumes the leftover newline character from previous input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // reads string with spaces. stdin is standard input. fgets adds \n at the end
    name[strlen(name) - 1] = '\0'; // removes trailing character and sets it to the null terminator

    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);
    printf("%s\n", name);


    // --- Example of a shopping cart program ---
    char itemName[50] = ""; // strin to store item name
    float price = 0.0f; // float to store price
    int quantity = 0; // int to store quantity
    char currency = '$'; // char for the currency symbol
    float total = 0.0f; // float to store total price

    printf("What item would you like to purchase? "); // prompt user for item name
    fgets(itemName, sizeof(itemName), stdin); // fgets reads string with spaces
    itemName[strlen(itemName) - 1] = '\0'; // remove trailing newline character

    printf("What is the price for each item? ");
    scanf("%f", &price); // read float input

    printf("How many items would you like to buy? ");
    scanf("%d", &quantity); // %d for int read integer input

    total = price * quantity; // calculate total price

    printf("You have purchased %d %s/s at a price of %.2f%c each.\n", quantity, itemName, price, currency);
    printf("Your total is: %c%.2f\n", currency, total);



    // MAD LIBS game

    char noun[50] = ""; // string to store noun. person or place or thing
    char verb[50] = ""; // string to store verb. action word
    char adjective1[50] = ""; // string to store adjective. describes a noun
    char adjective2[50] = ""; // string to store another adjective
    char adjective3[50] = ""; // string to store another adjective

    printf(" Enter an adjective: ");
    fgets(adjective1, sizeof(adjective1), stdin); // read string input with spaces. stdin is standard input
    adjective1[strlen(adjective1) - 1] = '\0'; // remove trailing newline character

    printf(" Enter a noun: ");
    fgets(noun, sizeof(noun), stdin); // read string input with spaces
    noun[strlen(noun) - 1] = '\0'; // remove trailing newline character

    printf(" Enter an adjective: ");
    fgets(adjective2, sizeof(adjective2), stdin); // read string input with spaces
    adjective2[strlen(adjective2) - 1] = '\0'; // remove trailing newline character

    printf(" Enter a verb (-ing): ");
    fgets(verb, sizeof(verb), stdin); // read string input with spaces
    verb[strlen(verb) - 1] = '\0'; // remove trailing newline character
    
    printf(" Enter an adjective: ");
    fgets(adjective3, sizeof(adjective3), stdin); // read string input with spaces
    adjective3[strlen(adjective3) - 1] = '\0'; // remove trailing newline character


    printf("The %s %s was %s %s while %s.\n", adjective1, noun, adjective2, verb, adjective3);
    printf("Today i went to a %s zoo. \n", adjective1);
    printf("In the exhibit, I saw a %s. \n", noun);
    printf("%s was %s and %s! \n", noun, adjective2, verb);
    printf("I was %s! \n", adjective3);



    // ---  C math functions --- 

    int x = 2;
    float y = 3.14;
    int z = -3;
    float a = 2.71828;
    float b = 1.5;

    // x = sqrt(x); // square root of x
    x = pow(x, 4); // x raised to the power of n. Raise x to given power and store result in x

    // y = round(y); // round y to nearest integer and store result in y
    y = ceil(y); // round y up to nearest integer and store result in y
    // y = floor(y); // round y down to nearest integer and store result in y

    z = abs(z); // absolute value of z and store result in z

    a = log(a); // natural logarithm of a and store result in a
    // a = log10(a); // logarithm base 10 of a and store result
    // a = exp(a); // exponential of a and store result in a

    b = sin(b); // sine of b (b in radians) and store result in b
    // b = cos(b); // cosine of b (b in radians) and store result in b
    // b = tan(b); // tangent of b (b in radians) and store result in b
    
    
    printf("%d\n", x);
    printf("%.2f\n", y); // print y with 2 decimal places
    printf("%d\n", z);
    printf("%.5f\n", a); // print a with 5 decimal places
    printf("%.5f\n", b); // print b with 5 decimal places




    // --- Circle calculator ---

    double radius = 0.0;
    double area = 0.0;
    double PI = 3.141592653589793;
    double surfaceArea = 0.0;
    double volume = 0.0;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius); // read double input for radius

    area = PI * pow(radius, 2); // calculate area using double precision
    printf("The area of the circle is: %.2lf\n", area); // print area with 2 decimal places

    surfaceArea = 4 * PI * pow(radius, 2); // calculate surface area of sphere using double precision
    printf("The surface area of the sphere is: %.2lf\n", surfaceArea); // print surface area with 2 decimal places

    volume = (4.0 / 3.0) * PI * pow(radius, 3); // calculate volume of sphere using double precision
    printf("The volume of the sphere is: %.2lf\n", volume); // print volume with 2 decimal places

   return 0; // indicate that program ended successfully. 0 means success, other values indicate errors. Standard practice in C.
}