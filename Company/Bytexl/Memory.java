import java.util.Scanner;

public class Memory {

    public static boolean isPowerOfTwo(int x) {
        return x != 0 && (x & (x - 1)) == 0;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter page size in KB: ");
        int pageSizeKB = scanner.nextInt();

        System.out.print("Enter physical memory size in KB: ");
        int physicalMemoryKB = scanner.nextInt();

        System.out.print("Enter address space bits: ");
        int addressSpaceBits = scanner.nextInt();

        if (!isPowerOfTwo(pageSizeKB) || !isPowerOfTwo(physicalMemoryKB)) {
            System.out.println("Both page size and physical memory size must be powers of two.");
            return;
        }

        int pageSizeBits = (int) (Math.log(pageSizeKB * 1024) / Math.log(2));
        int physicalMemoryBits = (int) (Math.log(physicalMemoryKB * 1024) / Math.log(2));
        int pageTableIndexBits = addressSpaceBits - pageSizeBits;

        System.out.println("\"VPN\":" + pageTableIndexBits);
        System.out.println("\"Page Offset\":" + pageSizeBits);
        System.out.println("\"Page Table Index\":" + pageTableIndexBits);
        System.out.println("\"Frame Number\":" + (physicalMemoryBits - pageSizeBits));
        System.out.println("\"Offset within a Frame\":" + pageSizeBits);

        scanner.close();
    }
}
