/*
 * ===================================================================
 *  File    : main.c
 *  Topic   : 23 Mini Projects
 *  Level   : Project
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc main.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS  100
#define DATA_FILE     "/tmp/students_sms.dat"

/* ── Data Model ───────────────────────────────────────────────────────── */
typedef struct {
    int   roll;
    char  name[50];
    char  branch[20];
    int   semester;
    float gpa;
    int   active;   /* 0 = deleted (soft delete) */
} Student;

/* ── Global State ─────────────────────────────────────────────────────── */
Student db[MAX_STUDENTS];
int     count = 0;

/* ── Utility ──────────────────────────────────────────────────────────── */
void clear_screen(void) { printf("\033[2J\033[H"); }
void press_enter(void)   { printf("\nPress Enter to continue..."); getchar(); getchar(); }
void header(const char *title) {
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║  %-44s║\n", title);
    printf("╚══════════════════════════════════════════════╝\n");
}

char grade_from_gpa(float gpa) {
    if (gpa>=9.0) return 'O';
    if (gpa>=8.0) return 'A';
    if (gpa>=7.0) return 'B';
    if (gpa>=6.0) return 'C';
    if (gpa>=5.0) return 'D';
    return 'F';
}

int roll_exists(int roll) {
    for(int i=0;i<count;i++)
        if(db[i].active && db[i].roll==roll) return 1;
    return 0;
}

int active_count(void) {
    int c=0;
    for(int i=0;i<count;i++) if(db[i].active) c++;
    return c;
}

/* ── File Operations ──────────────────────────────────────────────────── */
void save_to_file(void) {
    FILE *fp = fopen(DATA_FILE,"wb");
    if(!fp){printf("Error saving!\n");return;}
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(db, sizeof(Student), count, fp);
    fclose(fp);
}

void load_from_file(void) {
    FILE *fp = fopen(DATA_FILE,"rb");
    if(!fp) return;
    fread(&count, sizeof(int), 1, fp);
    fread(db, sizeof(Student), count, fp);
    fclose(fp);
}

/* ── CRUD Operations ──────────────────────────────────────────────────── */
void add_student(void) {
    header("ADD NEW STUDENT");
    if(count>=MAX_STUDENTS){printf("Database full!\n");press_enter();return;}

    Student s;
    s.active = 1;

    printf("Roll Number : "); scanf("%d",&s.roll);
    if(roll_exists(s.roll)){
        printf("Roll %d already exists!\n",s.roll);
        press_enter(); return;
    }
    printf("Name        : "); scanf(" %49[^\n]",s.name);
    printf("Branch      : "); scanf(" %19s",s.branch);
    printf("Semester    : "); scanf("%d",&s.semester);
    printf("GPA (0-10)  : "); scanf("%f",&s.gpa);

    if(s.gpa<0||s.gpa>10||s.semester<1||s.semester>8){
        printf("Invalid GPA or semester!\n"); press_enter(); return;
    }

    db[count++] = s;
    save_to_file();
    printf("\n✓ Student '%s' (Roll %d) added successfully!\n",s.name,s.roll);
    press_enter();
}

void view_all(void) {
    header("ALL STUDENTS");
    int n = active_count();
    if(n==0){printf("No records found.\n");press_enter();return;}

    printf("%-6s %-25s %-10s %-5s %-6s %s\n",
           "Roll","Name","Branch","Sem","GPA","Grade");
    printf("%-6s %-25s %-10s %-5s %-6s %s\n",
           "────","────────────────────────","──────────","───","─────","─────");
    for(int i=0;i<count;i++) {
        if(!db[i].active) continue;
        printf("%-6d %-25s %-10s %-5d %-6.2f  %c\n",
               db[i].roll, db[i].name, db[i].branch,
               db[i].semester, db[i].gpa, grade_from_gpa(db[i].gpa));
    }
    printf("\nTotal active students: %d\n",n);
    press_enter();
}

void search_student(void) {
    header("SEARCH STUDENT");
    int roll;
    printf("Enter Roll Number: "); scanf("%d",&roll);
    for(int i=0;i<count;i++){
        if(db[i].active && db[i].roll==roll){
            printf("\n┌─────────────────────────────┐\n");
            printf("│ Roll No  : %-18d│\n",db[i].roll);
            printf("│ Name     : %-18s│\n",db[i].name);
            printf("│ Branch   : %-18s│\n",db[i].branch);
            printf("│ Semester : %-18d│\n",db[i].semester);
            printf("│ GPA      : %-18.2f│\n",db[i].gpa);
            printf("│ Grade    : %-18c│\n",grade_from_gpa(db[i].gpa));
            printf("└─────────────────────────────┘\n");
            press_enter(); return;
        }
    }
    printf("Roll %d not found!\n",roll);
    press_enter();
}

void update_student(void) {
    header("UPDATE STUDENT");
    int roll;
    printf("Enter Roll Number to update: "); scanf("%d",&roll);
    for(int i=0;i<count;i++){
        if(db[i].active && db[i].roll==roll){
            printf("Found: %s\n",db[i].name);
            printf("New Name (Enter to skip): "); getchar();
            char tmp[50]; fgets(tmp,sizeof(tmp),stdin);
            tmp[strcspn(tmp,"\n")]=0;
            if(strlen(tmp)>0) strncpy(db[i].name,tmp,49);
            printf("New GPA (-1 to skip): "); float g; scanf("%f",&g);
            if(g>=0&&g<=10) db[i].gpa=g;
            printf("New Semester (-1 to skip): "); int s; scanf("%d",&s);
            if(s>=1&&s<=8) db[i].semester=s;
            save_to_file();
            printf("✓ Updated successfully!\n");
            press_enter(); return;
        }
    }
    printf("Roll %d not found!\n",roll);
    press_enter();
}

void delete_student(void) {
    header("DELETE STUDENT");
    int roll;
    printf("Enter Roll Number to delete: "); scanf("%d",&roll);
    for(int i=0;i<count;i++){
        if(db[i].active && db[i].roll==roll){
            printf("Delete '%s' (Roll %d)? (y/n): ",db[i].name,roll);
            char c; scanf(" %c",&c);
            if(c=='y'||c=='Y'){
                db[i].active=0;
                save_to_file();
                printf("✓ Deleted!\n");
            } else { printf("Cancelled.\n"); }
            press_enter(); return;
        }
    }
    printf("Roll %d not found!\n",roll);
    press_enter();
}

void sort_and_view(void) {
    header("SORT STUDENTS");
    printf("Sort by:\n  1. GPA (Descending)\n  2. Name (A-Z)\n  3. Roll Number\nChoice: ");
    int ch; scanf("%d",&ch);

    /* Build active-only temp array */
    Student tmp[MAX_STUDENTS]; int n=0;
    for(int i=0;i<count;i++) if(db[i].active) tmp[n++]=db[i];

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            int sw=0;
            if(ch==1) sw=(tmp[j].gpa<tmp[j+1].gpa);
            else if(ch==2) sw=(strcmp(tmp[j].name,tmp[j+1].name)>0);
            else sw=(tmp[j].roll>tmp[j+1].roll);
            if(sw){Student t=tmp[j];tmp[j]=tmp[j+1];tmp[j+1]=t;}
        }

    printf("\n%-6s %-25s %-10s %-5s %-6s\n","Roll","Name","Branch","Sem","GPA");
    printf("%-6s %-25s %-10s %-5s %-6s\n","────","─────────────────────────","──────────","───","─────");
    for(int i=0;i<n;i++)
        printf("%-6d %-25s %-10s %-5d %-6.2f\n",
               tmp[i].roll,tmp[i].name,tmp[i].branch,tmp[i].semester,tmp[i].gpa);
    press_enter();
}

void statistics(void) {
    header("STATISTICS");
    int n=active_count();
    if(n==0){printf("No records.\n");press_enter();return;}

    float sum=0,max_gpa=0,min_gpa=10;
    int grade_cnt[6]={0};  /* O A B C D F */
    for(int i=0;i<count;i++){
        if(!db[i].active) continue;
        sum+=db[i].gpa;
        if(db[i].gpa>max_gpa) max_gpa=db[i].gpa;
        if(db[i].gpa<min_gpa) min_gpa=db[i].gpa;
        char g=grade_from_gpa(db[i].gpa);
        if(g=='O') grade_cnt[0]++;
        else if(g=='A') grade_cnt[1]++;
        else if(g=='B') grade_cnt[2]++;
        else if(g=='C') grade_cnt[3]++;
        else if(g=='D') grade_cnt[4]++;
        else grade_cnt[5]++;
    }
    printf("Total Students : %d\n",n);
    printf("Average GPA    : %.2f\n",sum/n);
    printf("Highest GPA    : %.2f\n",max_gpa);
    printf("Lowest GPA     : %.2f\n\n",min_gpa);
    printf("Grade Distribution:\n");
    const char *gl[]={"O (≥9.0)","A (≥8.0)","B (≥7.0)","C (≥6.0)","D (≥5.0)","F (<5.0)"};
    for(int i=0;i<6;i++){
        printf("  %-12s : %3d ",gl[i],grade_cnt[i]);
        for(int j=0;j<grade_cnt[i];j++) printf("█");
        printf("\n");
    }
    press_enter();
}

/* ── Main Menu ────────────────────────────────────────────────────────── */
int main(void) {
    load_from_file();
    int choice;

    while(1){
        clear_screen();
        printf("\n╔══════════════════════════════════════════════╗\n");
        printf("║        STUDENT MANAGEMENT SYSTEM             ║\n");
        printf("║           C Programming Project              ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║  Active Records: %-27d║\n", active_count());
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║  1. Add Student                              ║\n");
        printf("║  2. View All Students                        ║\n");
        printf("║  3. Search Student (by Roll)                 ║\n");
        printf("║  4. Update Student                           ║\n");
        printf("║  5. Delete Student                           ║\n");
        printf("║  6. Sort & View                              ║\n");
        printf("║  7. Statistics                               ║\n");
        printf("║  0. Exit                                     ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf("Choice: "); scanf("%d",&choice);

        switch(choice){
            case 1: add_student();    break;
            case 2: view_all();       break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: sort_and_view();  break;
            case 7: statistics();     break;
            case 0: printf("\nGoodbye!\n\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
