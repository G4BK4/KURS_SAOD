#include "foo.h"

void info()
{
    cout << "+----------------+" << endl;
    cout << "| Enter num for: |" << endl;
    cout << "| 1) Quit        |" << endl;
    cout << "| 2) Insert      |" << endl;
    cout << "| 3) Search      |" << endl;
    cout << "| 4) Erase       |" << endl;
    cout << "| 5) Print level |" << endl;
    cout << "+----------------+" << endl;
}
int main()
{
    int key = 0;
    string value;
    skip_list* list = set_list();
    string str;
    info();
    while (true) {
        cout << "> ";
        cin >> str;
        if (str == "1") {
            return 0;
        } else if (str == "2") {
            cout << "Enter key for add" << endl;
            cout << "> ";
            cin >> key;
            cout << "Enter value" << endl;
            cout << "> ";
            cin >> value;
            insert(list, key, std::to_string(key));
        } else if (str == "3") {
            cout << "Enter key for search" << endl;
            cout << "> ";
            cin >> key;
            cout << search(list, key)->value << endl;
        } else if (str == "4") {
            cout << "Enter key for erase" << endl;
            cout << "> ";
            cin >> key;
            erase(list, key);
        } else if (str == "5") {
            cout << "Enter level" << endl;
            cout << "> ";
            cin >> key;
            key -= 1;
            skip_node* i = list->head;
            while (i->next[key] != list->NIL) {
                cout << "lvl: " << i->next[key]->level << " key: " << i->next[key]->key << " value: " << i->next[key]->value << endl;
                i = i->next[key];
            }
        }
    }
    return 0;
}