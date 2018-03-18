#include <stdio.h>
#include <stdint.h>

uint32_t W = 0x02000000;

uint32_t A = 0x6a09e667;
uint32_t B = 0xbb67ae85;
uint32_t C = 0x3c6ef372;
uint32_t D = 0xa54ff53a;
uint32_t E = 0x510e527f;
uint32_t F = 0x9b05688c;
uint32_t G = 0x1f83d9ab;
uint32_t H = 0x5be0cd19;

uint32_t K[64] = {
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

uint32_t majority(uint32_t x, uint32_t y, uint32_t z) {
  return ((x & y) | (x & z) | (y & z));
}

uint32_t cycle(uint32_t x, uint32_t i) {
  return ((x >> i) | (x << (32 - i)));
}

uint32_t choose(uint32_t x, uint32_t y, uint32_t z) {
  return ((x & y) | ((~x) & z));
}

int main(int argc, char *argv[]) {
  
  printf("Initial\n");
  printf("A = %x\n", A);
  printf("B = %x\n", B);
  printf("C = %x\n", C);
  printf("D = %x\n", D);
  printf("E = %x\n", E);
  printf("F = %x\n", F);
  printf("G = %x\n", G);
  printf("H = %x\n", H);

  uint32_t T1 = W + K[0] + H + choose(E, F, G) + (cycle(E, 6) ^ cycle(E, 11) ^ cycle(E, 25));
  uint32_t T2 = majority(A, B, C) + (cycle(A, 2) ^ cycle(A, 13) ^ cycle(A, 22));


  printf("Pass 1\n");
  printf("A = %x\n", T1 + T2);
  printf("B = %x\n", A);
  printf("C = %x\n", B);
  printf("D = %x\n", C);
  printf("E = %x\n", D + T1);
  printf("F = %x\n", E);
  printf("G = %x\n", F);
  printf("H = %x\n", G);

  return 0;
}