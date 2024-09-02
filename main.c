#include <string.h>
#include <stdio.h>
#include <string.h>
#include "k.h"
#include "hof.h"
#include <stdlib.h>
 
int main() {
    // struct game game = {
    //     .board = {
    //         {'A', 'B', 'C', 'D'},
    //         {'E', 'F', 'G', 'H'},
    //         {'I', 'J', 'K', 'A'},
    //         {'B', 'C', 'D', 'E'}
    //     },
    //     .score = 0
    // };
 
    // printf("is won: %d\n", is_game_won(game));
    // // stdout: 1
 
 
    // struct game game = {
    //     .board = {
    //         {'A', 'B', 'C', 'D'},
    //         {'E', 'F', 'G', 'H'},
    //         {'I', 'J', 'K', 'A'},
    //         {'B', 'C', 'D', 'E'}
    //     },
    //     .score = 0
    // };
 
    // printf("is move possible: %d\n", is_move_possible(game));
    // // stdout: 1
 
 
    // struct game game = {
    //     .board = {
    //         {'A', 'A', 'A', 'A'},
    //         {'B', 'B', 'B', 'B'},
    //         {'C', 'C', 'C', 'C'},
    //         {'D', 'D', 'D', 'D'}
    //     },
    //     .score = 0
    // };
 
    // bool result = update(&game, -1, 0);
    // if(result) {
    //     printf("true\n");
    // } else {
    //     printf("no\n");
    // }
 
    // for(int i = 0; i < SIZE; i++) {
    //     if(i == 0) {
    //         for(int j = 0; j < SIZE; j++) {
    //             if(j == 0) {
    //                 printf("  -");
    //             } else {
    //                 printf("   -");
    //             }
    //         }
    //         printf("\n");
    //     }
 
    //     for(int j = 0; j < SIZE; j++) {
    //         printf("| %c ", game.board[i][j]);
    //     }
    //     printf("|\n");
 
    //     for(int j = 0; j < SIZE; j++) {
    //         if(j == 0) {
    //             printf("  -");
    //         } else {
    //             printf("   -");
    //         }
    //     }
    //     printf("\n");
    // }
 
    // printf("Score: %d\n", game.score);


    // struct player list[10];
    // int size = load(list);
    // printf("Size: %d\n", size);

        // commed
    // for(int i = 0; i < 10; i++) {
    //     if((int)list[i].name[0] > 1) {
    //         printf("%s %d\n", list[i].name, list[i].score);
    //     }
    // }

    // printf("Sorted:)))))\n");

    // int i = 0;
    // while(i < 10) {
        
    //     for(int i = 0; i < size; i++) {
    //         printf("%d -- %s %d\n", i, list[i].name, list[i].score);
    //     }
    //     printf("name: ");
    //     char buffer[30];
    //     int scr;
    //     fgets(buffer, 30, stdin);
    //     buffer[strlen(buffer)] = '\0';
    //     buffer[strlen(buffer) - 1] = '\0';
    //     printf("score: ");
    //     scanf("%d", &scr);
    //     int c;
    //     while((c = getchar()) != '\n' && c != EOF) {
    //         c = getchar();
    //     }
    //     struct player player = {
    //         .score = scr,
    //     };
    //     for(int i = 0; i < strlen(buffer); i++) {
    //         player.name[i] = buffer[i];
    //     }
    //     memset(buffer, 0, 30);
    //     bool result2 = add_player(list, &size, player);
    //     if(result2) {
    //         printf("true\n");
    //     } else {
    //         printf("no\n");
    //     }

        //commed
    //     // for(int i = 0; i < size; i++) {
    //     //     if((int)list[i].name[0] > 1) {
    //     //         printf("%s %d\n", list[i].name, list[i].score);
    //     //     }
    //     // }

    //     bool result3 = save(list, size);
    //     if(result3) {
    //         printf("\nураааа\n");
    //     } else {
    //         printf("\nnooooo\n");
    //     }
    //     i++;

    // }

    struct player list[10];
    int size = load(list);
    for(int i = 0; i < 13; i++) {
        char namePlayer[30];
        printf("name: ");
        fgets(namePlayer, 30, stdin);
        // int c;
        // while((c = getchar()) != '\n' && c != EOF);
        
        namePlayer[strlen(namePlayer)] = '\0';
        int scr;
        printf("Enter score: ");
        scanf("%d", &scr);
        struct player player = {
            .score = scr,
        };
        for(int k = 0; k < strlen(namePlayer); k++) {
            player.name[k] = namePlayer[k];
        }
        add_player(list, &size, player);
        save(list, size);
        
    }

    while(true) {
        printf("Hola, fren, welcome to 2048\nEnter ur name: ");
        char namePlayer[30];
        fgets(namePlayer, 30, stdin);
        namePlayer[strlen(namePlayer)] = '\0';
        namePlayer[strlen(namePlayer) - 1] = '\0';
        printf("Whats doing, %s\n\n", namePlayer);

        struct player list[10];
        int size = load(list);
        // struct player player = {
        //             .score = 3210,
        //         };
        
        // char name[30] = "salie";
        // for(int i = 0; i < 30; i++) {
            // player.name[i] = name[i];
        // }
        // add_player(list, &size, player);
        // save(list, size);
        printf("Do you want to see HOF?(Y/N): ");
        char blabla = getchar();
        
        if(size != -1) {
            if(blabla == 'Y') {
                for(int i = 0; i < size; i++) {
                    printf("%s %d\n", list[i].name, list[i].score);
                }
            }
            printf("\n");
        } else if(blabla == 'N') {
            printf("HOF doenst exist, and has been created\n\n");
        }
        
        struct game game = {
            .board = {
                {'A', ' ', ' ', ' '},
                {'B', ' ', ' ', 'A'},
                {'A', ' ', ' ', ' '},
                {'A', ' ', ' ', ' '}
            },
        };
        printf("This is ur playing field:\n");
        // add_random_tile(&game);
        add_random_tile(&game);
        print_field(&game);

        printf("And now begin to play, have fun(\n");

        struct player player = {};

        int flagToSave = 0;
        while(true) {
            if(is_game_won(game)) {
                printf("Awesome, check the HOF, if u`re not lame, u`ll being here\nBye ^__^\n");
                int scr = game.score;
                struct player player = {
                    .score = scr,
                };
                for(int i = 0; i < strlen(namePlayer); i++) {
                    player.name[i] = namePlayer[i];
                }
                flagToSave = 1;
                // save(list, size);
                // to score
                // exit(1);
                break;
            }

            if(is_move_possible(game)) {
                printf("\nEnter a coords DX, for what would you to move an els (1 - right, -1 left, 0 - do not move for DX): ");
                int DX;
                scanf("%i", &DX);
                printf("\nGood, enter DY, same (1 - down, -1 - up): ");
                int DY;
                scanf("%i", &DY);
                while(!update(&game, DY, DX)) {
                    printf("\n\nEnter another coords, dx: ");
                    scanf("%i", &DX);
                    printf("\nDY: ");
                    scanf("%i", &DY);
                }

                if(!is_game_won(game) && is_move_possible(game)) {
                    add_random_tile(&game);
                }
                print_field(&game);
            } else {
                printf("Brooo, you lose ;D\nUr result has been written to HOF if you beat a result^__^\n");
                // to score
                // exit(1);
                flagToSave = 1;
                break;
            }
            // break;
        }

        if(flagToSave == 1) {
            add_player(list, &size, player);
            save(list, size);
        }

        break;
    }

    return 0;
}
