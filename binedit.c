#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  pront
  char filename[256];
  FILE *fp = NULL;

  printf("Enter the filename: ");

  if (fgets(filename, sizeof(filename), stdin) != NULL) {
        // Remove the trailing newline character if it exists
      filename[strcspn(filename, "\n")] = 0;

        // Try to open the file
      fp = fopen(filename, "r"); // Open in read mode

      if (fp == NULL) {
          perror("Error opening file"); // Print system-specific error
          return EXIT_FAILURE; // Indicate failure
      } 
      else {
          printf("File '%s' opened successfully!\n", filename);
            // Example: Read and print the first line of the file
          char line[1024];
          if (fgets(line, sizeof(line), fp) != NULL) {
            printf("First line: %s", line);
          } 
          else {
            printf("File is empty or could not read first line.\n");
          }

          fclose(fp); // Close the file when done
          printf("File closed.\n");
      }
  } 
  else {
    fprintf(stderr, "Error reading filename from input.\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS; // Indicate success
}
