abstract class progam{
    public abstract void Developer();
    public abstract void language();
}

class HTML extends progam {
    @Override
    public void Developer() {
        System.out.println("HTML Developer");
    }

    @Override
    public void language() {
        System.out.println("HTML Language");
    }
}

class Java extends progam {
    @Override
    public void Developer() {
        System.out.println("Java Developer");
    }

    @Override
    public void language() {
        System.out.println("Java Language");
    }
}

class am {
    public static void main(String[] args) {
        progam htmlDev = new HTML();
        htmlDev.Developer(); // Output: HTML Developer
        htmlDev.language();  // Output: HTML Language

        progam javaDev = new Java();
        javaDev.Developer(); // Output: Java Developer
        javaDev.language();  // Output: Java Language

    }
}