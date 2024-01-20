// To provide the numberic to the given roman number

#include<stdio.h>
int main() {
    char inp[10], c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}, cur;
    int v[] = {1, 5, 10, 50, 100, 500, 1000}, len, i, index, prev_index, j, v_flag, sum = 0;
    printf("Enter the roman number: ");
    gets(inp);
    for(i = 0; inp[i] != '\0'; i++) {
        cur = inp[i];
        v_flag = 0;
        for(j = 0; j < 7; j++) {
            if(cur == c[j]) {
                v_flag = 1;
                if(i != 0) prev_index = index;
                index = j;
                break;
            }
        }
        if(v_flag != 1) {
            printf("Invalid Input");
            break;
        }
        else {
            if(i != 0) {
                if(v[index] > v[prev_index]) sum += v[index] - (2 * v[prev_index]);
                else sum += v[index];
            }
            else sum += v[index];
        }
    }
    printf("Numberic = %d", sum);
    return 0;
}