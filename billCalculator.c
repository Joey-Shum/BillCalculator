//
//  billCalculator.c
//  sideProject
//

#include "billCalculator.h"


#include <math.h>
#include <stdlib.h>
#include <string.h>

void print_money(int amount) {

    if (amount < 0) {
        printf("-");
        amount = abs(amount);
    }

    int part1 = (amount - amount % 100000000) / 100000000;
    int part2 = (amount % 100000000 - amount % 100000) / 100000;
    int part3 = (amount % 100000 - amount % 100) / 100;
    int part4 = amount % 100;

    if ((part1 == 0) && (part2 == 0) && (part3 == 0) && (part4 == 0)) {
        printf("$0.00\n");
    } else if ((part1 == 0) && (part2 == 0) && (part3 == 0)) {
        printf("$0.%02d\n", part4);
    } else if ((part1 == 0) && (part2 == 0)) {
        printf("$%d.%02d\n", part3, part4);
    } else if (part1 == 0) {
        printf("$%d,%03d.%02d\n", part2, part3, part4);
    } else {
        printf("$%d,%03d,%03d.%02d\n", part1, part2, part3, part4);
    }
}


void print_bill(int amount, int tax_rate, int tip_rate) {
    printf("bill:  ");
    print_money(amount);

    int tax = (amount * tax_rate) / 100;
    printf("tax:   ");
    print_money(tax);

    int tip = ((amount + tax) * tip_rate) / 100;
    printf("tip:   ");
    print_money(tip);

    int total = amount + tax + tip;
    printf("total: ");
    print_money(total);

    printf("======\n\n");
}


void main() {
    printf("Type the bill amount that is less than or equal to 999999999: ");
    int myBill;
    scanf("%d", &myBill);
    
    printf("Type the tax rate without the %% symbol: ");
    int myTaxRate;
    scanf("%d", &myTaxRate);
    
    printf("Type the tip rate without the %% symbol: ");
    int myTipRate;
    scanf("%d", &myTipRate);
    
    print_bill(myBill, myTaxRate, myTipRate);
    
    printf("Type Y to make another calculation, or any other character to exit from the program: ");
    char yes[] = "Y";
    char runProgram[200];
    scanf(" %c", &runProgram);
    if (strcmp(runProgram, yes) == 0) {
        main();
    }
}

