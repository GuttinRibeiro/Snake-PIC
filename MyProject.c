#define MENU 0
#define GAME 1
#define INST 2

// Glcd module connections
char GLCD_DataPort at PORTD;

const code char gameover[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,  96,  32,  32,  96,   0,   0, 128, 128, 128, 128,   0,   0, 128, 128, 128, 128, 128, 128, 128,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0, 128, 128, 128, 128,   0, 128,   0,   0,   0, 128,   0,   0, 128, 128,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   7,  12,   8,   9,  15,   0,   0,  14,  10,  10,  15,   0,   0,  15,   0,   0,  15,   0,   0,  15,   0,   0,   7,  10,  10,  11,   0,   0,   0,   0,  15,   8,   8,  15,   0,   0,   3,  12,  12,   3,   0,   7,  10,  10,  11,   0,   0,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 224, 240, 248, 248, 248, 248, 240, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 240, 248, 248, 248, 248, 240, 224, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  15,  31,  31,  31,  31,  15,  15,  31, 191, 220, 232, 224, 240, 240, 248, 248, 248, 248, 248, 252, 252, 252, 252, 248, 248, 248, 248, 248, 240, 240, 224, 232, 220, 191,  31,  15,  15,  31,  31,  31,  31,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 127, 255, 255, 255, 255, 255,  63,  63,  63,  63,  63, 127, 255, 255, 255, 255, 127,  63,  63,  63,  63,  63, 255, 255, 255, 255, 255,  62,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  29, 255, 255, 224, 192, 192, 192, 192, 192, 224, 247, 127, 127, 243, 224, 192, 192, 192, 192, 192, 224, 255, 255,  13,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 240, 248, 248, 248, 248, 240, 240, 248, 252,  62,  29,  11,  11,  15,  31, 255, 255, 127, 255, 248, 248, 252, 120, 255, 127, 255, 255,  31,  15,  11,  11,  29,  62, 252, 248, 240, 240, 248, 248, 248, 248, 240,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   7,  15,  31,  31,  31,  31,  15,   7,   0,   0,   0,   0,   0,   1,   1,   0,   1,   1,   1,   1,   0,   1,   0,   1,   1,   0,   0,   0,   0,   0,   7,  15,  31,  31,  31,  31,  15,   7,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};

const code char snake[1024] = {
255, 255,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  56,  68,  68,  68, 136,   0,   0, 240,  32,  16,  16,  16, 224,   0,   0,  32, 144, 144, 144, 224,   0,   0, 254, 128,  64,  32,  16,   0,   0, 224, 144, 144, 144, 144, 224,   0,   0,   0,   0,   0, 224,  16,  16,  16,  16, 224,   0,   0, 240,  32,  16,  16,  16, 224,   0,   0,   0,   0,   0, 252,  68,  68,  68,  68,  56,   0,   0, 252,   0,   0,   0, 240,   8,   4,   4,   4,   4,   8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   4,   4,   4,   3,   0,   0,   7,   0,   0,   0,   0,   7,   0,   0,   3,   4,   4,   2,   7,   0,   0,   7,   0,   1,   2,   4,   0,   0,   3,   4,   4,   4,   4,   4,   0,   0,   0,   0,   0,   3,   4,   4,   4,   4,   3,   0,   0,   7,   0,   0,   0,   0,   7,   0,   0,   0,   0,   0,   7,   0,   0,   0,   0,   0,   0,   0,   7,   0,   0,   0,   1,   2,   4,   4,   4,   4,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 252,   0,   0, 240,  16,  16, 240,   0, 240,  80,  80, 112,  16,   0, 208,  80,  80, 240,   0,   0, 240,  16,  16,   0,   0,  64,  64,  64,   0,   0,   0, 208,  80,  80, 240,   0,   0, 240,  16,  16, 224,   0,   0, 224,  80,  80,  96,   0,   0, 240,  16,  16,  16, 248,  16,   0,   0, 224,  80,  80,  96,   0,   0,   0,   0,   8, 132, 100,  56,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1, 129,   1,   0,   0,   1,   1,   1,   1,   0,   6,   5,   5,   5,   3,   0,   1,   1,   1,   1,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   0,   0,   7,   1,   1,   0,   0,   0,   0,   1,   1,   1,   0,   0,   1,   0,   0,   0,   1,   1,   0,   0,   0,   1,   1,   1,   0,   0,   0,   0,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  63,   0,   0,  62,   2,   2,  62,   0,  38,  42,  58,   0,   0,   2,  63,  34,   0,   0,  62,   2,   2,   0,  62,  32,  32,  62,   0,   0,  28,  34,  34,  34,   0,  62,  34,  34,  62,   0,   0,  28,  42,  42,  44,   0,  38,  42,  58,   0,   0,   0,   0,   8,   8,   8,   0,   0,   0,  58,  42,  42,  62,   0,   0, 254,  34,  34,  28,   0,   0,  28,  42,  42,  44,   0,   0,  62,   2,   2,   2,  63,  34,   0,   0,  28,  42,  42,  44,   0,   0,   0,  27,  36,  36,  36,  27,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 255, 255, 255
};

const code char instrucoes[1024] = {
255, 255, 255,   7,   7, 135, 135, 135,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7, 135,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7, 135,   7,   7,   7,   7,   7,   7, 135, 135, 135,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7, 135,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7, 135,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7, 255, 255, 255,
255, 255, 255,   0, 129, 192, 160, 152, 135,   0,   0,   0,   0,  16,  16,  16,   0,   0,   0,   0,   0, 124, 130, 130,  68,   0,   0, 254,   0,   0, 254,   4,   2,   2, 252,   4,   2,   2, 252,   0,   0, 100, 146, 146,  82, 252,   0,   0,   0,   0,   0, 255,   0,   0,   0,   0,   0, 119, 136, 136, 136, 119,   0,   0,   0,   0,  16,  16,  16,   0,   0,   0,   0,   0, 255,  68, 130, 130, 124,   0,   0, 100, 146, 146,  82, 252,   0,   0, 254,   0, 130, 108,  16, 108, 130,   0, 124, 130, 130, 130, 124,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 255,   0,   0,   0, 128, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,   0,   0,   0,   0,   0, 131,  64,  64,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,   0,   0,  64,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 255,   0,  24,  22,  17, 127,  16,   0,   0,   0,   0,   8,   8,   8,   0,   0,   0,   0,   0,  62,  73,  73,  73,  46,   0,   0,  38,  73,  73,  73,  50,   0,   0,  62,  65,  65,  34, 255,   0,   0,   0,   0,   0, 255,   0,   0,   0,   0,   0,  63,  68,  66,  66,  60,   0,   0,   0,   0,   8,   8,   8,   0,   0,   0,   0,   0,  62,  65,  65,  66, 127,   0,   0, 127,   0,   0, 127,   2,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 255,   0,   0,   0,   0,   0,  16,   8,   8, 136, 112,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  96, 128,   0, 128,  96,   0, 192,  32,  32,  32, 192,   0,   0, 248,   0,  32, 248,  32,   0,  64,  32,  32,  32, 192,   0,   0, 224,  64,  32,   0,   0,   0,   0,  64,  32,  32,  32, 192,   0,   0, 192,  32,  32,  32, 192,   0,   0,   0,   0,   0, 224,  64,  32,  32, 192,  64,  32,  32, 192,   0,   0, 192,  32,  32,  32, 192,   0,   0, 224,  64,  32,  32, 192,   0,   0, 224,   0,   0,   0, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 255,   0,   0,   0,   0,   0,   8,  12,  10,   9,   8,   0,   0,   0,   0,   1,   1,   1,   0,   0,   0,   0,   0,   3,  12,   3,   0,   0,   7,   8,   8,   8,   7,   0,   0,  15,   0,   0,  15,   8,   0,   6,   9,   9,   5,  15,   0,   0,  15,   0,   0,   0,   0,   0,   0,   6,   9,   9,   5,  15,   0,   0,   7,   8,   8,   8,   7,   0,   0,   0,   0,   0,  15,   0,   0,   0,  15,   0,   0,   0,  15,   0,   0,   7,   9,   9,   9,   5,   0,   0,  15,   0,   0,   0,  15,   0,   0,   7,   8,   8,   8,  15,   0,   0,   8,   0,   0,   8,   0,   0,   8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 255, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 255, 255, 255
};

const code char trofeu[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128, 128, 128, 128, 128, 128, 248, 248,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8, 232, 248, 128, 128, 128, 128, 128, 128, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,  15,  56, 224, 128,   0,   0,   0,   0,  31, 120, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192, 248,  31,   0,   0,   0,   0, 128, 224,  56,  15,   1,   0,   0, 192,   0,   0,   0,   0,   0, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  64,  32,  64,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   3,   6,   4,  12,  24,  24,  19,  55,  60,  48,  96, 192, 128,   0,   0,   0, 128, 192,  96,  48,  60,  54,  19,  16,  24,  12,   4,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   7,  24,  96,  24,   7,   0,   0,  62,  65,  65,  65,  62,   0,   0,  62,  65,  65,  34,   0,   0,  62,  73,  73,  73,  46,   0,   0,   0,   0,   3,  28,  96,  28,   3,   0,  62,  73,  73,  73,  46,   0,   0, 127,   2,   1,   1, 126,   0,   0,  62,  65,  65,  34,   0,   0,  62,  73,  73,  73,  46,   0,   0,  63,  64,  64,  64, 127,   0,   0,  95,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 224, 224, 176, 159, 128, 128, 128, 159, 176, 224, 224, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 240, 144,  16,  31,  31,  16,  16,  22,  20,  20,  20,  20,  20,  22,  20,  16,  25,  31,  16, 144, 240,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};

sbit GLCD_CS1 at RB0_bit;
sbit GLCD_CS2 at RB1_bit;
sbit GLCD_RS  at RB2_bit;
sbit GLCD_RW  at RB3_bit;
sbit GLCD_EN  at RB4_bit;
sbit GLCD_RST at RB5_bit;

sbit GLCD_CS1_Direction at TRISB0_bit;
sbit GLCD_CS2_Direction at TRISB1_bit;
sbit GLCD_RS_Direction  at TRISB2_bit;
sbit GLCD_RW_Direction  at TRISB3_bit;
sbit GLCD_EN_Direction  at TRISB4_bit;
sbit GLCD_RST_Direction at TRISB5_bit;
// End Glcd module connections

// Global
enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

typedef struct musical_note {
  unsigned short int low_value;
  unsigned short int high_value;
} Note;

typedef struct song {
  Note notes_list[20];
  unsigned short int last_note_idx;
} Song;

typedef struct position {
     unsigned short int posx;
     unsigned short int posy;
} Position;

typedef struct snake_char {
  Position list[200];
  unsigned short int tail_idx;
  unsigned short int gameover;
  unsigned short int win;
} Snake;

Song doremifa;
unsigned short int song_idx;

unsigned short int game_control;
// Vari?veis globais que configuram o MSB e o LSB do TMR0
unsigned short int low_value, high_value;

void interrupt_timer() iv 0x0008 ics ICS_AUTO {
    TMR0L = doremifa.notes_list[song_idx].low_value;           // Configura o valor inicial do timer
    TMR0H = doremifa.notes_list[song_idx].high_value;
    if(song_idx == doremifa.last_note_idx) {
      song_idx = 0;
    } else {
      song_idx++;
    }

    late.re1 = ~late.re1;     // Complementa a sa?da do buzzer para gerar a onda quadrada
    TMR0IF_bit = 0;         // Zera a flag de interrup??o do timer 0
    TMR0IE_bit = 1;
}

// Funções para estruturas de dados
void init_snake(Snake *player) {
  unsigned short int i;
  player->tail_idx = 30;

  for (i = 0; i < player->tail_idx+1; i++) {
       player->list[i].posx = 50+i;
       player->list[i].posy = 50;
  }

  player->list[0].posx = 50;
  player->list[0].posy = 50;
  player->gameover = 0;
  player->win = 0;
}

int append_position(Snake *player, Position pos) {
  if(player->tail_idx == 199) {
        player->gameover = 1;
        player->win = 1;
        return 1;
  }

  if(pos.posx > 127 || pos.posy > 63) {
        return 1;
  }

  player->tail_idx++;
  player->list[player->tail_idx].posx = pos.posx;
  player->list[player->tail_idx].posy = pos.posy;
  return 0;
}

int has_position(Snake player, Position pos) {
     unsigned short int i;
     for (i = 0; i < player.tail_idx; i++) {
          if(player.list[i].posx == pos.posx && player.list[i].posy == pos.posy) {
               return 1;
          }
     }

     return 0;
}

void head_conflit(Snake *player) {
   unsigned short i;
   unsigned short new_tail;
   for(i = 1; i < player->tail_idx+1; i++) {
        if(player->list[0].posx == player->list[i].posx && player->list[0].posy == player->list[i].posy) {
              new_tail = i;
              for(i = new_tail; i < player->tail_idx + 1; i++) {
                   Glcd_Dot(player->list[i].posx, player->list[i].posy, 2);
              }
              player->tail_idx = new_tail;
        }
   }
}

void draw_snake(Snake player) {
  unsigned short int i;
  for (i = 0; i < player.tail_idx+1; i++) {
      Glcd_Dot(player.list[i].posx, player.list[i].posy, 1);
  }
}

void move_snake(Snake *player, unsigned short int movement) {
   unsigned short int i;
   Position aux1, aux2;
   aux1.posx = player->list[0].posx;
   aux1.posy = player->list[0].posy;
   switch (movement) {
        case LEFT:
                    if(player->list[0].posx == 1) {   // chocou com a parede da esquerda
                         player->gameover = 1;
                    } else {
                         player->list[0].posx--;
                    }
        break;

        case RIGHT:
                    if(player->list[0].posx == 126) {   // chocou com a parede da direita
                         player->gameover = 1;
                    } else {
                         player->list[0].posx++;
                    }
        break;

        case UP:
                    if(player->list[0].posy == 10) {   // chocou com a parede de cima
                         player->gameover = 1;
                    } else {
                         player->list[0].posy--;
                    }
        break;

        case DOWN:
                    if(player->list[0].posy == 62) {   // chocou com a parede de baixo
                         player->gameover = 1;
                    } else {
                         player->list[0].posy++;
                    }
        break;
   }


   for(i = 1; i < player->tail_idx + 1; i++) {
         aux2.posx = player->list[i].posx;
         aux2.posy = player->list[i].posy;
         player->list[i].posx = aux1.posx;
         player->list[i].posy = aux1.posy;
         aux1.posx = aux2.posx;
         aux1.posy = aux2.posy;
   }

   Glcd_Dot(aux1.posx, aux1.posy, 2);
}

// Funcao que atualiza a pontuacao do jogador no LCD
void update_score(unsigned short int new_score) {
    char str[10];

    IntToStr(new_score, str);
    Glcd_Write_Text(str, 40, 0, 1);
}

unsigned short manhattan_dist(Position pos1, Position pos2) {
     unsigned short int x = pos1.posx - pos2.posx;
     unsigned short int y = pos1.posy - pos2.posy;
     if(x < 0) x = -1*x;
     
     if(y < 0) y = -1*y;
     
     return x+y;
}

Position add_fruit(Snake player) {
     Position ret;
     ret.posx = rand() % 123 + 3;
     ret.posy = rand() % 52 + 12;
     while(has_position(player, ret) && manhattan_dist(player.list[0], ret) < player.tail_idx+2) {
         ret.posx = rand() % 123 + 3;
         ret.posy = rand() % 52 + 12;
     }
     return ret;
}

// Funcao que desenha o quadrado do jogo
void draw_game_screen() {
    Glcd_Write_Text("Score:", 0, 0, 1);

    // Drawing the game screen
    Glcd_Line(0, 9, 127, 9, 1);                 // Draw line
    Glcd_Line(0, 127, 127, 127, 1);                 // Draw line
    Glcd_Line(0, 9, 0, 127, 1);                 // Draw line
    Glcd_Line(0, 127, 127, 127, 1);                 // Draw line
    Glcd_Line(127, 9, 127, 127, 1);                 // Draw line
}

void check_keypad(unsigned short int idx, unsigned short int function, unsigned short int *movement) {
    switch(idx) {
                case 0:
                       latc = 0b11111110;   // Escreve 0 na coluna 0
                        if(portc.rc5 == 0) {
                                    // Apertou 4
                                    if(function == GAME && (!(*movement == LEFT || *movement == RIGHT))) *movement = LEFT;
                       }
                       break;
                case 1:
                       latc = 0b11111101;   // Escreve 0 na coluna 1
                       if(portc.rc4 == 0) {
                                    // Apertou 2
                                    if(function == MENU) game_control = 2;
                                    if(function == INST) game_control = 0;
                                    if(function == GAME && (!(*movement == UP || *movement == DOWN))) *movement = UP;

                       } else if(portc.rc6 == 0) {
                                    // Apertou 8
                                    if(function == MENU) game_control = 1;
                                    if(function == GAME &&  (!(*movement == UP || *movement == DOWN))) *movement = DOWN;
                       }
                       break;
                case 2:
                       latc = 0b11111011;   // Escreve 0 na coluna 2
                       if(portc.rc5 == 0) {
                                    // Apertou 6
                                    if(function == GAME &&  (!(*movement == LEFT || *movement == RIGHT))) *movement = RIGHT;
                       }
                       break;
    }
}

void main() {
  unsigned short int score;
  unsigned short int i;
  unsigned short int movement = LEFT;
  char str[10];
  Snake player;
  Position fruit, aux;
  init_snake(&player);
  fruit  = add_fruit(player);
  score = player.tail_idx;

  doremifa.last_note_idx = 6;
  doremifa.notes_list[0].low_value = 0x1E;
  doremifa.notes_list[0].high_value = 0xFE;
  doremifa.notes_list[1].low_value = 0x56;
  doremifa.notes_list[1].high_value = 0xFE;
  doremifa.notes_list[2].low_value = 0x85;
  doremifa.notes_list[2].high_value = 0xFE;
  doremifa.notes_list[3].low_value = 0x9A;
  doremifa.notes_list[3].high_value = 0xFE;
  doremifa.notes_list[4].low_value = 0xC1;
  doremifa.notes_list[4].high_value = 0xFE;
  doremifa.notes_list[5].low_value = 0xE4;
  doremifa.notes_list[5].high_value = 0xFE;
  doremifa.notes_list[6].low_value = 0x03;
  doremifa.notes_list[6].high_value = 0xFF;
  song_idx = 0;

  low_value = doremifa.notes_list[0].low_value;                     // valores iniciais das Vari?veis globais para evitar erros
  high_value = doremifa.notes_list[0].low_value;

  game_control = 0;
  ANSELA  = 0;                                    // Configure AN pins as digital
  ANSELB = 0;
  ANSELC = 0;
  ANSELD = 0;
  ANSELE = 0;
  trise.f1 = 0;                            // RE1 configurada como sa?da
  late.re1 = 1;
  //                 T0: timer para gera??o das ondas quadradas
  T0CON = 0b10001000;        // T0CON 16 bits sem prescaler
  GIE_bit = 1;             // Habilita interrup??o global
  TMR0IF_bit = 0;
  TMR0IE_bit = 0;          // COlocar como 1 para ligar buzzer
  trisc = 0b11110000;                      // bits 7-4 como entrada e bits 3-0 como saida

  C1ON_bit = 0;                                  // Disable comparators
  C2ON_bit = 0;

  Glcd_Init();                                   // Initialize GLCD
  Glcd_Fill(0x00);                               // Clear GLCD

  Delay_ms(1000);

  while(1) {
    // Loop do menu
    while(game_control == 0) {
      Glcd_Image(snake);
      Delay_ms(200);
      for(i = 0; i < 3; i++) {
            check_keypad(i, MENU, &movement);
      }
    }
    Glcd_Fill(0x00);                               // Clear GLCD

    // Loop das intrucoes
    while (game_control == 1) {
      Glcd_Image(instrucoes);
      Delay_ms(200);
      for(i = 0; i < 3; i++) {
            check_keypad(i, INST, &movement);
      }
    }
    Glcd_Fill(0x00);                               // Clear GLCD

    // Loop do jogo
    while (game_control == 2) {
      draw_game_screen();
      update_score(score);
      Glcd_Dot(fruit.posx, fruit.posy, 1);
      draw_snake(player);
      for(i = 0; i < 3; i++) {
            check_keypad(i, GAME, &movement);
      }
      Delay_ms(25);
      move_snake(&player, movement);
      head_conflit(&player);
      score = player.tail_idx;
      if(has_position(player, fruit)) {
          if(movement == LEFT) {
               aux.posx = player.list[player.tail_idx].posx + 1;
               aux.posy = player.list[player.tail_idx].posy;
          } else if(movement == RIGHT) {
               aux.posx = player.list[player.tail_idx].posx - 1;
               aux.posy = player.list[player.tail_idx].posy;
          } else if(movement == UP) {
               aux.posx = player.list[player.tail_idx].posx;
               aux.posy = player.list[player.tail_idx].posy + 1;
          } else if(movement == DOWN) {
               aux.posx = player.list[player.tail_idx].posx;
               aux.posy = player.list[player.tail_idx].posy - 1;
          }
          append_position(&player, aux);
          Glcd_Dot(fruit.posx, fruit.posy, 2);
          fruit = add_fruit(player);
          score++;
      }
      Delay_ms(25);
      //Glcd_Fill(0x00);


      if(player.gameover) {
           Delay_ms(200);
           // Fim do jogo:
           if(!player.win) {
             Glcd_Image(gameover);
           } else {
             Glcd_Image(trofeu);
             Glcd_Write_Text("Score:", 57, 4, 1);
                 IntToStr(score, str);
                 Glcd_Write_Text(str, 90, 4, 1);
           }

           Delay_ms(5000);
           game_control = 0;
           init_snake(&player);
      }

    }
    score = player.tail_idx;
    Glcd_Fill(0x00);
  }
}