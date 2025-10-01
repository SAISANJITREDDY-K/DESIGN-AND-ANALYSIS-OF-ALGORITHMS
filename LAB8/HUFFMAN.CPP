#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    char c;
    int f;
    node *l, *r;
    node(char c, int f, node* l = nullptr, node* r = nullptr)
        : c(c), f(f), l(l), r(r) {}
};

struct compare {
    bool operator()(node* x, node* y) {
        return x->f > y->f;
    }
};

void print(node* root, const string& str) {
    if (!root) return;
    if (!root->l && !root->r)
        cout << root->c << ": " << str << "\n";
    print(root->l, str + "0");
    print(root->r, str + "1");
}

void huffman(const vector<char>& chars, const vector<int>& f) {
    priority_queue<node*, vector<node*>, compare> pq;
    int n = chars.size();

    for (int i = 0; i < n; ++i)
        pq.push(new node(chars[i], f[i]));

    while (pq.size() > 1) {
        node* l = pq.top(); pq.pop();
        node* r = pq.top(); pq.pop();

        node* internal = new node('$', l->f + r->f, l, r);
        pq.push(internal);
    }

    node* root = pq.top();
    print(root, "");
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<char> a(n);
    vector<int> f(n);

    cout << "Enter " << n << " characters (without spaces): ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Enter " << n << " frequencies (integer values): ";
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    cout << "Char | Huffman code\n";
    cout << "-------------------\n";
    huffman(a, f);

    return 0;
}
