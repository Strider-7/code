#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
} *head = nullptr, *last = nullptr;

Node *insert(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    new_node->prev = nullptr;

    if (head == nullptr)
    {
        head = new_node;
        last = new_node;
    }
    else
    {
        head->prev = new_node;
        head = new_node;
    }
    return new_node;
}

void display(Node *node)
{
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int deleteNode(Node *node)
{
    int x = node->data;
    Node *p = node->prev;
    if (node == last)
    {
        last = node->prev;
        p->next = nullptr;
    }
    else
    {
        p->next = node->next;
        node->next->prev = p;
    }
    delete node;

    return x;
}
void displayMap(unordered_map<int, Node *> &map)
{
    for (auto &&i : map)
        cout << i.first << " ";
}

bool insertInCache(unordered_map<int, Node *> &map, int data, int size)
{
    auto itr = map.find(data);
    if (itr == map.end())
    {
        if (map.size() == size)
        {
            int x = deleteNode(last);
            map.erase(x);
        }
        map[data] = insert(data);
        // displayMap(map);
        return false;
    }
    else
    {
        Node *p = itr->second;
        deleteNode(p);
        map[data] = insert(data);
        // displayMap(map);
        return true;
    }
}

int main()
{
    int ch, x, size;
    vector<string> v;
    cout << "Enter cache size" << endl;
    cin >> size;
    unordered_map<int, Node *> map;

    while (true)
    {

        cout << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cout << endl;
        cout << "enter choice" << endl;

        cin >> ch;

        cout << endl;
        switch (ch)
        {
        case 1:
            cout << "enter the value to be inserted in cache" << endl;
            cin >> x;
            insertInCache(map, x, size) ? cout << " hit" << endl : cout << " miss" << endl;

            break;

        case 2:
            display(head);

            break;

        case 3:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}
