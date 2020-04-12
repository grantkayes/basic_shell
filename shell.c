#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);
void lsh_loop(void);
char *lsh_read_line();

int main(int argc, char *argv[]) {

  //load config files
  
  //run command loop.
  lsh_loop();

  //perform any shutdown/cleanup

  return EXIT_SUCCESS;
}

void lsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = lsh_read_line();
    
    free(line);
    free(args);
  } while (status);
}

#define LSH_RL_BUFSIZE 1024
char *lsh_read_line() {
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0; 
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (7) {
    // read a character
    c = getchar();

    // if we git EOF, replace it with a null character and return
    if (c == EOF || c == "\n") {
      buffer[position] = "\0";
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // if we have exceeded the buffer, reallocate
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
      
    
     


