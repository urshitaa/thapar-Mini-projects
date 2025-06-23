#include <stdio.h>
#include <ctype.h>
#include <time.h>

int main() {
    FILE *inFile, *outFile;
    char ch;
    clock_t start, end;

    inFile = fopen("1000MBFile.txt", "r");
    if (inFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outFile = fopen("Uppercase.txt", "w");
    if (outFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inFile);
        return 1;
    }

    start = clock();  // Start timing

    while ((ch = fgetc(inFile)) != EOF) {
        fputc(toupper(ch), outFile);
    }

    end = clock();  // End timing

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("File converted to uppercase successfully.\n");
    printf("Time taken: %.6f seconds\n", time_taken);

    fclose(inFile);
    fclose(outFile);

    return 0;
}
