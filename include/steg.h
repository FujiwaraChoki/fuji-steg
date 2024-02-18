#ifndef STEG_H
#define STEG_H

#include <stdio.h>

// Function to embed secret data into a carrier file
void embedData(const char *imageFileName, const char *outputFileName, const char *message);

// Function to extract secret data from a carrier file
char *extractData(const char *imageFileName);

#endif /* STEG_H */
