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

// Desenha as instruções do jogo no LCD
void draw_instructions() {
  Glcd_Write_Text("TODO", 30, 50, 1);
}

// Desenha as opções do menu no LCD
void draw_menu() {
  Glcd_Write_Text("Jogar - 1", 40, 40, 1);
  Glcd_Write_Text("Instruções- 2", 30, 50, 1);
}

// Função que atualiza a pontuação do jogador no LCD
void update_score(unsigned short int new_score) {
    char str*;
    str = (char *) malloc(6*sizeof(char));

    if(str != NULL) {
      IntToStr(new_score, str);
      Glcd_Write_Text(str, 40, 0, 1);
    }
    free(str);
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

void main() {
  unsigned short int score = 100;
  unsigned short int game_control = 0;
  ANSELA  = 0;                                    // Configure AN pins as digital
  ANSELB = 0;
  ANSELC = 0;
  ANSELD = 0;
  ANSELE = 0;

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

      // TODO: pegar entradas do keypad
    }

    // Loop das intruções
    while (game_control == 1) {
      draw_instructions();
      Delay_ms(200);
    }
    
    // Loop do jogo
    while (game_control == 2) {
      draw_game_screen();

      update_score(score);
      Delay_ms(200);
    }

  }
}


