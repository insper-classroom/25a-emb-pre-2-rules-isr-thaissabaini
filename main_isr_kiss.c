#include "asf.h"

volatile int g_cnt = 0;
volatile char g_str[10];
volatile int btn_flag = 0;

// Callback de interrupção do botão
void btn_callback(void) {
  btn_flag = 1;
}

void main(void) {
  while (1) {
    if (btn_flag) {
      btn_flag = 0;
      printf("btn pressed \n");

      if (g_cnt >= 8)
        g_cnt = 0;
      
      g_cnt = 2;
      for (int i = 0; i < g_cnt; i++) {
        g_str[i] = '*';
      }
      g_str[g_cnt] = '\0';
      
      gfx_mono_draw_string(g_str, 0, 0, &sysfont);
    }
  }
}
