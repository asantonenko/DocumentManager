#include "DocumentController.hpp"

DocumentController::DocumentController()
{
    //ctor
}


Document* DocumentController::createDocument(const std::string& name,  const std::string& color, Node*parent){
    Document* doc = new Document(name,color);
    parent->addChild(doc);
    return doc;
}

Document* DocumentController::move (Document* dc, Node* where){
    Node* parent = dc->getParent();
    bool hasParent = parent != nullptr;
    if (hasParent)
    {
        parent->removeChild(dc);
    } //else ???
    where->addChild(dc);
    return dc;
}

Document* DocumentController::copy (Document* dc, Node* where){
    Document * copyDoc = new Document(*dc);
    where->addChild(copyDoc);
    return copyDoc;
}

Document* DocumentController::rename (Document* dc, const std::string& name){
    dc->setName(name);
    return dc;
}

bool DocumentController::deleteDocument (Document* dc){
    Node* parent = dc->getParent();
    bool canDelete = (parent!=nullptr);
    if (canDelete)
    {
        parent->removeChild(dc);
    }
    return canDelete;
}

const std::string& DocumentController::read(Document* dc){
    return dc->getBody();
}

Document* DocumentController::write(Document* dc, const std::string& body){
    dc->setBody(body);
    return dc;
}

Document* DocumentController::append(Document* dc, const std::string& body){
    dc->appendBody(body);
    return dc;
}

Document* DocumentController::changeColor(Document* dc, const std::string& color){
    dc->setColor(color);
    return dc;
}
