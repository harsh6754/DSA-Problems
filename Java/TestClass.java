interface Parent2 {
      default void show()
      {
        System.out.println("Default Parent2");
     }
}
interface  Parent1 {
    default void show()
     {
        System.out.println("Default Parent1");
     }
}

class TestClass implements Parent1,Parent2{
      @Override 
      public void show()
      {
        Parent1.super.show();
        Parent2.super.show();
      }
      public void showOfParent1()
      {
        Parent1.super.show();
      }
      
      public void showOfParent2() {
          Parent2.super.show();
      }

      public static void main(String[] args) {
        TestClass d = new TestClass();
        d.show();
        System.out.println("Now showOfParent1() showOfParent2()");
        d.showOfParent1();
        d.showOfParent2();

      }


}