#include<vector>
#include<map>
#include<memory>
#include<iostream>
#include<exception>
#include<utility>
#include<iostream>
#include<algorithm>
#include "Tree.cpp"

template<typename T>
class DisjointSet{

public:
    static Node<T>* MakeSet(const T& val){
        return (new Node<T>(val));
    }

    static Node<T>& Find(Node<T>& node){
        if(node.parent == &node)
            return node;
        else
            return Find(*node.parent);
    }

    static void UnionLeader(Node<T>& node1, Node<T>& node2){
        Node<T>& root1 = Find(node1);
        Node<T>& root2 = Find(node2);
        if(root1 != root2){
            root2.parent = &node1;
        }   
    }

    static void Union(Node<T>& node1, Node<T>& node2){
        if(node1.parent == &node1 && node2.parent == &node2){
            if(node1 == node2){
                return;
            }else{
                node1.parent = &node2;
                return;
            }
        }else{
            if(node1.parent == &node1 && node2.parent != &node2){
                if(node1 == Find(node2)){
                    return;
                }else{
                    node1.parent = &node2;
                    return;
                }
                
            }else if(node1.parent != &node1 && node2.parent == &node2){
                if(node2 == Find(node1)){
                    return;
                }else{
                    node2.parent = &node1;
                    return;
                }
            }else{
                 if(Find(node1) == Find(node2)){
                    return;
                }else{
                    Node<T>* temp_parent = node2.parent;
                    node2.parent = &node1;
                    Union(node2, *temp_parent);
                    return;
                }
            }
        } 
    }
};

