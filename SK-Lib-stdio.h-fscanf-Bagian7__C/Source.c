#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

/*
    Source by Microsoft
    Modified For Learn by RK
    I.D.E : VS2019
*/

FILE* stream;

int main(void) {
    long l;
    float fp;
    char s[81];
    char c;

    if (fopen_s(&stream, "fscanf.out", "w+") != 0){
        printf("The file fscanf.out was not opened\n");
    } else {
        fprintf(stream, "%s %ld %f%c", "a-string", 65000, 3.14159, 'x');
        fseek(stream, 0L, SEEK_SET);

        fscanf(stream, "%s", s);   // C4996
        fscanf(stream, "%ld", &l); // C4996

        fscanf(stream, "%f", &fp); // C4996
        fscanf(stream, "%c", &c);  // C4996
        // Note: fscanf is deprecated; consider using fscanf_s instead

        // Output data read:
        printf("%s\n", s);
        printf("%ld\n", l);
        printf("%f\n", fp);
        printf("%c\n", c);

        fclose(stream);
    }

    _getch();
    return 0;
}