
#include<bits/stdc++.h>
using namespace std;

class DocumentEditor
{
private:
    vector<string> documentElements;
    string renderedDocuments;

public:
    // add text as a plain string
    void addText(string text){
        documentElements.push_back(text);
    }

    // adds an image represented by its file path
    void addImage(string imagePath){
        documentElements.push_back(imagePath);
    }

    // reders the document by checking the type of each element at runtime
    string renderDocument()
    {
        if(renderedDocuments.empty())
        {
            string result;
            for(auto element:documentElements)
            {
                if(element.size()>4 && (element.substr(element.size()-4)==".jpg" || element.substr(element.size()-4)==".png")){
                    result += "[Image: " + element + "]" + "\n";
                }else{
                    result += element + "\n";
                }
            }
            renderedDocuments = result;
        }

        return renderedDocuments;
    }


    void saveToFile()
    {
        ofstream file("document.txt");
        if(file.is_open())
        {
            file << renderDocument();
            file.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing" << endl;
        }
    }
};



int main()
{
    DocumentEditor editor;
    editor.addText("Hello, world!");
    editor.addImage("image1.jpg");
    editor.addText("This is a sample document.");

    cout << editor.renderDocument() << endl;
    editor.saveToFile();
    return 0;
}


