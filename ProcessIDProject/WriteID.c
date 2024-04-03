//demonstrates the usage of getpid() and getppid() functions
//to retrieve the process ID and the parent process ID.
//The program is modified to write the process ID's to a file instead
//of only printing them to the console. This program will include an 
//example of reading contents of that file (process_ids.txt) to display
//the ID's it is used as a place holder and can customized to use any other text file

#include <stdio.h>
//functions require <unistd.h>
#include <unistd.h>

int main() {
	
	//assign to long
	long IPid;
	long IPPid;
    // Get the process ID (pid) for this process
    pid_t IPid = getpid();
    // Get the parent process ID (pid) for this process
    pid_t IPPid = getppid();

    // Open a file for writing
    FILE *file = fopen("process_ids.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the process ID (PID) and parent process ID (PPID) to the file
    fprintf(file, "Process ID (PID): %ld\n", (long)IPid);
    fprintf(file, "Parent Process ID (PPID): %ld\n", (long)IPPid);

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("process_ids.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read and print the contents of the file
    char line[100]; // assuming no line is longer than 100 characters
    printf("Contents of process_ids.txt:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    return 0;
}
