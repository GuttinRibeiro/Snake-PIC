/* Por: Augusto Ribeiro Castro - 9771421
        Gabriel Santos Ribeiro - 9771380
*/

// Contantes que controlam o fluxo principal das telas
#define MENU 0
#define GAME 1
#define INST 2

// Conexão de dados do GLCD
char GLCD_DataPort at PORTD;

// Estrutura para desenhar caveira de fim de jogo
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

// Estrutura para desenhar o menu inicial da aplicação
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

// Estrutura para desenhar o menu de instruções
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

// Estrutura para desenhar o troféu de vitória ao fim do jogo
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

// Definição dos bits do GLCD:
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
// Fim das conexões do GLCD

// Estruturas globais:
// Enumeração de comandos de direção
enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// Estrutura auxiliar de posição
typedef struct position {
     unsigned short int posx;
     unsigned short int posy;
} Position;

// Estrutura snake que encapsula as informações do jogador:
// Lista de posições da cobra, flags de fim de jogo e de vitória,
// índice da última posição preenchida no vetor da cobra para calcular
// pontuação e usada em operações de inserção/remoção e para percorrer
// o vetor pelas posições válidas
typedef struct snake_char {
  Position list[200];
  unsigned short int tail_idx;
  unsigned short int gameover;
  unsigned short int win;
} Snake;


// Variável global que controla se o jogo está no menu inicial, 
// nas intruções ou no jogo
unsigned short int game_control;

// Funções para as estruturas de dados:
// Função que inicializa a estrutura Snake, configurando o tamanho,
// as posições iniciais e as flags
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


// Função que adiciona uma nova posição à estrutura Snake no final do
// vetor. Retorna 1 caso ocorra um erro (posição com coordenadas invá
// lidas ou limite máximo de posições atingido => caso de vitória)
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

// Função que retorna 1 se a estrutura Snake possui a posição recebida
// e 0 caso contrário
int has_position(Snake player, Position pos) {
     unsigned short int i;
     for (i = 0; i < player.tail_idx; i++) {
          if(player.list[i].posx == pos.posx && player.list[i].posy == pos.posy) {
               return 1;
          }
     }

     return 0;
}

// Função que trata o caso de a cobra comer o próprio rabo
void head_conflict(Snake *player) {
   unsigned short i;
   unsigned short new_tail;
   for(i = 1; i < player->tail_idx+1; i++) {
        if(player->list[0].posx == player->list[i].posx && player->list[0].posy == player->list[i].posy) {
              Sound_Play(100, 1000);   // Frequencia = 100Hz, duracao = 1000ms
              new_tail = i;
              for(i = new_tail; i < player->tail_idx + 1; i++) {
                   // Apagar o ponto no GLCD: complementar cor
                   Glcd_Dot(player->list[i].posx, player->list[i].posy, 2);
              }
              player->tail_idx = new_tail;
        }
   }
}

// Função que desenha a cobra no GLCD
void draw_snake(Snake player) {
  unsigned short int i;
  for (i = 0; i < player.tail_idx+1; i++) {
      Glcd_Dot(player.list[i].posx, player.list[i].posy, 1);
  }
}

// Função que realiza a movimentação da cobra com base no movimento
// desejado recebido, utilizando a enumeração
void move_snake(Snake *player, unsigned short int movement) {
   unsigned short int i;
   Position aux1, aux2;
   aux1.posx = player->list[0].posx;
   aux1.posy = player->list[0].posy;
   switch (movement) {
        case LEFT:
                    if(player->list[0].posx == 1) {   // chocou com a parede da esquerda
                         player->gameover = 1;
                         Sound_Play(100, 1000);   // Frequencia = 100 Hz, duracao = 1000 ms
                    } else {
                         player->list[0].posx--;
                    }
        break;

        case RIGHT:
                    if(player->list[0].posx == 126) {   // chocou com a parede da direita
                         player->gameover = 1;
                         Sound_Play(100, 1000);   // Frequencia = 100 Hz, duracao = 1000 ms
                    } else {
                         player->list[0].posx++;
                    }
        break;

        case UP:
                    if(player->list[0].posy == 10) {   // chocou com a parede de cima
                         player->gameover = 1;
                         Sound_Play(100, 1000);   // Frequencia = 100 Hz, duracao = 1000 ms
                    } else {
                         player->list[0].posy--;
                    }
        break;

        case DOWN:
                    if(player->list[0].posy == 62) {   // chocou com a parede de baixo
                         player->gameover = 1;
                         Sound_Play(100, 1000);   // Frequencia = 100 Hz, duracao = 1000 ms
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

// Função que atualiza a pontuacao do jogador no LCD
void update_score(unsigned short int new_score) {
    char str[10];

    IntToStr(new_score, str);
    Glcd_Write_Text(str, 40, 0, 1);
}

// Função que retorna a distância de Manhattan entre duas posições
unsigned short manhattan_dist(Position pos1, Position pos2) {
     unsigned short int x = pos1.posx - pos2.posx;
     unsigned short int y = pos1.posy - pos2.posy;
     if(x < 0) x = -1*x;
     
     if(y < 0) y = -1*y;
     
     return x+y;
}

// Função que retorna a posição calculada de uma fruta com base na
// cobra e na distância de Manhattan
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

// Função que desenha o quadrado do jogo
void draw_game_screen() {
    Glcd_Write_Text("Score:", 0, 0, 1);

    // Drawing the game screen
    Glcd_Line(0, 9, 127, 9, 1);                 // Draw line
    Glcd_Line(0, 127, 127, 127, 1);                 // Draw line
    Glcd_Line(0, 9, 0, 127, 1);                 // Draw line
    Glcd_Line(0, 127, 127, 127, 1);                 // Draw line
    Glcd_Line(127, 9, 127, 127, 1);                 // Draw line
}

// Função que trata as entradas do teclado matricial
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

  game_control = 0;
  ANSELA  = 0;                                    // Configura portas como digitais
  ANSELB = 0;
  ANSELC = 0;
  ANSELD = 0;
  ANSELE = 0;
  trise.f1 = 0;                            // RE1 configurada como saída (buzzer)
  late.re1 = 1;

  Sound_Init(&PORTE, 1);                   // Inicialização da lib Sound para o pino RE1 (buzzer)
  trisc = 0b11110000;                      // bits 7-4 como entrada e bits 3-0 como saida

  C1ON_bit = 0;                                  // Desativa comparadores
  C2ON_bit = 0;

  Glcd_Init();                                   // Inicializa o GLCD
  Glcd_Fill(0x00);                               // Limpa o GLCD

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
    Glcd_Fill(0x00);                               // Limpa o GLCD

    // Loop das intrucoes
    while (game_control == 1) {
      Glcd_Image(instrucoes);
      Delay_ms(200);
      for(i = 0; i < 3; i++) {
            check_keypad(i, INST, &movement);
      }
    }
    Glcd_Fill(0x00);                               // Limpa o GLCD

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
      head_conflict(&player);
      score = player.tail_idx;
      if(has_position(player, fruit)) {
          Sound_Play(600, 1000);   // Frequencia = 600 Hz, duracao = 1000ms
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

      if(player.gameover) {
           Delay_ms(200);
           // Fim do jogo:
           if(!player.win) {
             Glcd_Image(gameover);
              Sound_Play(132, 500);  Sound_Play(132, 250);  Sound_Play(132, 200);  Sound_Play(132, 200);  Sound_Play(148, 250); Sound_Play(165, 300); Sound_Play(165, 1000);
           } else {
             Glcd_Image(trofeu);
             Glcd_Write_Text("Score:", 57, 4, 1);
             IntToStr(score, str);
             Glcd_Write_Text(str, 90, 4, 1);
             //Tocar ode � alegria - n�o ficou nem um pouco parecido no PIC:
             //MI - MI - FA - SOL - SOL
             Sound_Play(165, 250); Sound_Play(165, 250); Sound_Play(176, 250); Sound_Play(198, 250); Sound_Play(198, 250);
             //FA - MI - RE - DO - DO
             Sound_Play(176, 250); Sound_Play(165, 250); Sound_Play(148, 250); Sound_Play(132, 250); Sound_Play(132, 250);
             //RE - MI - MI - RE - RE
             Sound_Play(148, 250); Sound_Play(165, 250); Sound_Play(165, 250); Sound_Play(148, 250); Sound_Play(148, 250);
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