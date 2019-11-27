#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args( char * line );

char ** parse_args( char * line ){
  char ** args = malloc(1);
  char line_array[100];
  strcpy(line_array, line);
  char * line_parse = line_array;
  int i = 0;
  while (line_parse){
    args[i] = strsep(&line_parse, " ");
    printf("%s\n", args[i]);
    i++;
    args = realloc(args, i);
  }
  args[i] = NULL;
  return args;
}

int main(){
  char * test_string = "ls -a -l";
  printf("\"Command line invocation\": %s\n", test_string);
  printf("Running parse_args on the invocation...\n");
  char ** args = parse_args(test_string);
  int i = 0;
  while (args[i]){
    printf("%s\n", args[i]);
    i++;
  }
  printf("Running execvp for the invocation...\n");
  execvp(args[0], args);
  return 0;
}
