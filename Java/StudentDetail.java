public class StudentDetail {
        public static void main(String s[]) {
            Student students[] = new Student[5];

            students[0] = new Student();
            students[0].name = "Rajesh";
            students[0].marks = 45;
            students[0].section = 'A';

            students[1] = new Student();
            students[1].name = "Suresh";
            students[1].marks = 78;
            students[1].section = 'B';

            students[2] = new Student();
            students[2].name = "Ramesh";
            students[2].marks = 83;
            students[2].section = 'A';

            students[3] = new Student();
            students[3].name = "Kamlesh";
            students[3].marks = 77;
            students[3].section = 'A';

            students[4] = new Student();
            students[4].name = "Vignesh";
            students[4].marks = 93;
            students[4].section = 'B';

            for (int i = 0; i < students.length; i++) {
                System.out.println(students[i].name + " in section " + students[i].section + " got " + students[i].marks
                        + " marks.");
            }
        }

    }

    class Student {
        String name;
        int marks;
        char section;
        String address;
        String mobile;
    }

