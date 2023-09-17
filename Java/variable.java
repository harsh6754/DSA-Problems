class Variable{
    int a=10;
    int b=20;
    public static void main(String args[]){
        {
            int c=30;
            Variable v= new Variable();
            System.out.println(v.a);
            System.out.println(v.b);
            System.out.println(c);
        }
    }
}