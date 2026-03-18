#include <iostream>
#include <memory>

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