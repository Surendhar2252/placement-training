import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Node {
    Map<Character, Node> children = new HashMap<>();
    int size = 0;
}

public class Contacts {
    private static void add(Node root, String s) {
        Node current = root;
        for (char c : s.toCharArray()) {
            current = current.children.computeIfAbsent(c, k -> new Node());
            current.size++;
        }
    }

    private static int find(Node root, String s) {
        Node current = root;
        for (char c : s.toCharArray()) {
            if (!current.children.containsKey(c)) return 0;
            current = current.children.get(c);
        }
        return current.size;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = new Node();
        for (int i = 0; i < n; i++) {
            String op = sc.next();
            String contact = sc.next();
            if (op.equals("add")) add(root, contact);
            else System.out.println(find(root, contact));
        }
    }
}
