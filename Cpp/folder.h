#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <string>
#include <set>

class Folder;
class Message {
    friend void swap(Message&, Message&);
    friend class Folder;

public:
    explicit Message(const std::string &str = ""):
        contents(str) { }
    Message(const Message &);
    Message& operator=(const Message &);
    ~Message();
    Message(Message&&);
    Message& operator=(Message&&);
    void save(Folder&);
    void remove(Folder&);
    void debug_print();
private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void move_Folders(Message*);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend class Message;
public:
    ~Folder();
    Folder(const Folder&);
    Folder& operator=(const Folder&);

    Folder(Folder&&);
    Folder& operator=(Folder&&);

    Folder() = default;
    void save(Message&);
    void remove(Message&);
    void debug_print();
private:
    std::set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Msgs();
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void move_Messages(Folder*);
};

#endif
