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
#include <math.h>
#include <string.h>

#define PI    3.14159265358979
#define E_VAL 2.71828182845905
#define HIST  10

double history[HIST];
int    hist_count = 0;
double memory = 0.0;

void add_history(double val) {
    if(hist_count < HIST) history[hist_count++] = val;
    else {
        for(int i=0;i<HIST-1;i++) history[i]=history[i+1];
        history[HIST-1] = val;
    }
}

void display_history(void) {
    printf("\n=== Calculation History ===\n");
    if(hist_count==0){printf("No history.\n");return;}
    for(int i=0;i<hist_count;i++) printf("  [%d] = %.10g\n",i+1,history[i]);
}

double deg_to_rad(double d) { return d * PI / 180.0; }

int main(void) {
    printf("╔══════════════════════════════════════════╗\n");
    printf("║        SCIENTIFIC CALCULATOR             ║\n");
    printf("║  Type 'help' for operations              ║\n");
    printf("╚══════════════════════════════════════════╝\n");

    char cmd[20];
    double a, b, result=0;

    while(1){
        printf("\n> ");
        scanf("%19s", cmd);

        if(strcmp(cmd,"exit")==0||strcmp(cmd,"quit")==0) {printf("Bye!\n");break;}
        if(strcmp(cmd,"hist")==0){display_history();continue;}
        if(strcmp(cmd,"pi")==0){printf("π = %.10f\n",PI);add_history(PI);continue;}
        if(strcmp(cmd,"e")==0){printf("e = %.10f\n",E_VAL);add_history(E_VAL);continue;}
        if(strcmp(cmd,"ms")==0){memory=result;printf("Stored: %.10g\n",memory);continue;}
        if(strcmp(cmd,"mr")==0){result=memory;printf("Recalled: %.10g\n",memory);continue;}
        if(strcmp(cmd,"mc")==0){memory=0;printf("Memory cleared\n");continue;}
        if(strcmp(cmd,"help")==0){
            printf("  Basic:  + - * / mod pow\n");
            printf("  Trig:   sin cos tan asin acos atan (degrees)\n");
            printf("  Log:    log log2 log10 exp\n");
            printf("  Other:  sqrt abs ceil floor round\n");
            printf("  Mem:    ms (store) mr (recall) mc (clear)\n");
            printf("  Const:  pi e\n");
            printf("  hist:   history  |  exit: quit\n");
            continue;
        }

        /* Two-operand operations */
        if(strcmp(cmd,"+")==0||strcmp(cmd,"-")==0||strcmp(cmd,"*")==0||
           strcmp(cmd,"/")==0||strcmp(cmd,"mod")==0||strcmp(cmd,"pow")==0){
            printf("a = "); scanf("%lf",&a);
            printf("b = "); scanf("%lf",&b);
            if(strcmp(cmd,"+")==0)  result=a+b;
            else if(strcmp(cmd,"-")==0) result=a-b;
            else if(strcmp(cmd,"*")==0) result=a*b;
            else if(strcmp(cmd,"/")==0){
                if(b==0){printf("Error: Division by zero!\n");continue;}
                result=a/b;
            }
            else if(strcmp(cmd,"mod")==0){
                if((int)b==0){printf("Error: Mod by zero!\n");continue;}
                result=fmod(a,b);
            }
            else result=pow(a,b);
            printf("= %.10g\n",result);
            add_history(result);
            continue;
        }

        /* One-operand operations */
        printf("a = "); scanf("%lf",&a);
        if(strcmp(cmd,"sin")==0)   result=sin(deg_to_rad(a));
        else if(strcmp(cmd,"cos")==0)   result=cos(deg_to_rad(a));
        else if(strcmp(cmd,"tan")==0){
            if(fmod(a,180)==90){printf("Undefined!\n");continue;}
            result=tan(deg_to_rad(a));
        }
        else if(strcmp(cmd,"asin")==0)  result=asin(a)*180/PI;
        else if(strcmp(cmd,"acos")==0)  result=acos(a)*180/PI;
        else if(strcmp(cmd,"atan")==0)  result=atan(a)*180/PI;
        else if(strcmp(cmd,"log")==0){
            if(a<=0){printf("Error: log of non-positive!\n");continue;}
            result=log(a);
        }
        else if(strcmp(cmd,"log2")==0)  result=log2(a);
        else if(strcmp(cmd,"log10")==0) result=log10(a);
        else if(strcmp(cmd,"exp")==0)   result=exp(a);
        else if(strcmp(cmd,"sqrt")==0){
            if(a<0){printf("Error: sqrt of negative!\n");continue;}
            result=sqrt(a);
        }
        else if(strcmp(cmd,"abs")==0)   result=fabs(a);
        else if(strcmp(cmd,"ceil")==0)  result=ceil(a);
        else if(strcmp(cmd,"floor")==0) result=floor(a);
        else if(strcmp(cmd,"round")==0) result=round(a);
        else { printf("Unknown command. Type 'help'.\n"); continue; }

        printf("= %.10g\n",result);
        add_history(result);
    }
    return 0;
}
