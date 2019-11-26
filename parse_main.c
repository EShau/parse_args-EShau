#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args( char * line );

char ** parse_args( char * line ){
  char ** args = calloc(6, sizeof(char));
  char line_array[100];
  strcpy(line_array, line);
  char * line_parse = line_array;
  printf("%s\n", line_array);
  int i = 0;
  while (line_parse){
    char temp[100];
    char * token = strsep(&line_parse, " ");
    strcpy(temp, token);
    args[i] = malloc(sizeof(temp));
    strcpy(args[i], temp);
    printf("%s\n", args[i]);
    i++;
  }
  while (i < 6){
    args[i] = NULL;
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
  int i = 0;
  printf("ok\n");
   for (i = 0; i < 6; i++){
     printf("%s\n", *(args + i));
   }
  printf("ok\n");
  char * y[] = {"ls", "-a", "-l", NULL};
  printf("%s\n", args[0]);
  printf("Running execvp for the invocation...\n");
  execvp(args[0], y);
  return 0;
}
