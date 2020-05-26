#pragma once
#include <string>
#include "Document.hpp"

class DocumentController
{
    public:
        /** Default constructor */
        DocumentController();

        Document* createDocument(const std::string& name,  const std::string& color, Node*parent);
        Document* move (Document* dc, Node* where);
        Document* copy (Document* dc, Node* where);
        Document* rename (Document* dc, const std::string& name);
        bool deleteDocument (Document* dc);
        const std::string& read(Document* dc);
        Document* write(Document* dc, const std::string& body);
        Document* append(Document* dc, const std::string& body);
        Document* changeColor(Document* dc, const std::string& color);

    protected:

    private:
};
