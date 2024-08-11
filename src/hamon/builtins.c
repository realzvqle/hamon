#include "headers/builtins.h"

int builtin_echo(int argc, char *argv[]) {
  char *message = {0};

  if (argc > 2) {
    message = argv[2];
    if (strncmp(argv[1], "-E", 2) == 0) {
      fwrite(message, 1, strlen(argv[2]), stdout);
      return 1;
    }

    if (strncmp(argv[1], "-n", 2) == 0) {
      printf("%s", message);
      return 1;
    }
  } else {
    message = argv[1];
  }

  puts(message);
  return 1;
}

int builtin_exit(int argc, char *argv[]) {
  int code = 0;
  if (argc > 1) {
    int code = (int)(unsigned long)argv[1];
  }
  exit(code);
  return 1;
}

int builtin_cd(int argc, char *argv[]) {
  puts("cd: I don't feel like doing this yet, soz");
  return 1;
}

int builtin_help(int argc, char *argv[]) {
  puts("help: I don't feel like doing this yet, soz");
  return 1;
}

// TODO: figure this shit out

int check_builtins(int argc, char *argv[]) {
  const char *builtin_strs[] = {"cd", "help", "echo", "exit"};
  int (*builtin_funcs[])() = {&builtin_cd, &builtin_help, &builtin_echo,
                              &builtin_exit};
  int num_builtins = sizeof(builtin_strs) / sizeof(char *);

  for (int builtin_index = 0; builtin_index < num_builtins; builtin_index++) {
    if (strncmp(builtin_strs[builtin_index], argv[0], 4) == 0) {
      return builtin_funcs[builtin_index](argc, argv);
    }
  }

  return 0;
}
