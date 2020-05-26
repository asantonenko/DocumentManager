#pragma once
#include<string>
#include "Node.hpp"

class DirectoryController
{
    public:
        /** Default constructor */
        DirectoryController();

        DirectoryController(Node* rootDir);

        Node* getRoot() const;

        Node* createDirectory(const std::string& name, Node *parent);
        bool removeDirectory(Node* dir);
        Node* renameDirectory(Node* dir, const std::string& name);
        Node* moveDirectory(Node* dir, Node* where);
        Node* copyDirectory(Node* dir, Node* where);

    protected:

    private:
        Node* m_root;
};
