#include "../common.hpp"

struct Node {
    i64 val;
    Node *p, *l, *r;
    Node() {}
    Node(i64 v) : val(v), p(nullptr), l(nullptr), r(nullptr) {}
};

/// 二分探索木（平衡ではないので、最悪計算量はO(n)）
struct BinarySearchTree {
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(i64 val) {
        auto cur = root;
        Node* p = nullptr;
        Node* x = new Node(val);
        while (cur) {
            p = cur;
            if (x->val < cur->val) {
                cur = cur->l; // 左に移動
            } else {
                cur = cur->r; // 右に移動
            }
        }
        x->p = p;

        if (!p) {
            root = x;
        } else if (x->val < p->val) {
            p->l = x;
        } else {
            p->r = x;
        }
    }

    Node* find(i64 val) {
        auto cur = root;
        while (cur) {
            if (cur->val == val)
                break;
            else if (val < cur->val)
                cur = cur->l;
            else
                cur = cur->r;
        }
        return cur;
    }

    Node* next_node(Node* cur) {
        if (!cur->l)
            return cur;
        else
            return next_node(cur->l);
    }

    void replace(Node* n, Node* m) {
        auto p = n->p;
        if (m) m->p = p;
        if (n == root) {
            root = m;
        } else if (p->l == n) {
            p->l = m;
        } else {
            p->r = m;
        }
        delete n;
    }

    bool erase(i64 val) {
        auto n = find(val);
        if (!n) return false;

        if (!n->r) { // 左がいて右がいない
            replace(n, n->l);
        } else if (!n->l) { // 右がいて左がいない
            replace(n, n->r);
        } else { // 両方いる場合は、右部分木の左端のノードをnの位置にもってくる
            // 元いたやつの親と子の辺を繋ぎかえる
            auto cand = next_node(n->r);
            n->val = cand->val;
            replace(cand, cand->r);
        }
        return true;
    }

    void dump_preorder(const Node* cur) const {
        if (!cur) {
            return;
        }
        cout << " " << cur->val; // 自身
        dump_preorder(cur->l);   // 左
        dump_preorder(cur->r);   // 右
    }

    /// 先行順巡回（dfs）
    void dump_preorder() const {
        dump_preorder(root);
    }

    void dump_inorder(const Node* cur) const {
        if (!cur) {
            return;
        }
        dump_inorder(cur->l);    // 左
        cout << " " << cur->val; // 自身
        dump_inorder(cur->r);    // 右
    }

    /// 中間順巡回（dfs）
    void dump_inorder() const {
        dump_inorder(root);
    }
};

/// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/8/ALDS1_8_C
signed main() {
    int N;
    cin >> N;
    auto tree = BinarySearchTree();
    rep(i, 0, N) {
        string s;
        cin >> s;
        if (s == "insert") {
            i64 v;
            cin >> v;
            tree.insert(v);
        } else if (s == "find") {
            i64 v;
            cin >> v;
            cout << (tree.find(v) ? "yes" : "no") << "\n";
        } else if (s == "delete") {
            i64 v;
            cin >> v;
            tree.erase(v);
        } else {
            tree.dump_inorder();
            cout << "\n";
            tree.dump_preorder();
            cout << "\n";
        }
    }
}
