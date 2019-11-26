#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args( char * line );

char ** parse_args( char * line ){
  char ** args = malloc(6);
  char line_array[100];
  strcpy(line_array, line);
  char * line_parse = line_array;
  int i = 0;
  while (line_parse){
    char temp[100];
    char * token = strsep(&line_parse, " ");
    strcpy(temp, token);
    args[i] = malloc(sizeof(temp));
    strcpy(args[i], temp);
    i++;
  }
  return args;
}

int main(){
  char * test_string = "ls -a -l";
  printf("\"Command line invocation\": %s\n", test_string);
  printf("Running parse_args on the invocation...\n");
  char ** args = parse_args(test_string);
  printf("ok\n");
  // char * args[6];
  int i = 0;
  printf("ok\n");
  // printf("%s\n", *(args_temp));
  printf("%s\n", args[0]);
  printf("Running execvp for the invocation...\n");
  execvp(args[0], args);
  return 0;
}
