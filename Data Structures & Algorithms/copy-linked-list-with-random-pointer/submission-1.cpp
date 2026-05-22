/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        Node* tempHead = head;
        unordered_map<Node*, Node*> old_random_map;

        while (tempHead) {
            if (tempHead->random) 
                old_random_map[tempHead] = tempHead->random;
            else 
                old_random_map[tempHead] = nullptr;
            tempHead = tempHead->next;
        }

        unordered_map<Node*, Node*> new_to_old_map, old_to_new_map;
        Node* newHead = new Node(head->val);
        Node* tempNewHead = newHead;
        old_to_new_map[head] = newHead;
        new_to_old_map[newHead] = head;
        head = head->next;

        while (head) {
            Node* temp = new Node(head->val);
            new_to_old_map[temp] = head;
            old_to_new_map[head] = temp;
            tempNewHead->next = temp;
            head = head->next;
            tempNewHead = tempNewHead->next;
        }

        Node* finalTemp = newHead;

        while (finalTemp) {
            finalTemp->random = old_to_new_map[old_random_map[new_to_old_map[finalTemp]]];
            finalTemp = finalTemp->next;
        }

        return newHead;
    }   
};
