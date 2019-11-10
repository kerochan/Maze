template <typename T>
struct Node{
    T val;
    Node* parent;

    Node(const T& _val){
        val = _val;
        parent = this;
    }

       
    bool operator==(const Node<T>& n) const{
        return (this->val == n.val) && (this->parent == n.parent);
    }
  
    bool operator!=(const Node<T>& n) const{
        return (this->val != n.val) || (this->parent != n.parent);
    }
};