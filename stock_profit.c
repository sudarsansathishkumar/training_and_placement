// To get the profit for the share market
// Imagine ChildWorks

#include<stdio.h>
int main() {
    int stock[7] = {2, 5, 6, 15, 1, 8, 0};
    int min=0, max=0, profit, i;
    for(i = 0; i < 7; i++) {
        if((stock[min] > stock[i]) && (i != 6)) {
            min = i;
        }
        if(stock[max] < stock[i]) {
            max = i;
        }
    }
    profit = stock[max] - stock[min];
    printf("Day of buying the stock: %d, with price of $%d\n", min+1, stock[min]);
    printf("Day of selling the stock: %d, with price of $%d\n", max+1, stock[max]);
    printf("Profit: $%d\n", profit);
    return 0;
}
