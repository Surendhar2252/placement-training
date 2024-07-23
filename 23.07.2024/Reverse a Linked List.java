class Node {
    int data;
    Node next;
    Node(int d) { data = d; next = null; }
}

public class ReverseLinkedList {
    static Node reverse(Node head) {
        Node prev = null;
        while (head != null) {
            Node next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
}
