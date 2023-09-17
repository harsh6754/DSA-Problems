import java.io.*;

class Employee {
    int Emp_id;
    String Emp_name;
    int Emp_salary;
    String Emp_Address;
    int Emp_Contact;
    String Emp_Gender;
    int Emp_Age;
    String Emp_Department;

    Employee(int empid, String empname, int empsalary, String empaddress, int empcontact, String empgender, int empage,
            String empdepartment) {
        Emp_id = empid;
        Emp_name = empname;
        Emp_salary = empsalary;
        Emp_Address = empaddress;
        Emp_Contact = empcontact;
        Emp_Gender = empgender;
        Emp_Age = empage;
        Emp_Department = empaddress;
    }

    void display() {
        System.out.println("ID: " + this.Emp_id + " Name: " + this.Emp_name + " Salary:" + this.Emp_salary + " Address "
                + this.Emp_Contact + " Contact" + this.Emp_Contact + "Gender" + this.Emp_Gender + " Age " + this.Emp_Age
                + " Department" + this.Emp_Department);
    }

    public static void main(String args[]) throws IOException {
        Employee e[] = new Employee[10];
        for (int i = 0; i < 10; i++) {
            System.out.println("Enter the ID, Name , Salary , Address ,Contact,Gender, Age , Department of Employee("
                    + (i + 1) + ")");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int Emp_id = Integer.parseInt(br.readLine());
            String Emp_name = br.readLine();
            int Emp_salary = Integer.parseInt(br.readLine());
            String Emp_Address = br.readLine();
            int Emp_Contact = Integer.parseInt(br.readLine());
            String Emp_Gender = br.readLine();
            int Emp_Age = Integer.parseInt(br.readLine());
            String Emp_Department = br.readLine();
            e[i] = new Employee(Emp_id, Emp_name, Emp_salary, Emp_Address, Emp_Contact, Emp_Gender, Emp_Age,
                    Emp_Department);
        }
        System.out.println("Employee Details: \n-------------------");
        for (int i = 0; i < 10; i++) {
            e[i].display();
        }

    }
}