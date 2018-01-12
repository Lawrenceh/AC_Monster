/* solution 1: pre-order recursive solution (using STRINGSTREAM) */
/* solution 2: (not written) level order traversal */

class Codec {
private:
    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }
    
    TreeNode* deserialize(istringstream &in) {
        string s;
        in >> s;
        if (s == "#") return nullptr;
        TreeNode *node = new TreeNode(stoi(s));
        node->left = deserialize(in);
        node->right = deserialize(in);
        return node;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
