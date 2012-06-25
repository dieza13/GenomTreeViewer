#ifndef FILETEXTREADER_H
#define FILETEXTREADER_H
#include <iostream>
#include <fstream>
#include <string>


class FileTextReader
{
public:
    FileTextReader();
    void readFile(const char *path);
};

#endif // FILETEXTREADER_H
