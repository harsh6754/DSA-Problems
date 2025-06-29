abstract class cars{
    public abstract void start();
    public abstract void stop();
}

abstract class Bike extends cars{
    @Override
    public void start() {
        System.out.println("Bike is starting");
    }
    
    @Override
    public void stop() {
        System.out.println("Bike is stopping");
    }
}

class Scooter extends Bike {
    @Override
    public void start() {
        System.out.println("Scooter is starting");
    }
    
    @Override
    public void stop() {
        System.out.println("Scooter is stopping");
    }
}

class am_Diff {
    public static void main(String[] args) {
        cars myBike = new Bike() {
            @Override
            public void start() {
                System.out.println("Anonymous Bike is starting");
            }
            
            @Override
            public void stop() {
                System.out.println("Anonymous Bike is stopping");
            }
        };
        
        myBike.start(); // Output: Anonymous Bike is starting
        myBike.stop();  // Output: Anonymous Bike is stopping
        
        Scooter myScooter = new Scooter();
        myScooter.start(); // Output: Scooter is starting
        myScooter.stop();  // Output: Scooter is stopping
    }
}