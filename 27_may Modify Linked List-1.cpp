struct Node* modifyTheList(struct Node *head)
    {

        Node* temp=head;
        vector<int> v;
        while(temp!=0){
            v.push_back(temp->data);
            temp=temp->next;
        }
        for(int i=0;i<v.size()/2;i++){
            v[i]=v[v.size()-1-i]-v[i];
            v[v.size()-1-i]-=v[i];
        }
        temp=head;
        int i=0;
        while(temp!=0){
            temp->data=v[i];
            temp=temp->next;i++;
        }
        return head;
    }
