#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define MAX_LVL 16

struct skip_node {
    struct skip_node** next;
    string value;
    int level;
    size_t key;
};
typedef struct skip_node skip_node;

typedef struct {
    skip_node* head;
    skip_node* NIL;
    int biggest_level;
} skip_list;

skip_node* set_node(skip_list* list, size_t a, string b, int level);
void insert(skip_list* list, size_t key, string value);
skip_node* search(skip_list* list, size_t key);
void erase(skip_list* list, size_t key);
int set_level(skip_list* list);
skip_list* set_list();

#endif