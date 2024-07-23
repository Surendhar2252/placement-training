import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FrequencyQueries {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        Map<Integer, Integer> freq = new HashMap<>();
        Map<Integer, Integer> count = new HashMap<>();
        while (q-- > 0) {
            int op = sc.nextInt(), x = sc.nextInt();
            if (op == 1) {
                int oldFreq = freq.getOrDefault(x, 0);
                freq.put(x, oldFreq + 1);
                count.put(oldFreq, count.getOrDefault(oldFreq, 0) - 1);
                count.put(oldFreq + 1, count.getOrDefault(oldFreq + 1, 0) + 1);
            } else if (op == 2) {
                int oldFreq = freq.getOrDefault(x, 0);
                if (oldFreq > 0) {
                    freq.put(x, oldFreq - 1);
                    count.put(oldFreq, count.getOrDefault(oldFreq, 0) - 1);
                    count.put(oldFreq - 1, count.getOrDefault(oldFreq - 1, 0) + 1);
                }
            } else {
                System.out.println(count.getOrDefault(x, 0) > 0 ? 1 : 0);
            }
        }
    }
}
