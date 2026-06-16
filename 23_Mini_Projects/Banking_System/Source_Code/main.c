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
#include <time.h>

#define MAX_ACCOUNTS  50
#define MAX_TX        100
#define BANK_FILE     "/tmp/bank.dat"

typedef struct {
    char timestamp[20];
    char type[10];    /* DEBIT / CREDIT */
    double amount;
    double balance;
    char description[40];
} Transaction;

typedef struct {
    int       acc_no;
    char      holder[50];
    char      type[15];    /* SAVINGS / CURRENT */
    double    balance;
    int       active;
    Transaction tx[MAX_TX];
    int       tx_count;
} Account;

Account db[MAX_ACCOUNTS];
int     acc_count = 0;
int     next_acc  = 100001;

void get_time(char *buf) {
    time_t t = time(NULL);
    strftime(buf, 20, "%d/%m/%y %H:%M", localtime(&t));
}

void save(void){ FILE*f=fopen(BANK_FILE,"wb");if(!f)return;fwrite(&acc_count,sizeof(int),1,f);fwrite(&next_acc,sizeof(int),1,f);fwrite(db,sizeof(Account),acc_count,f);fclose(f);}
void load(void){ FILE*f=fopen(BANK_FILE,"rb");if(!f)return;fread(&acc_count,sizeof(int),1,f);fread(&next_acc,sizeof(int),1,f);fread(db,sizeof(Account),acc_count,f);fclose(f);}

Account *find_account(int acc_no) {
    for(int i=0;i<acc_count;i++)
        if(db[i].active && db[i].acc_no==acc_no) return &db[i];
    return NULL;
}

void add_transaction(Account *a, const char *type, double amount, const char *desc) {
    if(a->tx_count>=MAX_TX) return;
    Transaction *tx = &a->tx[a->tx_count++];
    get_time(tx->timestamp);
    strncpy(tx->type, type, 9);
    tx->amount  = amount;
    tx->balance = a->balance;
    strncpy(tx->description, desc, 39);
}

void create_account(void) {
    printf("\n=== Create Account ===\n");
    if(acc_count>=MAX_ACCOUNTS){printf("Bank full!\n");return;}
    Account a={0};
    a.acc_no  = next_acc++;
    a.active  = 1;
    a.tx_count= 0;
    printf("Holder Name : "); scanf(" %49[^\n]",a.holder);
    printf("Type (1=Savings 2=Current): ");
    int t; scanf("%d",&t);
    strcpy(a.type, t==2?"CURRENT":"SAVINGS");
    printf("Initial Deposit: ₹"); scanf("%lf",&a.balance);
    if(a.balance<(t==2?5000:1000)){
        printf("Minimum deposit: ₹%d\n",t==2?5000:1000); return;
    }
    add_transaction(&a,"CREDIT",a.balance,"Account opened");
    db[acc_count++]=a;
    save();
    printf("\n✓ Account created! Account No: %d\n",a.acc_no);
}

void deposit(void) {
    printf("\n=== Deposit ===\n");
    int acc; printf("Account No: "); scanf("%d",&acc);
    Account *a=find_account(acc);
    if(!a){printf("Account not found!\n");return;}
    double amt; printf("Amount: ₹"); scanf("%lf",&amt);
    if(amt<=0){printf("Invalid amount!\n");return;}
    a->balance+=amt;
    add_transaction(a,"CREDIT",amt,"Cash deposit");
    save();
    printf("✓ Deposited ₹%.2f | New Balance: ₹%.2f\n",amt,a->balance);
}

void withdraw(void) {
    printf("\n=== Withdraw ===\n");
    int acc; printf("Account No: "); scanf("%d",&acc);
    Account *a=find_account(acc);
    if(!a){printf("Account not found!\n");return;}
    double amt; printf("Amount: ₹"); scanf("%lf",&amt);
    double min_bal = strcmp(a->type,"SAVINGS")==0 ? 1000 : 5000;
    if(amt<=0||a->balance-amt<min_bal){
        printf("Insufficient funds! (Min balance: ₹%.0f)\n",min_bal);return;
    }
    a->balance-=amt;
    add_transaction(a,"DEBIT",amt,"Cash withdrawal");
    save();
    printf("✓ Withdrawn ₹%.2f | New Balance: ₹%.2f\n",amt,a->balance);
}

void transfer(void) {
    printf("\n=== Fund Transfer ===\n");
    int from,to; double amt;
    printf("From Account: "); scanf("%d",&from);
    printf("To Account  : "); scanf("%d",&to);
    printf("Amount      : ₹"); scanf("%lf",&amt);
    Account *a=find_account(from), *b=find_account(to);
    if(!a||!b){printf("Account not found!\n");return;}
    if(a->balance<amt){printf("Insufficient funds!\n");return;}
    a->balance-=amt; b->balance+=amt;
    char desc[40];
    snprintf(desc,40,"Transfer to %d",to);   add_transaction(a,"DEBIT",amt,desc);
    snprintf(desc,40,"Transfer from %d",from);add_transaction(b,"CREDIT",amt,desc);
    save();
    printf("✓ ₹%.2f transferred from %d to %d\n",amt,from,to);
}

void balance_inquiry(void) {
    printf("\n=== Balance Inquiry ===\n");
    int acc; printf("Account No: "); scanf("%d",&acc);
    Account *a=find_account(acc);
    if(!a){printf("Account not found!\n");return;}
    printf("┌─────────────────────────────────┐\n");
    printf("│ Account No : %-20d│\n",a->acc_no);
    printf("│ Holder     : %-20s│\n",a->holder);
    printf("│ Type       : %-20s│\n",a->type);
    printf("│ Balance    : ₹%-19.2f│\n",a->balance);
    printf("└─────────────────────────────────┘\n");
}

void mini_statement(void) {
    printf("\n=== Mini Statement ===\n");
    int acc; printf("Account No: "); scanf("%d",&acc);
    Account *a=find_account(acc);
    if(!a){printf("Account not found!\n");return;}
    int start = a->tx_count>5 ? a->tx_count-5 : 0;
    printf("Last %d transactions for Account %d:\n",a->tx_count-start,acc);
    printf("%-18s %-7s %-12s %-12s %s\n","Date","Type","Amount","Balance","Description");
    printf("%-18s %-7s %-12s %-12s %s\n","──────────────────","───────","────────────","────────────","──────────────────");
    for(int i=start;i<a->tx_count;i++){
        Transaction *tx=&a->tx[i];
        printf("%-18s %-7s ₹%-11.2f ₹%-11.2f %s\n",
               tx->timestamp,tx->type,tx->amount,tx->balance,tx->description);
    }
}

int main(void) {
    load();
    int ch;
    while(1){
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║         BANKING SYSTEM               ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║ 1. Create Account  2. Deposit        ║\n");
        printf("║ 3. Withdraw        4. Transfer       ║\n");
        printf("║ 5. Balance         6. Statement      ║\n");
        printf("║ 0. Exit                              ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("Choice: "); scanf("%d",&ch);
        switch(ch){
            case 1: create_account();  break;
            case 2: deposit();         break;
            case 3: withdraw();        break;
            case 4: transfer();        break;
            case 5: balance_inquiry(); break;
            case 6: mini_statement();  break;
            case 0: printf("Goodbye!\n"); return 0;
        }
    }
}
