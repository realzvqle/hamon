#include <stdio.h>
#include <stdlib.h>

#define COLORS
#define GRAPHICS

#include <hamon_cli.h>
#include <hamon_config.h>
#include <hamon_escape.h>
#include <hamon_meta.h>
#include <hamon_prompt.h>

/*
 ▄▄                                                ▄▄
 ██                                                ██
 ██▄████▄   ▄█████▄  ████▄██▄   ▄████▄   ██▄████▄  ██
 ██▀   ██   ▀ ▄▄▄██  ██ ██ ██  ██▀  ▀██  ██▀   ██  ██
 ██    ██  ▄██▀▀▀██  ██ ██ ██  ██    ██  ██    ██  ▀▀
 ██    ██  ██▄▄▄███  ██ ██ ██  ▀██▄▄██▀  ██    ██  ▄▄
 ▀▀    ▀▀   ▀▀▀▀ ▀▀  ▀▀ ▀▀ ▀▀    ▀▀▀▀    ▀▀    ▀▀  ▀▀
*/

int init_shell(void) {
  char *username = get_username();
  printf("Hello, %s%s%s! and welcome to..\n", GREEN, username, CLEAR);
  printf(CYAN);
  puts("▄▄                                                ▄▄");
  puts("██                                                ██");
  puts("██▄████▄   ▄█████▄  ████▄██▄   ▄████▄   ██▄████▄  ██");
  puts("██▀   ██   ▀ ▄▄▄██  ██ ██ ██  ██▀  ▀██  ██▀   ██  ██");
  puts("██    ██  ▄██▀▀▀██  ██ ██ ██  ██    ██  ██    ██  ▀▀");
  puts("██    ██  ██▄▄▄███  ██ ██ ██  ▀██▄▄██▀  ██    ██  ▄▄");
  puts("▀▀    ▀▀   ▀▀▀▀ ▀▀  ▀▀ ▀▀ ▀▀    ▀▀▀▀    ▀▀    ▀▀  ▀▀");
  printf(CLEAR);
  printf(RED ">%s a homemade command shell, in %sC\n" CLEAR, CLEAR, BLUE);
  printf("Made with %s❤%s by %s\n", RED, CLEAR, __AUTHOR__);
  free(username);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    return process_args(argc, argv);
  }
  gen_default_config();

  // init_shell();
  return init_prompt();
}
