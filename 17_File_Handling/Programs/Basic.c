/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 17 File Handling
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char  name[30];
    int   roll;
    float gpa;
} Student;

void write_text_file(void) {
    FILE *fp = fopen("/tmp/students.txt","w");
    if(!fp){perror("fopen");exit(1);}

    Student students[] = {
        {"Alice Johnson",101,9.2f},
        {"Bob Kumar",    102,8.5f},
        {"Carol Singh",  103,9.8f},
    };
    int n = 3;
    fprintf(fp, "%d\n", n);
    for(int i=0;i<n;i++)
        fprintf(fp,"%-25s %3d %.2f\n",students[i].name,students[i].roll,students[i].gpa);

    fclose(fp);
    printf("Written %d records to /tmp/students.txt\n", n);
}

void read_text_file(void) {
    FILE *fp = fopen("/tmp/students.txt","r");
    if(!fp){perror("fopen");exit(1);}

    int n;
    fscanf(fp,"%d\n",&n);
    printf("\nRead %d records:\n",n);
    printf("%-25s %5s  %4s\n","Name","Roll","GPA");
    printf("%-25s %5s  %4s\n","────","────","───");

    char name[30]; int roll; float gpa;
    for(int i=0;i<n;i++){
        fscanf(fp,"%[^\n] %d %f\n",name,&roll,&gpa);
        printf("%-25s %5d  %.2f\n",name,roll,gpa);
    }
    fclose(fp);
}

void write_binary_file(void) {
    Student students[] = {
        {"Alice",101,9.2f},
        {"Bob",  102,8.5f},
        {"Carol",103,9.8f},
    };
    FILE *fp = fopen("/tmp/students.bin","wb");
    fwrite(students, sizeof(Student), 3, fp);
    fclose(fp);
    printf("\nBinary: Written 3 Student records (%zu bytes each)\n",sizeof(Student));
}

void read_binary_file(void) {
    FILE *fp = fopen("/tmp/students.bin","rb");
    if(!fp){perror("fopen");exit(1);}

    /* Get file size */
    fseek(fp,0,SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    int n = size / sizeof(Student);
    printf("Binary file size: %ld bytes = %d records\n",size,n);

    Student s;
    for(int i=0;i<n;i++){
        fread(&s,sizeof(Student),1,fp);
        printf("  [%d] %-20s Roll=%d GPA=%.1f\n",i+1,s.name,s.roll,s.gpa);
    }
    fclose(fp);
}

void word_count(const char *filename) {
    FILE *fp = fopen(filename,"r");
    if(!fp) return;
    int chars=0,words=0,lines=0;
    int in_word=0;
    int c;
    while((c=fgetc(fp))!=EOF){
        chars++;
        if(c=='\n') lines++;
        if(c==' '||c=='\t'||c=='\n'){in_word=0;}
        else if(!in_word){in_word=1;words++;}
    }
    fclose(fp);
    printf("\nWord count for %s: %d chars, %d words, %d lines\n",
           filename,chars,words,lines);
}

int main(void){
    write_text_file();
    read_text_file();
    write_binary_file();
    read_binary_file();
    word_count("/tmp/students.txt");
    return 0;
}
