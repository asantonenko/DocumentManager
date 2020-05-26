#include "DirectoryController.hpp"
#include "Directory.hpp"

DirectoryController::DirectoryController()
    : m_root(nullptr)
{}

DirectoryController::DirectoryController(Node* rootDir)
    : m_root(rootDir)
{}

Node* DirectoryController::getRoot() const{
    return m_root;
}

Node* DirectoryController::createDirectory(const std::string& name, Node *parent){
    Directory * newdir = new Directory(name);
    parent->addChild(newdir);
    return newdir;
}

bool DirectoryController::removeDirectory(Node* dir){
    Node* parent = dir->getParent();
    bool canRemove = (parent!=nullptr);
    if (canRemove)
    {
        parent->removeChild(dir);
    }
    return canRemove;
}

Node* DirectoryController::renameDirectory(Node* dir, const std::string& name){
    dir->setName(name);
    return dir;
}

Node* DirectoryController::moveDirectory(Node* dir, Node* where){
    Node* parent = dir->getParent();
    bool hasParent = parent != nullptr;
    if (hasParent)
    {
        parent->removeChild(dir);
    }
    where->addChild(dir);
    return dir;
}

Node* DirectoryController::copyDirectory(Node* dir, Node* where){
    Directory * copyDir = new Directory(*dynamic_cast<Directory*>(dir));
    where->addChild(copyDir);
    return copyDir;
}
