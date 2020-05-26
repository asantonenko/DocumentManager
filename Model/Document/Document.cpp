#include "Document.hpp"
#include <iostream>

Document::Document(const std::string& name, const std::string& color, Node* parent):
    Node(name, NT_Document, parent), m_color(color)
{}

Document::Document(const Document& doc):
    Node(doc.m_name, NT_Document, nullptr), m_color(doc.m_color), m_body (doc.m_body)
{}

Document::~Document()
{
    std::cout <<"Document " <<m_name <<" destroyed!" <<std::endl;
}

const std::string& Document::getBody()const{
    return m_body;
}
void Document::setBody(const std::string& body){
    m_body = body;
}

void Document::appendBody(const std::string& body){
    m_body += body;
}

const std::string& Document::getColor()const{
    return m_color;
}
void Document::setColor(const std::string& color){
    m_color = color;
}


void Document::addChild(Node* child) {
    throw 111; //???
}

void Document::removeChild(Node* child) {
    throw 111; //???
}
