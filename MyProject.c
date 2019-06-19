#define MENU 0
#define GAME 1
#define INST 2

// Glcd module connections
char GLCD_DataPort at PORTD;

/*const code char gameover[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,  96,  32,  32,  96,   0,   0, 128, 128, 128, 128,   0,   0, 128, 128, 128, 128, 128, 128, 128,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0, 128, 128, 128, 128,   0, 128,   0,   0,   0, 128,   0,   0, 128, 128,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   7,  12,   8,   9,  15,   0,   0,  14,  10,  10,  15,   0,   0,  15,   0,   0,  15,   0,   0,  15,   0,   0,   7,  10,  10,  11,   0,   0,   0,   0,  15,   8,   8,  15,   0,   0,   3,  12,  12,   3,   0,   7,  10,  10,  11,   0,   0,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 224, 240, 248, 248, 248, 248, 240, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224, 240, 248, 248, 248, 248, 240, 224, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  15,  31,  31,  31,  31,  15,  15,  31, 191, 220, 232, 224, 240, 240, 248, 248, 248, 248, 248, 252, 252, 252, 252, 248, 248, 248, 248, 248, 240, 240, 224, 232, 220, 191,  31,  15,  15,  31,  31,  31,  31,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 127, 255, 255, 255, 255, 255,  63,  63,  63,  63,  63, 127, 255, 255, 255, 255, 127,  63,  63,  63,  63,  63, 255, 255, 255, 255, 255,  62,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  29, 255, 255, 224, 192, 192, 192, 192, 192, 224, 247, 127, 127, 243, 224, 192, 192, 192, 192, 192, 224, 255, 255,  13,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 240, 248, 248, 248, 248, 240, 240, 248, 252,  62,  29,  11,  11,  15,  31, 255, 255, 127, 255, 248, 248, 252, 120, 255, 127, 255, 255,  31,  15,  11,  11,  29,  62, 252, 248, 240, 240, 248, 248, 248, 248, 240,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   7,  15,  31,  31,  31,  31,  15,   7,   0,   0,   0,   0,   0,   1,   1,   0,   1,   1,   1,   1,   0,   1,   0,   1,   1,   0,   0,   0,   0,   0,   7,  15,  31,  31,  31,  31,  15,   7,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};*/

/*const code char snake[1024] = {
255, 255,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  56,  68,  68,  68, 136,   0,   0, 240,  32,  16,  16,  16, 224,   0,   0,  32, 144, 144, 144, 224,   0,   0, 254, 128,  64,  32,  16,   0,   0, 224, 144, 144, 144, 144, 224,   0,   0,   0,   0,   0, 224,  16,  16,  16,  16, 224,   0,   0, 240,  32,  16,  16,  16, 224,   0,   0,   0,   0,   0, 252,  68,  68,  68,  68,  56,   0,   0, 252,   0,   0,   0, 240,   8,   4,   4,   4,   4,   8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   4,   4,   4,   3,   0,   0,   7,   0,   0,   0,   0,   7,   0,   0,   3,   4,   4,   2,   7,   0,   0,   7,   0,   1,   2,   4,   0,   0,   3,   4,   4,   4,   4,   4,   0,   0,   0,   0,   0,   3,   4,   4,   4,   4,   3,   0,   0,   7,   0,   0,   0,   0,   7,   0,   0,   0,   0,   0,   7,   0,   0,   0,   0,   0,   0,   0,   7,   0,   0,   0,   1,   2,   4,   4,   4,   4,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 252,   0,   0, 240,  16,  16, 240,   0, 240,  80,  80, 112,  16,   0, 208,  80,  80, 240,   0,   0, 240,  16,  16,   0,   0,  64,  64,  64,   0,   0,   0, 208,  80,  80, 240,   0,   0, 240,  16,  16, 224,   0,   0, 224,  80,  80,  96,   0,   0, 240,  16,  16,  16, 248,  16,   0,   0, 224,  80,  80,  96,   0,   0,   0,   0,   8, 132, 100,  56,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1, 129,   1,   0,   0,   1,   1,   1,   1,   0,   6,   5,   5,   5,   3,   0,   1,   1,   1,   1,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   0,   0,   7,   1,   1,   0,   0,   0,   0,   1,   1,   1,   0,   0,   1,   0,   0,   0,   1,   1,   0,   0,   0,   1,   1,   1,   0,   0,   0,   0,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  63,   0,   0,  62,   2,   2,  62,   0,  38,  42,  58,   0,   0,   2,  63,  34,   0,   0,  62,   2,   2,   0,  62,  32,  32,  62,   0,   0,  28,  34,  34,  34,   0,  62,  34,  34,  62,   0,   0,  28,  42,  42,  44,   0,  38,  42,  58,   0,   0,   0,   0,   8,   8,   8,   0,   0,   0,  58,  42,  42,  62,   0,   0, 254,  34,  34,  28,   0,   0,  28,  42,  42,  44,   0,   0,  62,   2,   2,   2,  63,  34,   0,   0,  28,  42,  42,  44,   0,   0,   0,  27,  36,  36,  36,  27,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255,
255, 255, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 255, 255, 255
};*/

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
typedef struct musical_note {
  unsigned short int low_value;
  unsigned short int high_value;
} Note;

typedef struct song {
  Note notes_list[20];
  unsigned short int last_note_idx;
} Song;


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

// Desenha as instru??es do jogo no LCD
void draw_instructions() {
  Glcd_Write_Text("TODO", 16, 2, 1);
}

// Desenha as op??es do menu no LCD
void draw_menu() {
  Glcd_Write_Text("Jogar - 2", 16, 2, 1);
  Glcd_Write_Text("Instrucoes- 8", 16, 4, 1);

  // Drawing the menu screen
  Glcd_Line(12, 10, 115, 10, 1);                 // Linha superior
  Glcd_Line(12, 50, 115, 50, 1);                 // Linha inferior
  Glcd_Line(12, 10, 12, 50, 1);                    // Linha lateral esquerda
  Glcd_Line(115, 10, 115, 50, 1);                 // Linha lateral direita
  
  //Glcd_Image(snake);
}

// Fun??o que atualiza a pontua??o do jogador no LCD
void update_score(unsigned short int new_score) {
    char str[10];

    IntToStr(new_score, str);
    Glcd_Write_Text(str, 40, 0, 1);
}

// Fun??o que desenha o quadrado do jogo
void draw_game_screen() {
    Glcd_Write_Text("Score:", 0, 0, 1);

    // Drawing the game screen
    Glcd_Line(0, 9, 127, 9, 1);                 // Draw line
    Glcd_Line(0, 127, 127, 127, 1);                 // Draw line
    Glcd_Line(0, 9, 0, 127, 1);                 // Draw line
    Glcd_Line(0, 127, 127, 127, 1);                 // Draw line
    Glcd_Line(127, 9, 127, 127, 1);                 // Draw line
}


void check_keypad(unsigned short int idx, unsigned short int function) {
    switch(idx) {
                case 0:
                       latc = 0b11111110;   // Escreve 0 na coluna 0
                        if(portc.rc5 == 0) {
                                    // Apertou 4

                       }
                       break;
                case 1:
                       latc = 0b11111101;   // Escreve 0 na coluna 1
                       if(portc.rc4 == 0) {
                                    // Apertou 2
                                    if(function == MENU) game_control = 2;
                                    if(function == INST) game_control = 0;

                       } else if(portc.rc6 == 0) {
                                    // Apertou 8
                                    if(function == MENU) game_control = 1;

                       }
                       break;
                case 2:
                       latc = 0b11111011;   // Escreve 0 na coluna 2
                       if(portc.rc5 == 0) {
                                    // Apertou 6

                       }
                       break;
    }
}



void main() {
  unsigned short int score = 100;
  unsigned short int i;

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
  draw_menu();

  while(1) {
    // Loop do menu
    while(game_control == 0) {
      draw_menu();
      Delay_ms(200);
      for(i = 0; i < 3; i++) {
            check_keypad(i, MENU);
      }
    }
    Glcd_Fill(0x00);                               // Clear GLCD

    // Loop das intru??es
    while (game_control == 1) {
      draw_instructions();
      Delay_ms(200);
      for(i = 0; i < 3; i++) {
            check_keypad(i, INST);
      }
    }
    Glcd_Fill(0x00);                               // Clear GLCD

    // Loop do jogo
    while (game_control == 2) {
      draw_game_screen();

      update_score(score);
      Delay_ms(200);
      
      // Fim do jogo:
      //Glcd_Image(gameover);
    }
    Glcd_Fill(0x00);
  }
}
