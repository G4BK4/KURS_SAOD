#include "foo.h"

skip_node* set_node(skip_list* list, size_t a, string b, int level)
{
    skip_node* node = new skip_node;
    if (node) {
        node->key = a, node->value = b, node->level = level;
        node->next = new skip_node*[level];
        for (int i = 0; i < level; ++i)
            node->next[i] = list->NIL;
    }
    return node;
}

skip_list* set_list()
{
    skip_list* list = new skip_list;
    if (list) {
        list->biggest_level = 1;
        list->NIL = set_node(list, -1, "NIL", MAX_LVL);
        list->head = set_node(list, -2, "head", MAX_LVL);
        for (long unsigned int i = 0; i < MAX_LVL; ++i)
            list->head->next[i] = list->NIL;
    }
    return list;
}

int set_level(skip_list* list)
{
    srand(time(0));
    double chances = 100.0;
    double occasion = rand() % 100 + 0;
    int i;
    for (i = 1; i < MAX_LVL; ++i) {
        chances /= 2;
        if (occasion > chances) {
            return i;
        }
    }
    return i;
}

void update_connections(skip_list* list, skip_node* last_node)
{
    skip_node* node = list->head;
    for (int i = last_node->level - 1; i >= 0; --i) {
        if (node->next[i] == list->NIL) {
            last_node->next[i] = list->NIL;
            node->next[i] = last_node;
        } else {
            skip_node* temp = list->head;
            while (temp->next[i]->key < last_node->key && temp->next[i] != list->NIL) {
                temp = temp->next[i];
            }
            last_node->next[i] = temp->next[i];
            temp->next[i] = last_node;
        }
    }
}

skip_node* search(skip_list* list, size_t key)
{
    skip_node* prev = list->head;
    int i = list->biggest_level;
    while (prev->next[0] != list->NIL) {
        if (prev->next[i]->key > key || prev->next[i] == list->NIL) {
            --i;
            if (i < 0) {
                ++i;
                break;
            }
        } else {
            prev = prev->next[i];
        }
    }
    if (prev->key == key) {
        return prev;
    } else {
        return list->NIL;
    }
}

void insert(skip_list* list, size_t key, string value)
{
    if (list) {
        if (search(list, key) != list->NIL) {
            cout << "ERROR: ELEMENT WITH THIS KEY ALREADY EXISTS." << endl;
            return;
        }
        skip_node* new_node = set_node(list, key, value, set_level(list));
        if (new_node) {
            if (new_node->level > list->biggest_level)
                list->biggest_level = new_node->level;
            update_connections(list, new_node);
        }
    }
}

void search_new_biggest_level(skip_list* list)
{
    skip_node* ptr = list->head;
    list->biggest_level = 1;
    while (ptr->next[0] != list->NIL) {
        if (list->biggest_level < ptr->next[0]->level)
            list->biggest_level = ptr->next[0]->level;
        ptr = ptr->next[0];
    }
}

void erase(skip_list* list, size_t key)
{
    if (list) {
        skip_node* target = search(list, key);
        if (target == list->NIL) {
            cout << "ERROR: ELEMENT WITH THIS KEY DOESN't EXISTS." << endl;
            return;
        }
        skip_node* node = list->head;
        for (int i = target->level - 1; i >= 0; --i) {
            node = list->head;
            while (node->next[i] != target) {
                node = node->next[i];
            }
            node->next[i] = node->next[i]->next[i];
        }
        delete target;
    }
}
