#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(){
  char *inputBuffer = malloc(1024*sizeof(char));
  char **parsedInputBuffer = malloc(1024*sizeof(char*));
  if(inputBuffer == NULL || parsedInputBuffer == NULL){
    fprintf(stderr, "Insufficient memory!");
    return -1;
  }
  clearScreen();
  startProgram();
  readCommandLine(inputBuffer);
  while(1){
    parseInput(inputBuffer, parsedInputBuffer);
    if(strcmp(parsedInputBuffer[0], "cd") == 0){
      changeDirectories(parsedInputBuffer[1]);
    }
    else if(strcmp(parsedInputBuffer[0], "ls") == 0){
      printDirectoryContents();
    }
    else if(strcmp(parsedInputBuffer[0], "pwd") == 0){
      printDirectoryPath();
    }
    else if(strcmp(parsedInputBuffer[0], "rmdir") == 0){
      removeDirectory(parsedInputBuffer[1]);
    }
    else if((strcmp(parsedInputBuffer[0], "rm") == 0) && (strcmp(parsedInputBuffer[1], "-r") == 0)){
      removeDirectoryContents(parsedInputBuffer[2]);
    }
    else if(strcmp(parsedInputBuffer[0], "mkdir") == 0){
      makeDirectory(parsedInputBuffer[1]);
    }
    else if(strcmp(parsedInputBuffer[0], "mvdir") == 0){
      moveDirectory(parsedInputBuffer[1], parsedInputBuffer[2]);
    }
    else if(strcmp(parsedInputBuffer[0], "cp") == 0){
      copyFile(parsedInputBuffer[1], parsedInputBuffer[2]);
    }
    else if(strcmp(parsedInputBuffer[0], "mv") == 0){
      renameFile(parsedInputBuffer[1], parsedInputBuffer[2]);
    }
    else if(strcmp(parsedInputBuffer[0], "rm") == 0){
      deleteFile(parsedInputBuffer[1]);
    }
    else if(strcmp(parsedInputBuffer[0], "chmod") == 0){
      changeFileorDirectoryPermissions(parsedInputBuffer[1], parsedInputBuffer[2]);
    }
    else if(strcmp(parsedInputBuffer[0], "chown") == 0){
      changeFileorDirectoryOwnership(parsedInputBuffer[1], parsedInputBuffer[2], parsedInputBuffer[3]);    
    }
    else if(strcmp(parsedInputBuffer[0], "cat") == 0){
      displayFileContents(parsedInputBuffer[1]);
    }
    else if(strcmp(parsedInputBuffer[0], "head") == 0){
      displayFirstFewLines(parsedInputBuffer[1]);
    }
    else if(strcmp(parsedInputBuffer[0], "tail") == 0){
      displayLastFewLines(parsedInputBuffer[1]);
    }
    else if(strcmp(parsedInputBuffer[0], "whoami") == 0){
      displayUserName();
    }
    else if(strcmp(parsedInputBuffer[0], "uname") == 0){
      displaySystemInfo();
    }
    else if(strcmp(parsedInputBuffer[0], "clear") == 0){
      clearScreen();
    }
    else if(strcmp(parsedInputBuffer[0], "history") == 0){
      displayCommandHistory();
    }
    else if(strcmp(parsedInputBuffer[0], "exit") == 0){
      exitShell();
    }
    else if(strcmp(parsedInputBuffer[0], "kill") == 0){
      killProcess(atoi(parsedInputBuffer[1]));
    }
    readCommandLine(inputBuffer);
  }

  free(inputBuffer);
  free(parsedInputBuffer);
  return 0;
}