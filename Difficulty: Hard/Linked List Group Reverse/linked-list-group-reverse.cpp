/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/


class Solution {
public:
    Node* getkthnode(Node* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    Node* reverse(Node* temp){
        Node* t = temp;
        Node* pre = NULL;
        while(t!=NULL){
            Node* front = t->next;
            t->next = pre;
            pre = t;
            t =front;
        }
        return pre;
    }
    Node* reverseKGroup(Node* head, int k) {
        Node* temp = head;
        Node* nextnode = NULL;
        Node* prevnode = NULL;
        while(temp!=NULL){
            Node* kthnode = getkthnode(temp,k);
            // if(kthnode == NULL){
            //     if(prevnode){
            //         prevnode->next = temp;
            //     }
            //     break;
            // }
            if(kthnode == NULL){
            Node* reversedHead = reverse(temp);
            if(prevnode){
                prevnode->next = reversedHead;
            }
            else{
                head = reversedHead;
            }
            break;
            }
            nextnode = kthnode->next;
            kthnode->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kthnode;
            }
            else{
                prevnode->next = kthnode;
            }
            prevnode= temp;
            temp = nextnode;
            
            

        }
        return head;
    }
};