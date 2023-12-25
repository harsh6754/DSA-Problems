void DeleteAtHead(Node* &head,int d) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}