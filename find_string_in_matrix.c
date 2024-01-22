#include<stdio.h>
#include<string.h>
int main() {
    char str[100], c, mat[10][10];
    int n, m, i, j, k = 0, klen, l, found = 0, flag = 0, start[2], end[2];
    printf("Enter a string: ");
    gets(str);
    char key[30];
    printf("Enter the column size of the matrix: ");
    scanf("%d", &m);
    c = str[k++];
    n = strlen(str) / m;
    if(strlen(str) % m != 0) n++;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(c != '\0') {
                mat[i][j] = c;
                c = str[k++];
            }
            else mat[i][j] = ' ';
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) printf("%c ", mat[i][j]);
        printf("\n");
    }
    printf("Enter the key to search: ");
    scanf("%s", key);
    klen = strlen(key);
    if((klen > n) && (klen > m)) printf("\nThe key doesn't found in the matrix");
    else {
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(mat[i][j] == key[0]) {
                    // horizontal left to right
                    if((m - j) >= klen) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i][j+l] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = start[0];
                            end[1] = j + klen - 1;
                        }
                    }
                    if(found) break;
                    // horizontal right to left
                    if(j >= klen - 1) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i][j - l] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = start[0];
                            end[1] = j - klen + 1;
                        }
                    }
                    if(found) break;
                    // vertical top to bottom
                    if((n - i) >= klen) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i + l][j] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = i + klen - 1;
                            end[1] = start[1];
                        }
                    }
                    if(found) break;
                    // vertical bottom to top
                    if(i >= klen - 1) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i - l][j] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = i - klen + 1;
                            end[1] = start[1];
                        }
                    }
                    if(found) break;
                    // Diagonal top-left to bottom-right
                    if(((i + klen - 1) <= n) && ((j + klen - 1) <= m)) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i + l][j + l] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = i + klen - 1;
                            end[1] = j + klen - 1;
                        }
                    }
                    if(found) break;
                    // Diagonal bottom-left to top-right
                    if(((i - klen + 1) >= 0) && ((j + klen - 1) <= m)) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i - l][j + l] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = i - klen + 1;
                            end[1] = j + klen - 1;
                        }
                    }
                    if(found) break;
                    // Diagonal top-right to bottom-left
                    if(((i + klen - 1) <= n) && ((j - klen + 1) >= 0)) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i + l][j - l] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = i + klen - 1;
                            end[1] = j - klen + 1;
                        }
                    }
                }
                if(found) break;
                // Diagonal bottom-right to top-left
                    if(((i - klen + 1) >= 0) && ((j + klen - 1) >= 0)) {
                        flag = 1;
                        for(l = 0; l < klen; l++) {
                            if(mat[i - l][j - l] != key[l]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1) {
                            found = 1;
                            start[0] = i;
                            start[1] = j;
                            end[0] = i - klen + 1;
                            end[1] = j - klen + 1;
                        }
                    }
                    if(found) break;
            }
            if(found) break;
        }
        if(found) printf("\nFound from [%d, %d] to [%d, %d].\n", start[0], start[1], end[0], end[1]);
        else printf("\nThe key doesn't found in the matrix");
    }
    return 0;
}