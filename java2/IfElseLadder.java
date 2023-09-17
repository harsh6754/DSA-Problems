public class IfElseLadder {
    public static void main(String[] args) {
        int testscore = 50;
        char grade ;

        if(testscore >=90)
        {
            grade ='A';
        }
        else if(testscore >=80)
        {
            grade ='B';
            
        }
        else if(testscore >=70)
        {
            grade='C';
        }
        else if(testscore >=60)
        {
            grade='D';
        }
        else if(testscore >= 50)
        {
            grade='P';
        }
        else{
            grade='F';
        }
        System.out.println("Grade="+grade);
    }
}
