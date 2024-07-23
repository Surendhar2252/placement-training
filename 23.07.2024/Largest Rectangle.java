import java.util.Scanner;
import java.util.Stack;

public class LargestRectangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) heights[i] = sc.nextInt();
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0, i = 0;
        while (i < n) {
            if (stack.isEmpty() || heights[i] >= heights[stack.peek()]) stack.push(i++);
            else maxArea = Math.max(maxArea, heights[stack.pop()] * (stack.isEmpty() ? i : i - stack.peek() - 1));
        }
        while (!stack.isEmpty()) maxArea = Math.max(maxArea, heights[stack.pop()] * (stack.isEmpty() ? i : i - stack.peek() - 1));
        System.out.println(maxArea);
    }
}
