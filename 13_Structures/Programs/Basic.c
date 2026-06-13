/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 13 Structures
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char  name[50];
    int   roll;
    float gpa;
    char  branch[20];
} Student;

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char  name[50];
    Date  dob;
    float salary;
} Employee;

void print_student(const Student *s) {
    printf("%-20s %5d  %.2f  %s\n", s->name, s->roll, s->gpa, s->branch);
}

void sort_by_gpa(Student arr[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j].gpa < arr[j+1].gpa){
                Student tmp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=tmp;
            }
}

int main(void) {
    /* Single struct */
    printf("=== Single Structure ===\n");
    Student s1 = {"Alice Johnson", 101, 9.2f, "CSE"};
    printf("Name: %s\n",  s1.name);
    printf("Roll: %d\n",  s1.roll);
    printf("GPA:  %.2f\n",s1.gpa);
    printf("Branch: %s\n",s1.branch);

    /* Designated init */
    Student s2 = {.name="Bob Kumar", .roll=102, .gpa=8.5f, .branch="ECE"};

    /* Array of structs */
    printf("\n=== Array of Structures ===\n");
    Student class[] = {
        {"Alice",   101, 9.2f, "CSE"},
        {"Bob",     102, 8.5f, "ECE"},
        {"Carol",   103, 9.8f, "CSE"},
        {"Dave",    104, 7.9f, "ME"},
        {"Eve",     105, 8.1f, "EEE"},
    };
    int n = sizeof(class)/sizeof(class[0]);
    printf("%-20s %5s  %4s  %s\n","Name","Roll","GPA","Branch");
    printf("%-20s %5s  %4s  %s\n","────","────","───","──────");
    for(int i=0;i<n;i++) print_student(&class[i]);

    sort_by_gpa(class,n);
    printf("\nAfter sorting by GPA (desc):\n");
    for(int i=0;i<n;i++) print_student(&class[i]);

    /* Nested struct */
    printf("\n=== Nested Structure ===\n");
    Employee emp = {"Raj Sharma", {15,8,1990}, 75000.0f};
    printf("Name:   %s\n",   emp.name);
    printf("DOB:    %02d/%02d/%04d\n", emp.dob.day, emp.dob.month, emp.dob.year);
    printf("Salary: ₹%.2f\n",emp.salary);

    /* Memory layout */
    printf("\n=== Memory Layout ===\n");
    printf("sizeof(Student)  = %zu bytes\n", sizeof(Student));
    printf("sizeof(Date)     = %zu bytes\n", sizeof(Date));
    printf("sizeof(Employee) = %zu bytes\n", sizeof(Employee));

    return 0;
}
