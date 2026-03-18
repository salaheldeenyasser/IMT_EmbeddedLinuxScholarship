#include <iostream>
#include <memory>

/*
** Factory Method Pattern
** Definition: Defines an interface for creating an object, but lets subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.
** Key Concepts:
- Product: The interface or abstract class that defines the type of object the factory method creates.
- Concrete Product: The specific implementation of the Product interface that the factory method creates.
- Creator: The class that declares the factory method, which returns an object of type Product.
- Concrete Creator: The subclass of Creator that implements the factory method to create and return an instance of a Concrete Product.
** Benefits:
- Encapsulation: The Factory Method pattern encapsulates the object creation process, allowing for more flexible and maintainable code.
- Decoupling: It decouples the client code from the specific classes that need to be instantiated, making it easier to change the implementation without affecting the client.
- Extensibility: New product types can be added without modifying existing code, adhering to the Open/Closed Principle.
** Example: A document editor application that supports multiple document formats (PDF, Word,
*/

class IDocument
{
public:
    virtual void render() = 0;
    virtual ~IDocument() = default;
};

class PDFDocument : public IDocument
{
public:
    void render() override
    {
        std::cout << "Rendering PDF" << std::endl;
    }
};

class WordDocument : public IDocument
{
public:
    void render() override
    {
        std::cout << "Rendering Word Document" << std::endl;
    }
};

class HTMLDocument : public IDocument
{
public:
    void render() override
    {
        std::cout << "Rendering HTML Document" << std::endl;
    }
};

class DocumentCreator
{
public:
    virtual std::unique_ptr<IDocument> createDocument() = 0;
    virtual ~DocumentCreator() = default;

    void renderDocument()
    {
        auto document = createDocument();
        if (document)
        {
            document->render();
        }
        else
        {
            std::cout << "Unknown document type " << std::endl;
        }
    }
};

class PDFDocumentCreator : public DocumentCreator
{
public:
    std::unique_ptr<IDocument> createDocument() override
    {
        return std::make_unique<PDFDocument>();
    }
};

class WordDocumentCreator : public DocumentCreator
{
public:
    std::unique_ptr<IDocument> createDocument() override
    {
        return std::make_unique<WordDocument>();
    }
};

class HTMLDocumentCreator : public DocumentCreator
{
public:
    std::unique_ptr<IDocument> createDocument() override
    {
        return std::make_unique<HTMLDocument>();
    }
};

class MarkdownDocument : public IDocument
{
public:
    void render() override
    {
        std::cout << "Rendering Markdown Document" << std::endl;
    }
};

class MarkdownDocumentCreator : public DocumentCreator
{
public:
    std::unique_ptr<IDocument> createDocument() override
    {
        return std::make_unique<MarkdownDocument>();
    }
};

int main()
{
    PDFDocumentCreator pdfCreator;
    WordDocumentCreator wordCreator;
    HTMLDocumentCreator htmlCreator;
    MarkdownDocumentCreator markdownCreator;

    pdfCreator.renderDocument();
    wordCreator.renderDocument();
    htmlCreator.renderDocument();
    markdownCreator.renderDocument();

    return 0;
}