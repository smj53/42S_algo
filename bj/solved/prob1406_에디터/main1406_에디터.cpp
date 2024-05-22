#include <iostream>
#include <algorithm>
using namespace std;

// class Node {
//     public:
//     Node *p, *n;
//     char v;

//     Node(char c) : Node(c, 0, 0) {}

//     Node (char c, Node *prev, Node *next) {
//         v = c;
//         p = prev;
//         n = next;
//     }

//     static Node *createNode(char c, Node *p, Node *n) {
//         return (new Node(c, p, n));
//     }
// }

// class List {
//     public:
//     Node *h, *t;
//     Node *c;
//     int size;

//     List() {
//         h = t = c = 0;
//         size = 0;
//     }

//     int empty() {
//         return (size == 0);
//     }

//     void insert_left() {

//     }
// }

// int main(void) {
//     cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//     int M;
//     char op, t;
//     string s;
//     list<char> l;
//     list<char>::iterator cursor, tmp;
//     cin >> s;
//     for(int i=0; i<s.length(); i++) {
//         l.push_back(s[i]);
//     }
//     cursor = l.end();
//     cin >> M;
//     while (M--) {
//         cin >> op;
//         switch (op) {
//             case 'L':
//                 tmp = l.begin();
//                 if (!l.empty() && cursor != ++tmp)
//                     cursor--;
//             break;
//             case 'D':
//                 if (cursor != l.end())
//                     cursor++;
//             break;
//             case 'B':
//                 tmp = l.begin();
//                 if (!l.empty() && cursor != ++tmp)
//                     cursor = l.erase(cursor);
//             break;
//             case 'P':
//                 cin >> t;
//                 l.insert(cursor, t);
//             break;
//         }
//     }
//     for(auto i=l.begin(); i!=l.end(); i++) {
//         cout << *i;
//     }
// }
#include <list>
int main(void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int M;
    char op, t;
    string s;
    list<char> l;
    list<char>::iterator cursor, tmp;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        l.push_back(s[i]);
    }
    cursor = l.end();
    cin >> M;
    while (M--) {
        cin >> op;
        switch (op) {
            case 'L':
                if (cursor != l.begin())
                    cursor--;
            break;
            case 'D':
                if (cursor != l.end())
                    cursor++;
            break;
            case 'B':
                if (cursor != l.begin() && !l.empty())
                    cursor = l.erase(--cursor);
            break;
            case 'P':
                cin >> t;
                cursor = l.insert(cursor, t);
                cursor++;
            break;
        }
        // cout << "=========="<< op <<"=========" << endl;
        // if (cursor != l.end())
        //     cout << "cursor: " << *cursor << endl;
        // for(auto i=l.begin(); i!=l.end(); i++) {
        // cout << *i;
        // }
        // cout<<endl;
    }
    for(auto i=l.begin(); i!=l.end(); i++) {
        cout << *i;
    }
}