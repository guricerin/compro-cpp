#include "../common.hpp"

/// 乱数を用いる平衡二分探索木
/// https://www.slideshare.net/iwiwi/2-12188757
/// キーをみると二分探索木、優先度をみると二分ヒープ
template <class Key>
struct Treap {
    struct Node {
        Key key;
        int priority;
        Node *left, *right;
        Node(Key k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
    };

    using Tree = Node*;
    Tree _root = nullptr;

    void split(Tree t, Key key, Tree& l, Tree& r) {
        if (!t) {
            l = r = nullptr;
        } else if (key < t->key) {
            split(t->left, key, l, t->left);
            r = t;
        } else {
            split(t->right, key, t->right, r);
            l = t;
        }
    }

    void merge(Tree& t, Tree l, Tree r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->right, l->right, r);
            t = l;
        } else {
            merge(r->left, l, r->left);
            t = r;
        }
    }

    void insert(Tree& t, Tree x) {
        if (!t) {
            t = x;
        } else if (x->priority > t->priority) {
            split(t, x->key, x->left, x->right);
            t = x;
        } else {
            insert(x->key < t->key ? t->left : t->right, x);
        }
    }

    void erase(Tree& t, Key key) {
        if (!t) return;
        if (t->key == key) {
            merge(t, t->left, t->right);
        } else {
            erase(key < t->key ? t->left : t->right, key);
        }
    }

    bool find(Tree& t, Key key) {
        if (!t) {
            return false;
        } else if (t->key == key) {
            return true;
        } else {
            return find(key < t->key ? t->left : t->right, key);
        }
    }

    static i32 xor128() {
        static uint32_t x = 123456789, y = 362436069, z = 521288629, w = time(0);
        uint32_t t = x ^ (x << 11);
        x          = y;
        y          = z;
        z          = w;
        w          = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w & 0x3FFFFFFF;
    }

    void insert(Key k) {
        insert(_root, new Node(k, xor128()));
    }

    void insert(Key k, i32 p) {
        insert(_root, new Node(k, p));
    }

    void erase(Key k) {
        erase(_root, k);
    }

    bool find(Key k) {
        return find(_root, k);
    }

    void dump_preorder(const Tree cur) {
        if (!cur) {
            return;
        }
        cout << " " << cur->key;   // 自身
        dump_preorder(cur->left);  // 左
        dump_preorder(cur->right); // 右
    }

    void dump_inorder(const Tree cur) {
        if (!cur) {
            return;
        }
        dump_inorder(cur->left);  // 左
        cout << " " << cur->key;  // 自身
        dump_inorder(cur->right); // 右
    }
};

// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/8/ALDS1_8_D
signed main() {
    int N;
    cin >> N;
    Treap<i32> tree;
    rep(i, 0, N) {
        string s;
        cin >> s;
        if (s == "insert") {
            i32 v, p;
            cin >> v >> p;
            tree.insert(v, p);
        } else if (s == "find") {
            i32 v;
            cin >> v;
            cout << (tree.find(v) ? "yes" : "no") << "\n";
        } else if (s == "delete") {
            i32 v;
            cin >> v;
            tree.erase(v);
        } else {
            tree.dump_inorder(tree._root);
            cout << "\n";
            tree.dump_preorder(tree._root);
            cout << "\n";
        }
    }
}
