//#ifndef DIRECTORY_H
//#define DIRECTORY_H

#pragma once
#include "Node.hpp"


class Directory : public Node {
public:
    Directory(const std::string& name, Node* parent = nullptr);
    Directory(const Directory& dir);
    ~Directory()=default;

    virtual void addChild(Node* child) override;
    virtual void removeChild(Node* child) override;

    protected:

    private:
};

//#endif // DIRECTORY_H
