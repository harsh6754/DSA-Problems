import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class VisibleBuildings {
    public static List<Integer> findVisibleBuildings(List<Integer> heights) {
        List<Integer> visibleBuildings = new ArrayList<>();
        int maxHeight = 0;

        for (int i = 0; i < heights.size(); ++i) {
            if (heights.get(i) > maxHeight) {
                visibleBuildings.add(i);
                maxHeight = heights.get(i);
            }
        }

        return visibleBuildings;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the building heights separated by commas (e.g., 1,2,3):");
        String input = scanner.nextLine();
        String[] heightStrings = input.split(",");
        List<Integer> heights = new ArrayList<>();

        for (String heightStr : heightStrings) {
            try {
                int height = Integer.parseInt(heightStr.trim());
                heights.add(height);
            } catch (NumberFormatException e) {
                System.out.println("Please enter valid integer input for all building heights.");
                return;
            }
        }

        List<Integer> visibleBuildings = findVisibleBuildings(heights);

        System.out.print("[");
        for (int i = 0; i < visibleBuildings.size(); ++i) {
            System.out.print(visibleBuildings.get(i));
            if (i < visibleBuildings.size() - 1)
                System.out.print(", ");
        }
        System.out.println("]");
    }
}
