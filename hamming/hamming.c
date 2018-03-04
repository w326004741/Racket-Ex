#include <stdio.h>

// 无符号整形，unsigned int + 变量名，声明一个无符号变量。
// 无符号整型和有符号整型的区别就是无符号类型可以存放的正数范围比有符号整型中的范围大一倍，因为有符号类型将最高位储存符号，而无符号类型全都储存数字。
// https://zhidao.baidu.com/question/62424363.html
unsigned int hamming(unsigned int x) {
    unsigned int wt = 0;  
    // sizeof():用于获取类型和对象的内存占用大小，单位字节。
    // 比如在32位系统中的指针变量是4个字节的，在64位系统中的指针变量就是8个字节
    // https://www.jianshu.com/p/37d59c85bb3c
    // x >> 1 : 0000 1111 >> 3 => 000 00001(右移运算， 0000 1`111`向右移3个数(`111`)，然后用0补齐, `000` 0001)
    // 实现过程是把该变量先变成2进制数，然后进行移位，在用0补齐。
    for(int i = 0; i < (sizeof(x) * 8); i++)
        wt += ((x >> i) & 1);
        // (x >> i) & 1:https://stackoverflow.com/questions/38922606/what-is-x-1-and-x-1

    return wt;
}
// https://www.jianshu.com/p/2d3c94ca3874
// argc是命令行的总参数的个数
int main(int argc, char *argv[]) {  
    unsigned int sum = 0;
    unsigned int wt;

    // (Hexadecimal十六进制)0xf = 15(Decimal十进制)  0xf 一个f代表15(十进制)，0xff两个就是255(15x15，15的平方)
    for(int i = 0; i <= 0xf; i++) {
        wt = hamming(i);
        // wt = ___builtin_popcount(i);
        //sum += wt;
        printf("Hamming weight of %2u: %2u\n", i, wt);
    }
    //printf("Sum is: %u\n", sum);

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