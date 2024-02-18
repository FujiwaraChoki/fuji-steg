#include "steg.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("[ERROR] Usage: %s <action> <args>\n", argv[0]);
        return 1;
    }

    char *action = argv[1];

    if (strcmp(action, "embed") == 0) {
        printf("[INFO] Embedding data...\n");
        if (argc < 4) {
            printf("[ERROR] Usage: %s encode <input_file> <message>\n", argv[0]);
            return 1;
        }

        char *inputFileName = argv[2];
        char *outputFileName = argv[3];
        char *message = argv[4];

        embedData(inputFileName, outputFileName, message);

        printf("[SUCCESS] Data embedded successfully: %s\n", message);
    } else if (strcmp(action, "extract") == 0) {
        if (argc < 3) {
            printf("[ERROR] Usage: %s decode <input_file>\n", argv[0]);
            return 1;
        }
        
        char *inputFileName = argv[2];

        printf("[INFO] Extracting data from %s...\n", inputFileName);

        char *extractedData = extractData(inputFileName);

        printf("[SUCCESS] Data extracted successfully\n=============================\n%s\n=============================\n", extractedData);
    } else {
        printf("[ERROR] Invalid action: %s\n", action);
        return 1;
    }

    return 0;
}
