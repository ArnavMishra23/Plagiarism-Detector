#ifndef FILE_IO_H
#define FILE_IO_H

/**
 * Reads a text file and returns its contents as a string
 * @param filename The name of the file to read
 * @return A dynamically allocated string containing the file contents
 */
char* read_file(const char* filename);

#endif // FILE_IO_H