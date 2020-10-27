//============================================================================
// Name        : Practice_Prj.cpp
// Author      : Freddy Carrillo
// Version     :
// Description : Parsing Common Log Format - Code Assessment Question:
//               Every log with object size greated than 5000 bytes,
//               create new file and put in the first line the number of
//               logs with object size greater then 5000, and in the second
//               line the sum of the bytes (object size)
//============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE	(1000u)

int main()
{
	FILE *ifp, *ofp;
	char outputFilename[] = "outList.txt";
	char ch;
	char *line = (char *) malloc (sizeof(char) * LINE_SIZE);
	int index = 0;
	char buffer[10];
	int sum = 0;
	int temp = 0;
	unsigned int counter = 0;

	ifp = fopen("inList.txt", "r");

	if (ifp == NULL) {
		fprintf(stderr, "ERROR: Cannot open input file inList.txt!\n");
		exit(1);
	}

	ofp = fopen(outputFilename, "w");

	if (ofp == NULL) {
		fprintf(stderr, "ERROR: Cannot open output file %s!\n", outputFilename);
		exit(1);
	}

	int i = 0;
	int k = 0;

	// Start by getting each character until EOF
	ch = fgetc(ifp);
	while(ch != EOF) {
		line[i++] = ch;
		if(ch == '\n') {
			index = strlen(line);
			while(line[index] != ' ') {index--;}

			// Go to the end of the line and set index
			// to the beginning of the size of the object
			// returned to the client
			k = 0;
			index++;
			while(line[index] != '\n') {
				buffer[k] = line[index];
				k++;
				index++;
			}
			buffer[k] = '\0';

			// If greater than 5000 bytes, add to sum
			temp = atoi(buffer);
			if(temp > 5000) {
				sum += temp;
				counter++;
			}
		}
		ch = fgetc(ifp);
	}

	fprintf(ofp, "%d\n", counter);
	fprintf(ofp, "%d\n", sum);

	fclose(ifp);
	fclose(ofp);

    return 0;
}
