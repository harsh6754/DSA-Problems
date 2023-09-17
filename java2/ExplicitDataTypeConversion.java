public class ExplicitDataTypeConversion {
    public static void main(String[] args) {
        double a = 50.55;
        System.out.println("Double Representation : "+a);

        float b = (float)a;
        System.out.println("Float Representation  : "+b);

        long c =(long)b;
        System.out.println("Long Representation : "+c);

        int d = (int)c;
        System.out.println("Int Representation : "+d);
    
    }
}
