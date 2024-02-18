#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "steg.h"

void embedData(const char *imageFileName, const char *outputFileName, const char *message) {
    FILE *imageFile = fopen(imageFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (imageFile == NULL || outputFile == NULL) {
        printf("[ERROR] Couldn't open files.\n");
    }

    // Write the text length as a marker for extraction
    size_t textLength = strlen(message);
    fwrite(&textLength, sizeof(size_t), 1, outputFile);

    // Write the text to the output file
    fwrite(message, sizeof(char), textLength, outputFile);

    // Copy pixel data from image file to output file
    int byte;
    while ((byte = fgetc(imageFile)) != EOF) {
        fputc(byte, outputFile);
    }

    fclose(imageFile);
    fclose(outputFile);
}

// Function to extract text hidden in an image using LSB steganography
char *extractData(const char *imageFileName) {
    FILE *imageFile = fopen(imageFileName, "rb"); // Open image file for reading in binary mode

    if (imageFile == NULL) {
        printf("[ERROR] Couldn't open image file.\n");
    }

    // Read the text length marker
    size_t textLength;
    fread(&textLength, sizeof(size_t), 1, imageFile);

    // Allocate memory to store the extracted text
    char *extractedText = (char *)malloc((textLength + 1) * sizeof(char));

    // Read the text from the image file
    fread(extractedText, sizeof(char), textLength, imageFile);

    // Add null terminator to make it a valid string
    extractedText[textLength] = '\0';

    fclose(imageFile);

    return extractedText;
}