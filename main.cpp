#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Note{
protected:
    string m_title;
public:
    Note(string title = "default"):m_title(title){

    }
    string getTitle()const{
        return m_title;
    }
    void setTitle(string title){
        m_title = title;
    }

    virtual ostream& getContent(ostream &out)const = 0;
     friend ostream& operator<<(ostream &out,const Note &nt){

         return nt.getContent(out);
    }

    virtual void setContent(string x,string y) = 0;
};
class TextNote final : public Note{
private:
    string m_content;
public:
    TextNote(string x = "default"): m_content(x){

    }
  virtual void setContent(string y, string x)override{
        m_content = x;
        m_title = y;
    }
   virtual ostream& getContent(ostream &out)const override{
       out << "This TextNote\ntitle: " << m_title << "\ncontent: " << m_content << endl;
       return out;
   }
};
class ListNote final : public Note{
    string L_content;
public:
    ListNote(string title, string lcontent):L_content(lcontent), Note(title){

    }
    virtual void setContent(string title, string list_content)override{
        m_title = title;
        L_content = list_content;
    }
    virtual ostream& getContent(ostream &out)const override{
        out  << m_title << ": " << L_content << endl;
        return out;
    }
};

class NoteDirector{
    vector<ListNote> notesList;
public:
    void addNote(string title, string content){
        notesList.emplace_back(title,content);
    }
    void addNote(){
    cout << "title: ";
    string title;
    getline(cin, title);
    cout << "content: ";
    string content;
    getline(cin,content);
    notesList.emplace_back(title,content);
    }


    void pop_back(){
        this->notesList.pop_back();
        notesList.shrink_to_fit();
    }
    void deleteNote(int i){
        this->notesList.erase(notesList.begin()+(i-1));
        notesList.shrink_to_fit();
    }
    void editNote(int i,string title, string content){
        notesList.at(i) = {title,content};
    }
    void clearNotesList(){
        notesList.clear();
    };
  void print(int i){
        cout << this->notesList[i];
    }
    void printAll(){
      for(const auto &num:notesList){
           cout << num;
      }
    }
};



int main(){

    NoteDirector a;
    a.addNote("SO0","Go study SO!");
    a.addNote("JiiP1","study JiiP!");
    a.addNote("Eng2","prepare Eng!");
    a.addNote("Python3","Learn it!");
    a.editNote(2,"Non-eng","don't study english");

    a.pop_back();
    a.printAll();
    a.deleteNote(1);

    a.clearNotesList();
    a.addNote();
    a.printAll();

    return 0;
}

