#include "Directory.hpp"
#include <algorithm>

Directory::Directory(const std::string& name, Node* parent):
    Node(name, NT_Directory, parent)
{}

Directory::Directory(const Directory& dir):
    Node(dir.m_name, NT_Directory, nullptr)
{
    //???
}

void Directory::addChild(Node* child) {
    if (child->getParent()==nullptr) {
        m_children.push_back(child);
        child->setParent(this);
    }
}

void Directory::removeChild(Node* child) {
    auto it = std::find (m_children.begin(), m_children.end(), child);
    if (it != m_children.end())
    {
        (*it)->setParent(nullptr);
        m_children.erase(it);
    }
}
