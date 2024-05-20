# Process ID Project

## Table of Contents

1. [Overview](#Overview)
2. [Files](#Files)
    - WriteID.c
    - RunCommand.bash
3. [Usage Instructions](#User-Instructions)
4. [Compilation and Execution](#Compilation-and-Execution)
5. [Example Output](#Example-Output)

## Overview

The project consists of a C program (WriteID.c) that writes the current process ID (PID) and the parent process ID (PPID) to a file. The program then reads the contents of the file and displays it. The accompanying bash script (RunCommand.bash) provides the commands needed to compile and run the C program.

## Files

### WriteID.c

This C program retrieves the current process ID and the parent process ID, writes these IDs to a file named process_ids.txt, and then reads and prints the contents of the file.
```
#include <stdio.h>
#include <unistd.h>

int main() {
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
    fprintf(file, "Process ID (PID): %d\n", (int)IPid);
    fprintf(file, "Parent Process ID (PPID): %d\n", (int)IPPid);

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

```

### RunCommand.bash
This bash script provides the commands to compile and run the **WriteID.c** program.
```
#!/bin/bash

# Compile the C program
gcc WriteID.c -o WriteID

# Run the compiled program
./WriteID
```

## Usage Instructions

1. **Ensure you have the GCC compiler installed:** This is required to compile the C program.
2. **Create the WriteID.c file:** Copy the C code provided above into a file named **WriteID.c**.
3. **Create the RunCommand.bash file:** Copy the bash script provided above into a file named **RunCommand.bash**.

## Compilation and Execution

To compile and run the program using the provided bash script, follow these steps:

1. **Make the bash script executable:**
```
chmod +x RunCommand.bash
```

2. **Run the bash script:**
```
./RunCommand.bash
```

## Example Output

When the program runs, it will create a file named **process_ids.txt** containing the process ID and the parent process ID. The contents of the file will then be printed to the console.

```
Contents of process_ids.txt:
Process ID (PID): 12345
Parent Process ID (PPID): 6789
```
**Note: The actual process IDs will vary each time you run the program, as they are dynamically assigned by the operating system.**
