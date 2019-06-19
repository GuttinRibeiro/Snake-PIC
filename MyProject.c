#define MENU 0
#define GAME 1
#define INST 2

// Glcd module connections
char GLCD_DataPort at PORTD;

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
typdef struct musical_note {
  unsigned short int low_value;
  unsigned short int high_value;
} Note;

typedef struct song {
  notes_list[20];
  last_note_idx;
} Song;


Song doremifa;
unsigned short int song_idx;

unsigned short int game_control;
// Vari�veis globais que configuram o MSB e o LSB do TMR0
unsigned short int low_value, high_value;

void interrupt_timer() iv 0x0008 ics ICS_AUTO {
    TMR0L = doremifa.notes_list[song_idx].low_value;           // Configura o valor inicial do timer
    TMR0H = doremifa.notes_list[song_idx].high_value;
    if(song_idx == doremifa.las_note_idx) {
      song_idx = 0;
    } else {
      song_idx++;
    }

    late.re1 = ~late.re1;     // Complementa a sa�da do buzzer para gerar a onda quadrada
    TMR0IF_bit = 0;         // Zera a flag de interrup��o do timer 0
    TMR0IE_bit = 1;
}

// Desenha as instru��es do jogo no LCD
void draw_instructions() {
  Glcd_Write_Text("TODO", 16, 2, 1);
}

// Desenha as op��es do menu no LCD
void draw_menu() {
  Glcd_Write_Text("Jogar - 2", 16, 2, 1);
  Glcd_Write_Text("Instrucoes- 8", 16, 4, 1);
  
  // Drawing the menu screen
  Glcd_Line(12, 10, 115, 10, 1);                 // Linha superior
  Glcd_Line(12, 50, 115, 50, 1);                 // Linha inferior
  Glcd_Line(12, 10, 12, 50, 1);                    // Linha lateral esquerda
  Glcd_Line(115, 10, 115, 50, 1);                 // Linha lateral direita
}

// Fun��o que atualiza a pontua��o do jogador no LCD
void update_score(unsigned short int new_score) {
    char str[10];

    IntToStr(new_score, str);
    Glcd_Write_Text(str, 40, 0, 1);
}

// Fun��o que desenha o quadrado do jogo
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

  low_value = doremifa.notes_list[0].low_value;                     // valores iniciais das Vari�veis globais para evitar erros
  high_value = doremifa.notes_list[0].low_value;

  game_control = 0;
  ANSELA  = 0;                                    // Configure AN pins as digital
  ANSELB = 0;
  ANSELC = 0;
  ANSELD = 0;
  ANSELE = 0;
  trise.f1 = 0;                            // RE1 configurada como sa�da
  late.re1 = 1;
  //                 T0: timer para gera��o das ondas quadradas
  T0CON = 0b10001000;        // T0CON 16 bits sem prescaler
  GIE_bit = 1;             // Habilita interrup��o global
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
    
    // Loop das intru��es
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
    }

  }
}
