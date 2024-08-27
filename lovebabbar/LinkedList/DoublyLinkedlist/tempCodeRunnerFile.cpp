void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";  // Separator between nodes
        }
        temp = temp->next;
    }
    cout << endl;
}
