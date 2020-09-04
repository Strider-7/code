#include <bits/stdc++.h>
using namespace std;

int SIZE = 0;

bool insert(list<int> &l, unordered_map<int, int> &map, int data)
{
    if (map.find(data) == map.end())
    {
        if (l.size() == SIZE)
        {
            int temp = l.back();
            map.erase(temp);
            l.pop_back();
        }

        map[data]++;

        l.push_front(data);
        return false;
    }
    else
    {
        l.remove(data);
        l.push_front(data);
        return true;
    }
}

int main()
{

    int ch, x;
    vector<string> v;
    cout << "Enter cache size" << endl;
    cin >> SIZE;
    list<int> l;
    unordered_map<int, int> map;
    list<int>::iterator it;
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
            if (insert(l, map, x))
            {
                //    cout << "hit" << endl;
                v.push_back("hit");
            }
            else
            {
                // cout << "miss" << endl;
                v.push_back("miss");
            }
            break;

        case 2:

            for (it = l.begin(); it != l.end(); ++it)
                cout << '\t' << *it;
            cout << '\n';
            break;

        case 3:
            for (auto &&i : v)
            {
                cout << i << " ";
            }

            exit(0);
            break;

        default:
            break;
        }
    }
}