# Project Report — Tic Tac Toe with Minimax AI

> **Author: Pavan Shetty H S**

---

## Overview

This project was the most fun to build. The two-player mode is straightforward — the interesting part is the AI using the Minimax algorithm. Once I understood how Minimax works, implementing it felt elegant.

The AI cannot be beaten. It either wins or draws — never loses.

---

## How Minimax Works

Minimax is a recursive decision-making algorithm for two-player, zero-sum games. One player tries to maximise the score; the other tries to minimise it.

```
At each game state:
  If it is the AI's turn (maximiser):
    Try every legal move
    Recursively evaluate the resulting state
    Choose the move with the HIGHEST score

  If it is the human's turn (minimiser):
    Try every legal move
    Recursively evaluate the resulting state
    Choose the move with the LOWEST score

Terminal states:
  AI wins  → score = +10
  Human wins → score = -10
  Draw     → score = 0
```

For a 3×3 board, the game tree has at most 9! = 362,880 leaf nodes — trivially small for a computer.

---

## Implementation Notes

```c
int minimax(int is_maximiser) {
    char winner = check_winner();
    if (winner == 'O') return  10;   /* AI wins */
    if (winner == 'X') return -10;   /* human wins */
    if (winner == 'D') return   0;   /* draw */

    int best = is_maximiser ? -1000 : 1000;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!is_available(i, j)) continue;
            board[i][j] = is_maximiser ? 'O' : 'X';
            int score = minimax(!is_maximiser);
            board[i][j] = original_value;   /* undo move */
            if (is_maximiser) best = max(best, score);
            else              best = min(best, score);
        }
    }
    return best;
}
```

The AI calls `minimax` for every empty cell, picks the move with the highest score.

---

## Concepts Used

| Concept | Where |
|---------|-------|
| 2D char array | Board representation |
| Recursion | Minimax algorithm |
| Backtracking | Undo moves after evaluation |
| Game state check | Winner detection in all directions |
| Function decomposition | `check_winner`, `ai_move`, `human_move` |

---

## Complexity

- Minimax time: O(b^d) where b = branching factor (~9), d = depth (~9)
- For 3×3: at most 9! = 362,880 states — evaluated instantly
- With alpha-beta pruning (not implemented here), could skip ~half the nodes

---

*— Pavan Shetty H S*
