#include "hof.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int load(struct player list[]) {
    FILE *file = fopen(HOF_FILE, "r");

    if(file == NULL) {
        file = fopen(HOF_FILE, "w");
        return -1;
    }

    int hodnota = 0;
    char buffer[1024];

    while(fgets(buffer, 1024, file) != NULL) {
        int i = 0;
        if(buffer[i] == '\n') {
            continue;
        }
        while(buffer[i] != DELIMITER) {
            list[hodnota].name[i] = buffer[i];
            i++;
        }
        i = 0;
        while(buffer[i] != DELIMITER) {
            buffer[i] = '\0';
            i++;
        }
        buffer[i] = '\0';
        i++;

        int countOfTens = 0;
        int blabla = i;
        while(buffer[blabla] != '\n' && buffer[blabla] != '\0') {
            countOfTens++;
            blabla++;
        }

        int scr = 0;
        while(true) {
            if(countOfTens == 0) {
                break;
            }
            int temp = (int)buffer[i] - 48;
            int blabla = countOfTens;
            while(blabla != 1) {
                temp *= 10;
                blabla--;
            }
            countOfTens--;
            scr += temp;
            i++;
        }
        list[hodnota].score = scr;

        if(hodnota < 10) {
            hodnota++;
        } 
    }

    fclose(file);

    return hodnota;
}

bool add_player(struct player list[], int* size, const struct player player) {
    int toRemember;
    bool myVernem = NULL;
    printf("\n%s %d\n", player.name, player.score);

    for(int i = 0; i < (*size) - 1; i++) {
        for(int j = 0; j < (*size) - 1; j++) {
            if(list[j].score < list[j + 1].score) {
                int tmpScore = list[j + 1].score;
                char tmpName[30];
                for(int k = 0; k < strlen(list[j + 1].name); k++) {
                    tmpName[k] = list[j + 1].name[k];
                }
                list[j + 1] = list[j];
                for(int k = 0; k < strlen(tmpName); k++) {
                    list[j].name[k] = tmpName[k];
                }
                list[j].score = tmpScore;
            }
        }
    }

    int i = 0;
    while(true) {
        if(list[i].score <= player.score || i == 10) {
            toRemember = i;
            break;
        }
        i++;
    }

    if((*size) != 10) {
        for(int i = (*size); i > toRemember; i--) {
            list[i] = list[i - 1];
        }
        list[toRemember] = player;
    } else {
    
        for(int i = (*size) - 1; i > toRemember; i--) {
            list[i] = list[i - 1];
        }
        list[toRemember] = player;
    }





    // for(int j = 0; j < *size; j++) {
    //     for(int i = j; i < *size; i++) {
    //         if(list[i].score < list[i + 1].score) {
    //             int tempScore = list[i + 1].score;
    //             char tempName[50];
    //             strcpy(tempName, list[i + 1].name);
    //             list[i + 1] = list[i];
    //             strcpy(list[i].name, tempName);
    //             list[i].score = tempScore;
    //         }
    //     }
    // }
    
    // int j = 0;
    // while(true) {
    //     if(list[j].score <= player.score || j == 10) {
    //         toRemember = j;
    //         break;
    //     }
    //     j++;
        
    // }

    // if(toRemember == 0) {
    //     for(int j = (*size); j > toRemember; j--) {
    //         list[j] = list[j - 1];
    //     }
    //     list[toRemember] = player;
    // } else if((*size) == toRemember && toRemember != 9) {
    //     list[toRemember] = player;
    // } else if(toRemember == 9) {
    //     if(list[toRemember].score <= player.score) {
    //         list[toRemember] = player;
    //     }
    // } else if (toRemember < 10 && (*size) < 10) {
    //     for(int j = (*size); j > toRemember; j--) {
    //         list[j] = list[j - 1];
    //     }
    //     list[toRemember] = player;
    // }

    if(*size != 10) {
        (*size)++;
        myVernem = true;
    }

    if(myVernem) {
        return true;
    }

    return false;
}

bool save(const struct player list[], const int size) {
    FILE *file = fopen(HOF_FILE, "w");
    
    if(file == NULL) {
        return false;
    }
    // printf("size: %d\n", size);

    for(int i = 0; i < size; i++) {
        // fprintf(file, "%s%c%d\n", list[i].name, DELIMITER, list[i].score);
        printf("\n%s %d\n", list[i].name, list[i].score);
        fprintf(file, "%s%c%i\n", list[i].name, DELIMITER, list[i].score);
    }
    
    fclose(file);

    return true;
}
