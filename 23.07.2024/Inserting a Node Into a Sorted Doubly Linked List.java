class Node {
    int data;
    Node next, prev;
    Node(int d) { data = d; }
}

public class InsertDoublyLinkedList {
    static Node sortedInsert(Node head, int data) {
        Node node = new Node(data);
        if (head == null) return node;
        if (data < head.data) {
            node.next = head;
            head.prev = node;
            return node;
        }
        Node current = head;
        while (current.next != null && current.next.data < data) current = current.next;
        node.next = current.next;
        if (current.next != null) current.next.prev = node;
        current.next = node;
        node.prev = current;
        return head;
    }
}
