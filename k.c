#include <stdlib.h>
#include "k.h"
#include "hof.h"
#include <stdio.h>

void print_field(struct game *game) {
    for(int i = 0; i < SIZE; i++) {
        if(i == 0) {
            for(int j = 0; j < SIZE; j++) {
                if(j == 0) {
                    printf("  -");
                } else {
                    printf("   -");
                }
            }
            printf("\n");
        }
 
        for(int j = 0; j < SIZE; j++) {
            printf("| %c ", game->board[i][j]);
        }
        printf("|\n");
 
        for(int j = 0; j < SIZE; j++) {
            if(j == 0) {
                printf("  -");
            } else {
                printf("   -");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", game->score);
}


 
void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');
 
    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}
 
bool is_game_won(const struct game game) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(game.board[i][j] == 'K') {
                return true;
            }
        }
    }
 
    return false;
}
 
bool is_move_possible(const struct game game) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(game.board[i][j] == ' ') {
                return true;
            }
            if(j != 3 && i != 3 && (game.board[i][j] == game.board[i + 1][j] || game.board[i][j] == game.board[i][j + 1])) {
                return true;                    
            } else if(j == 3 && i != 3 && (game.board[i][j] == game.board[i + 1][j])) {
                return true;
            } else if(j != 3 && i == 3 && (game.board[i][j] == game.board[i][j + 1])) {
                return true;
            }
        }
    }
 
    return false;
}
 
bool update(struct game *game, int dy, int dx) {
    bool canRotate = NULL;

    if((dy == dx) || (dy == (dx * -1))) {
        return false;
    }
   
    if(dx == 1) {   // doneeeeeee!!!
        int wereAdd[4] = {0, 0, 0, 0};
        for(int i = 0; i < SIZE; i++) { // can rotate?
            for(int j = SIZE - 1; j > 0; j--) {
                while(game->board[i][j] != ' ' && j != 0) {
                    if(game->board[i][j] == game->board[i][j - 1] && game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    j--;
                }
                
                if(j == 0) {
                    continue;
                }

                while(j >= 0) {
                    if(game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    j--;
                }
            }
        }

        for(int i = 0; i < SIZE; i++) { // right
            for(int j = SIZE - 1; j >= 0; j--) {
                int blabla = j;
                while(game->board[i][blabla] == ' ') {
                    if(blabla == 0) {
                        break;
                    }
                    blabla--;
                }
                if(game->board[i][blabla] == ' ') {
                    continue;
                }
                char temp = game->board[i][blabla];
                if(blabla == SIZE - 1) {
                    continue;
                }
                game->board[i][blabla] = ' ';
                while(game->board[i][blabla] == ' ') {
                    blabla++;
                    if(blabla == SIZE - 1) {
                        break;
                    }
                }
                if(game->board[i][blabla] == temp) {
                    if(wereAdd[i] == 1) {
                        game->board[i][blabla - 1] = temp;
                        wereAdd[i] = 0;
                    } else {
                        game->board[i][blabla] = temp + 1;
                        int localscore = 1;
                        int count = 0;
                        while(count <= temp - 64) {
                            localscore *= 2;
                            count++;
                        }
                        game->score += localscore;
                        wereAdd[i] = 1;
                    }
                } else if(game->board[i][blabla] == ' ') {
                    game->board[i][blabla] = temp;
                } else {
                    game->board[i][blabla - 1] = temp;
                    wereAdd[i] = 0;
                }
            }
        }
    } else if(dx == -1) {   // doneeeee!!!!
        int wereAdd[4] = {0, 0, 0, 0};
        for(int i = 0; i < SIZE; i++) { // can rotate?
            for(int j = 0; j < SIZE; j++) {
                while(game->board[i][j] != ' ' && j != SIZE - 1) {
                    if(game->board[i][j] == game->board[i][j + 1] && game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    j++;
                }
                if(j == SIZE - 1) {
                    continue;
                }
                while(j < SIZE) {
                    if(game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    j++;
                }
            }
        }

        for(int i = 0; i < SIZE; i++) { // left
            for(int j = 0; j < SIZE; j++) {
                int blabla = j;
                while(game->board[i][blabla] == ' ') {
                    if(blabla == SIZE - 1) {
                        break;
                    }
                    blabla++;
                }
                if(game->board[i][blabla] == ' ') {
                    continue;
                }
                char temp = game->board[i][blabla];
                if(blabla == 0) {
                    continue;
                }
                game->board[i][blabla] = ' ';
                while(game->board[i][blabla] == ' ') {
                    blabla--;
                    if(blabla == 0) {
                        break;
                    }
                }
                if(game->board[i][blabla] == temp) {
                    if(wereAdd[i] == 1) {
                        game->board[i][blabla + 1] = temp;
                        wereAdd[i] = 0;
                    } else {
                        game->board[i][blabla] = temp + 1;
                        int localscore = 1;
                        int count = 0;
                        while(count <= temp - 64) {
                            localscore *= 2;
                            count++;
                        }
                        game->score += localscore;
                        wereAdd[i] = 1;
                    }
                } else if(game->board[i][blabla] == ' ') {
                    game->board[i][blabla] = temp;
                } else {
                    game->board[i][blabla + 1] = temp;
                    wereAdd[i] = 0;
                }
            }
        }
    } else if(dy == - 1) {  // doneeee!!!!
        int wereAdd[4] = {0, 0, 0, 0};
        for(int j = 0; j < SIZE; j++) { // can rotate?
            for(int i = 0; i < SIZE; i++) {
                while(game->board[i][j] != ' ' && i != SIZE - 1) {
                    if(game->board[i][j] == game->board[i + 1][j] && game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    i++;
                }
                if(i == SIZE - 1) {
                    continue;
                }
                while(i < SIZE) {
                    if(game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    i++;
                }
            }
        }
    
        for(int j = 0; j < SIZE; j++) { // up
            for(int i = 0; i < SIZE; i++) {
                int blabla = i;
                while(game->board[blabla][j] == ' ') {
                    if(blabla == SIZE - 1) {
                        break;
                    }
                    blabla++;
                }
                if(game->board[blabla][j] == ' ') {
                    continue;
                }
                char temp = game->board[blabla][j];
                if(blabla == 0) {
                    continue;
                }
                game->board[blabla][j] = ' ';
                while(game->board[blabla][j] == ' ') {
                    blabla--;
                    if(blabla == 0) {
                        break;
                    }
                }
                if(game->board[blabla][j] == temp) {
                    if(wereAdd[j] == 1) {
                        game->board[blabla + 1][j] = temp;
                        wereAdd[j] = 0;
                    } else {
                        game->board[blabla][j] = temp + 1;
                        int localscore = 1;
                        int count = 0;
                        while(count <= temp - 64) {
                            localscore *= 2;
                            count++;
                        }
                        game->score += localscore;
                        wereAdd[j] = 1;
                    }
                } else if(game->board[blabla][j] == ' ') {
                    game->board[blabla][j] = temp;
                } else {
                    game->board[blabla + 1][j] = temp;
                    wereAdd[j] = 0;
                }
            }
        }
    } else if(dy == 1) {
        int wereAdd[4] = {0, 0, 0, 0};
        for(int j = 0; j < SIZE; j++) { // can rotate?
            for(int i = SIZE - 1; i >= 0; i--) {
                while(game->board[i][j] != ' ' && i != 0) {
                    if(game->board[i][j] == game->board[i - 1][j] && game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    i--;
                }
                if(i == 0) {
                    continue;
                }
                while(i >= 0) {
                    if(game->board[i][j] != ' ') {
                        canRotate = true;
                    }
                    i--;
                }
            }
        }

        for(int j = 0; j < SIZE; j++) { // down
            for(int i = SIZE - 1; i >= 0; i--) {
                int blabla = i;
                while(game->board[blabla][j] == ' ') {
                    if(blabla == 0) {
                        break;
                    }
                    blabla--;
                }
                if(game->board[blabla][j] == ' ') {
                    continue;
                }
                char temp = game->board[blabla][j];
                if(blabla == SIZE - 1) {
                    continue;
                }
                game->board[blabla][j] = ' ';
                while(game->board[blabla][j] == ' ') {
                    blabla++;
                    if(blabla == SIZE - 1) {
                        break;
                    }
                }
                if(game->board[blabla][j] == temp) {
                    if(wereAdd[j] == 1) {
                        game->board[blabla - 1][j] = temp;
                        wereAdd[j] = 0;
                    } else {
                        game->board[blabla][j] = temp + 1;
                        int localscore = 1;
                        int count = 0;
                        while(count <= temp - 64) {
                            localscore *= 2;
                            count++;
                        }
                        game->score += localscore;
                        wereAdd[j] = 1;
                    }
                } else if(game->board[blabla][j] == ' ') {
                    game->board[blabla][j] = temp;
                } else {
                    game->board[blabla - 1][j] = temp;
                    wereAdd[j] = 0;
                }
            }
        }
    }

    if(canRotate != true) {
        return false;
    }
    
    return true;
}