
#include <bits/stdc++.h>
using namespace std;

// Abstraction for document elements
class DocumentElement
{
public:
    virtual string render() = 0;
};

// Concrete implementation for text elements
class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

// Concrete implementation for image elements
class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    ImageElement(string imagePath)
    {
        this->imagePath = imagePath;
    }

    string render() override
    {
        return "[Image: " + imagePath + "]";
    }
};

// NewLineElement represents a line break in the document.
class NewLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

// TabSpaceElement represents a tab space in the document.
class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};


// Document class responsible for holding a collection of elements
class Document
{
private:
    vector<DocumentElement *> documentElements;

public:
    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    // Renders the document by concatenating the render output of all elements.
    string render()
    {
        string result;
        for (auto element : documentElements)
        {
            result += element->render();
        }
        return result;
    }
};


// Persistence abstraction
class Persistence
{
public:
    virtual void save(string data) = 0;
};

// FileStorage implementation of Persistence
class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

// Placeholder DBStorage implementation
class DBStorage : public Persistence
{
public:
    void save(string data) override
    {
        // Save to DB
        cout << "Document saved to database (simulated)." << endl;
    }
};


// DocumentEditor class managing client interactions
class DocumentEditor
{
private:
    Document *doc;
    Persistence *db;
    string renderedDocument;

public:
    DocumentEditor(Document *doc, Persistence *db)
    {
        this->doc = doc;
        this->db = db;
    }

    void addText(string text)
    {
        doc->addElement(new TextElement(text));
    }

    void addImage(string imagePath)
    {
        doc->addElement(new ImageElement(imagePath));
    }

    // Adds a new line to the document.
    void addNewLine()
    {
        doc->addElement(new NewLineElement());
    }

    // Adds a tab space to the document.
    void addTabSpace()
    {
        doc->addElement(new TabSpaceElement());
    }

    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = doc->render();
        }
        return renderedDocument;
    }

    void saveDocument()
    {
        db->save(renderDocument());
    }
};

// Client usage example
int main()
{
    Document *document = new Document();
    Persistence *persistence = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    return 0;
}