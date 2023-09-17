class leftshift_operator {
    public static void main(String args[]) {
        byte x = 64;
        int i;
        byte y;
        i = x << 2;
        y = (byte) (x << 2);
        System.out.print(i + " " + y);
    }
}
