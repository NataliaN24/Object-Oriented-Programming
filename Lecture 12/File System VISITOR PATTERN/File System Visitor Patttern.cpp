#include <iostream>
#include <string>

class FileSystemEntityVisitor;

class FileSystemEntity {
    std::string name;
public:
    FileSystemEntity(std::string name) : name(name) {}
    const std::string& getName() const {
        return name;
    }

    virtual void accept(FileSystemEntityVisitor* visitor) = 0;

    virtual ~FileSystemEntity() = 0;
};
FileSystemEntity::~FileSystemEntity() {}

class File : public FileSystemEntity {
public:
    File(std::string name) : FileSystemEntity(name) {}

    void accept(FileSystemEntityVisitor* visitor) override {
        visitor->visitFile(this);
    }
};

class Directory : public FileSystemEntity {
public:
    FileSystemEntity** children;
    size_t size;

    Directory(std::string name) : FileSystemEntity(name), children(nullptr), size(0) {}

    void accept(FileSystemEntityVisitor* visitor) override {
        visitor->visitDirectory(this);
    }
};

class FileSystemEntityVisitor {
public:
    void visitFile(File* f) {
        std::cout << f->getName();
    }

    void visitDirectory(Directory* d) {
        std::cout << d->getName();

        for (size_t i = 0; i < d->size; i++) {
            d->children[i]->accept(this);
        }
    }
};

int main() {
    File file1("File1.txt");
    File file2("File2.txt");
    File file3("File3.txt");

    Directory dir1("Directory1");
    dir1.children = new FileSystemEntity * [2];
    dir1.children[0] = &file1;
    dir1.children[1] = &file2;
    dir1.size = 2;

    Directory root("RootDirectory");
    root.children = new FileSystemEntity * [2];
    root.children[0] = &dir1;
    root.children[1] = &file3;
    root.size = 2;

    FileSystemEntityVisitor visitor;
    root.accept(&visitor);

    delete[] dir1.children;
    delete[] root.children;

    return 0;
}
