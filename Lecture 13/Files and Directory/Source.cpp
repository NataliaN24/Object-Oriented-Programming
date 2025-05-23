#include <iostream>
#include <stdexcept>
#include <cstring>
#include"Directory.h"
#include"File.h"
#include"TextFile.h"

int main() {
    Directory* root = new Directory("root");
    Directory* folder1 = new Directory("Folder1");
    Directory* folder2 = new Directory("Folder2");

    folder1->addFile(new TextFile("file1.txt", "Hello from file1"));
    folder1->addFile(new TextFile("file2.txt", "Contents of file2"));

    folder2->addFile(new TextFile("file3.txt", "Third file here"));

    root->addFile(folder1);
    root->addFile(folder2);

    root->printContent();

    delete root;
    return 0;
}
