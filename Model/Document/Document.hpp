#pragma once
#include "Node.hpp"
#include <string>


class Document : public Node
{
    public:
        Document(const std::string& name, const std::string& color, Node* parent = nullptr);
        ~Document(); //=default;

        Document(const Document& doc);

        const std::string& getBody()const;
        void setBody(const std::string& body);
        void appendBody(const std::string& body);

        const std::string& getColor()const;
        void setColor(const std::string& color);

        virtual void addChild(Node* child) override;
        virtual void removeChild(Node* child) override;


    protected:

    private:
        std::string m_color;
        std::string m_body;

};
