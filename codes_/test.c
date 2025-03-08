#include <stdio.h>
#include <windows.h>

int main(void) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Initialize the memory for the STARTUPINFO and PROCESS_INFORMATION structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Command to launch MS Paint
    const char* command = "C:\\WINDOWS\\system32\\";

    // Attempt to create the child process
    if (!CreateProcess(
            NULL,       // No module name (use command line)
            (LPSTR)command, // Command line (needs to be cast to LPSTR)
            NULL,       // Process handle not inheritable
            NULL,       // Thread handle not inheritable
            FALSE,      // Set handle inheritance to FALSE
            0,          // No creation flags
            NULL,       // Use parent's environment block
            NULL,       // Use parent's starting directory
            &si,        // Pointer to STARTUPINFO structure
            &pi)) {     // Pointer to PROCESS_INFORMATION structure
        
        // If CreateProcess fails, print error message with error code
        DWORD error = GetLastError();
        fprintf(stderr, "CreateProcess failed with error code %ld\n", error);
        return -1;
    }

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Print success message after the process completes
    printf("Child process completed successfully.\n");

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
