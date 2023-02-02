/* Author:   
 * Date:     
 * Purpose:  Reads an image file in grayscale format
 *           and generates a new image file with increased brightness
 *           
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define INPUTFILE "input.pgm"
#define OUTPUTFILE "output.pgm"

int main(void) {
    FILE *inFile;
    FILE *outFile;
    int width, height, white, inPixel, outPixel;

    inFile = fopen(INPUTFILE, "r");
    outFile = fopen(OUTPUTFILE, "w");
    
    if (inFile == NULL || outFile == NULL)
        printf("Error opening input file - program terminating...\n");
    else{
        fscanf(inFile, "%d %d %d", &width ,&height, &white);
        fprintf(outFile, "%d\t%d\t%d\n",width ,height, white);
        int i = 1;
        while(i<=height){
            int j = 1;
            while (j<=width){
                fscanf(inFile, "%d", &inPixel);
                outPixel = (double)white * sqrt((double)inPixel / white);
                fprintf(outFile, "%d\t", outPixel);
                j++;
            }
            printf("\n");
         i++;   
        }
    }
        
    fclose(outFile);
        
    return 0;
}