#include <stdio.h>

int main(void)
{
    double *student;  // declare a pointer variable named student that can point to a variable of type double
    double grades[5]; // declare grades to be a 5-element array of double

    student = &grades[4];  // make the student variable point to the last element of grades
    *student = 17;         // make the double pointed to by student equal to 17, using the * operator
    *(grades + 3) = 72;    // without using the student pointer, and without using square brackets, set the fourth element of the grades array to have the value 72
    student -= 3;          // move the student pointer back by three double
    (student + 1)[0] = 93; // using square brackets, but without using the name grades, set the third element of the grades array to have the value 93
    student[0] = 85;       // without using the * operator, but using square brackets, set the double pointed to by student to have the value 85

    // print the values of the grades array
    for (int i = 0; i < 5; i++)
    {
        printf("grades[%d] = %f\n", i, grades[i]);
    }

    return 0;
}