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
#include <limits.h>

char board[3][3];
int  moves_made = 0;

void init_board(void) {
    char c = '1';
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) board[i][j]=c++;
    moves_made=0;
}

void print_board(void) {
    printf("\n");
    for(int i=0;i<3;i++){
        printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
        if(i<2) printf("───┼───┼───\n");
    }
    printf("\n");
}

char check_winner(void) {
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]) return board[i][0];
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]) return board[0][i];
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]) return board[0][0];
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]) return board[0][2];
    return (moves_made==9)?'D':0; /* Draw or no winner yet */
}

int is_available(int r, int c){ return board[r][c]!='X'&&board[r][c]!='O'; }

/* Minimax algorithm — returns score for the current player */
int minimax(int is_max) {
    char w=check_winner();
    if(w=='O') return  10;
    if(w=='X') return -10;
    if(w=='D') return  0;

    int best = is_max ? -1000 : 1000;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
        if(!is_available(i,j)) continue;
        char orig=board[i][j];
        board[i][j] = is_max?'O':'X';
        moves_made++;
        int score=minimax(!is_max);
        board[i][j]=orig; moves_made--;
        if(is_max) { if(score>best) best=score; }
        else       { if(score<best) best=score; }
    }
    return best;
}

void ai_move(void) {
    int best=-1000, br=-1, bc=-1;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){
        if(!is_available(i,j)) continue;
        char orig=board[i][j];
        board[i][j]='O'; moves_made++;
        int score=minimax(0); /* now human's turn (minimizer) */
        board[i][j]=orig; moves_made--;
        if(score>best){best=score;br=i;bc=j;}
    }
    board[br][bc]='O'; moves_made++;
    printf("AI plays: position %d\n", br*3+bc+1);
}

int human_move(char player) {
    int pos;
    printf("Player %c, enter position (1-9): ",player);
    scanf("%d",&pos);
    if(pos<1||pos>9) return 0;
    int r=(pos-1)/3, c=(pos-1)%3;
    if(!is_available(r,c)){printf("Position taken!\n");return 0;}
    board[r][c]=player; moves_made++;
    return 1;
}

void two_player(void) {
    init_board();
    char players[]={'X','O'};
    int turn=0;
    while(1){
        print_board();
        while(!human_move(players[turn]));
        char w=check_winner();
        if(w){print_board();
            if(w=='D') printf("It's a DRAW!\n");
            else printf("Player %c WINS! 🎉\n",w);
            return;
        }
        turn=1-turn;
    }
}

void vs_ai(void) {
    init_board();
    printf("You are X, AI is O\n");
    while(1){
        print_board();
        while(!human_move('X'));
        char w=check_winner();
        if(w){print_board();
            if(w=='D') printf("DRAW!\n");
            else if(w=='X') printf("You WIN! 🎉\n");
            else printf("AI WINS! 🤖\n");
            return;
        }
        printf("AI thinking...\n");
        ai_move();
        w=check_winner();
        if(w){print_board();
            if(w=='D') printf("DRAW!\n");
            else printf("AI WINS! 🤖\n");
            return;
        }
    }
}

int main(void) {
    printf("╔══════════════════════════╗\n");
    printf("║    TIC TAC TOE  ❌ ⭕    ║\n");
    printf("╚══════════════════════════╝\n");
    int ch;
    while(1){
        printf("\n1. Two Player\n2. vs AI (Minimax)\n0. Exit\nChoice: ");
        scanf("%d",&ch);
        if(ch==1) two_player();
        else if(ch==2) vs_ai();
        else break;
    }
    return 0;
}
/*
Board positions:
 1 | 2 | 3
───┼───┼───
 4 | 5 | 6
───┼───┼───
 7 | 8 | 9
*/
