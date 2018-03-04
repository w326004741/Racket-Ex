#include <stdio.h>


unsigned int hamming(unsigned int x) {
    unsigned int wt = 0;

    for(int i = 0; i < (sizeof(x) * 8); i++)
        wt += ((x >> i) & 1);

    return wt;
}

int main(int argc, char *argv[]) {
    unsigned int sum = 0;
    unsigned int wt;

    // (Hexadecimal十六进制)0xf = 15(Decimal十进制)  0xf 一个f代表15(十进制)，0xff两个就是255(15x15，15的平方)
    for(int i = 0; i <= 0xffffff; i++) {
        wt = hamming(i);
        // wt = ___builtin_popcount(i);
        sum += wt;
        //printf("Hamming weight of %2u: %2u\n", i, wt);
    }
    printf("Sum is: %u\n", sum);

    return 0;
}

// int hamming(int a) {
//     int wt;

//     // sizeof in c : size number of bits whatever what is your language
//     // 查询对象或类型的大小
//     // ref: http://zh.cppreference.com/w/c/language/sizeof
//     for (int i = 0; i < (8 * sizeof(a)) ; i++)
//     {
//         wt += ((a >> i) & 1);
//     }
//     return wt;
// }

// int main(int argc, char *argv[]) {
//     int x = 15;
//     print("The number of bits set in %d is %d.\n", x, hamming(x));

//     return 0;
// }