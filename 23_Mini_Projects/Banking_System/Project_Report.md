# Project Report — Banking System

> **Author: Pavan Shetty H S**

---

## Overview

The banking system was my first project that modelled real-world state transitions — opening accounts, depositing, withdrawing, transferring between accounts. Each operation has validation logic and maintains a transaction history.

---

## Data Model

```c
typedef struct {
    char   timestamp[20];
    char   type[10];        /* "CREDIT" or "DEBIT" */
    double amount;
    double balance;         /* balance AFTER this transaction */
    char   description[40];
} Transaction;

typedef struct {
    int         acc_no;
    char        holder[50];
    char        type[15];   /* "SAVINGS" or "CURRENT" */
    double      balance;
    int         active;
    Transaction tx[100];    /* last 100 transactions */
    int         tx_count;
} Account;
```

---

## Key Design Decisions

**Minimum balance enforcement:** Savings accounts require ₹1,000 minimum; current accounts ₹5,000. Every withdrawal checks this before proceeding.

**Transaction log:** Every deposit, withdrawal, and transfer appends a `Transaction` record. The mini-statement shows the last 5. I store the running balance in each transaction record so I do not need to replay history to show it.

**Binary persistence:** The entire account array is saved with `fwrite` on every modification. Simple but correct for this scale.

---

## What I Learned

- Modelling state transitions explicitly (credit/debit with descriptions)
- Using `time.h` to timestamp transactions
- The importance of validating BEFORE modifying state — if validation fails midway, no changes should have been applied

---

## Complexity

| Operation | Time | Notes |
|-----------|------|-------|
| Find account | O(n) | Linear scan by account number |
| Deposit/Withdraw | O(n) | Find + O(1) update |
| Transfer | O(n) | Two finds + O(1) updates |
| Mini statement | O(1) | Last 5 from fixed array |
| Save | O(n) | Full file rewrite |

---

*— Pavan Shetty H S*
