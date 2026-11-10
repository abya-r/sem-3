SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    
    if (head==nullptr)
    {
        head = new SinglyLinkedListNode(data);
        return head;
    }
    
    SinglyLinkedListNode *temp = head;
    while (temp->next!=nullptr)
    {
        temp = temp->next;
    }
    temp->next = new SinglyLinkedListNode(data);
    
    return head;
    
}