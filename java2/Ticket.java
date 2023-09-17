import java.util.Scanner;

public class Ticket {

    private String name;
    private int age;
    private int ticketCount;
    private double ticketPrice;

    public Ticket() {
        // constructor
    }

    public void input() {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter your name: ");
            this.name = scanner.nextLine();
            System.out.print("Enter your age: ");
            this.age = scanner.nextInt();
            System.out.print("Enter the number of tickets: ");
            this.ticketCount = scanner.nextInt();
            System.out.print("Enter the price per ticket: ");
            this.ticketPrice = scanner.nextDouble();
        }
    }

    public double calculateTicketAmount() {
        double ticketAmount = this.ticketCount * this.ticketPrice;
        double taxAmount = ticketAmount * 0.18;
        double discountAmount = ticketAmount * 0.05;
        return ticketAmount + taxAmount - discountAmount;
    }

    public void printTicketDetails(double amountPayable) {
        System.out.println("Ticket details:");
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Ticket count: " + this.ticketCount);
        System.out.println("Ticket price: " + this.ticketPrice);
        System.out.println("Amount payable: " + amountPayable);
    }

    public static void main(String[] args) {
        Ticket ticket = new Ticket();
        ticket.input();
        double amountPayable = ticket.calculateTicketAmount();
        ticket.printTicketDetails(amountPayable);
    }
}
