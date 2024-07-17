import java.util.Scanner;

public class ceaser_cipher {

    // Function to encrypt plaintext using Caesar cipher with a given shift
    public static String caesarEncrypt(String plaintext, int shift) {
        StringBuilder encryptedText = new StringBuilder();

        for (int i = 0; i < plaintext.length(); i++) {
            char ch = plaintext.charAt(i);

            // Encrypt uppercase letters
            if (Character.isUpperCase(ch)) {
                char encryptedChar = (char) ((ch - 'A' + shift) % 26 + 'A');
                encryptedText.append(encryptedChar);
            }
            // Encrypt lowercase letters
            else if (Character.isLowerCase(ch)) {
                char encryptedChar = (char) ((ch - 'a' + shift) % 26 + 'a');
                encryptedText.append(encryptedChar);
            }
            // Keep non-alphabet characters unchanged
            else {
                encryptedText.append(ch);
            }
        }

        return encryptedText.toString();
    }

    // Function to decrypt ciphertext using Caesar cipher with a given shift
    public static String caesarDecrypt(String ciphertext, int shift) {
        StringBuilder decryptedText = new StringBuilder();

        for (int i = 0; i < ciphertext.length(); i++) {
            char ch = ciphertext.charAt(i);

            // Decrypt uppercase letters
            if (Character.isUpperCase(ch)) {
                char decryptedChar = (char) ((ch - 'A' - shift + 26) % 26 + 'A');
                decryptedText.append(decryptedChar);
            }
            // Decrypt lowercase letters
            else if (Character.isLowerCase(ch)) {
                char decryptedChar = (char) ((ch - 'a' - shift + 26) % 26 + 'a');
                decryptedText.append(decryptedChar);
            }
            // Keep non-alphabet characters unchanged
            else {
                decryptedText.append(ch);
            }
        }

        return decryptedText.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Get user input for plaintext message
            System.out.print("Enter the plaintext message to encrypt: ");
            String plaintext = scanner.nextLine();

            // Get user input for shift value
            System.out.print("Enter the shift value (integer): ");
            int shift = scanner.nextInt();
            scanner.nextLine(); // Consume newline left by nextInt()

            // Encrypt the plaintext message
            String encryptedMessage = caesarEncrypt(plaintext, shift);
            System.out.println("Encrypted message: " + encryptedMessage);

            // Ask user for new input to decrypt the encrypted message
            System.out.println("\nEnter the encrypted message to decrypt: ");
            String ciphertext = scanner.nextLine();

            // Decrypt the encrypted message
            String decryptedMessage = caesarDecrypt(ciphertext, shift);
            System.out.println("Decrypted message: " + decryptedMessage);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } 
        scanner.close();
    }
}