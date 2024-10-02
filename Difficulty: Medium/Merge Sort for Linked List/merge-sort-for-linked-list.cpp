//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
    private:
    Node* getMid(Node* head){
        if(head==nullptr){
            return head;
            
        }
        Node* slow= head;
        Node* fast= head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast= fast->next->next;
            
        }
        return slow;
    }
    Node* merge(Node* left, Node* right){
        if(left==nullptr){
            return right;
        }
        if(right==nullptr){
            return left;
        }
        Node* dummy= new Node(-1);
        Node* temp= dummy;
        while(left and right){
            if(left->data<right->data){
               temp->next= left;
               temp= left;
               left= left->next;
            }
            else{
                temp->next= right;
                temp= right;
                right= right->next;
            }
        }
        while(left ){
            temp->next= left;
            temp= left;
            left= left->next;
        }
        while(right){
            temp->next= right;
            temp= right;
            right=right->next;
        }
        dummy = dummy->next;
        return dummy;
    }
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head==nullptr or head->next==nullptr){
            return head;
            
        }
        Node* mid= getMid(head);
        Node* left= head;
        Node* right= mid->next;
        mid->next= nullptr;
        left= mergeSort(left);
        right= mergeSort(right);
        //merge
        Node* ans= merge(left, right);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends