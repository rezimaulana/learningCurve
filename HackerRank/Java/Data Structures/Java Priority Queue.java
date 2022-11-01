import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Comparator;
import java.util.stream.*;

class Student{
    int id;
    String name;
    double cgpa;
    
    public Student(int id, String name, double cgpa){
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }
    
    public int getID(){
        return id;
    }
    public String getName(){
        return name;
    }
    public double getCGPA(){
        return cgpa;
    }
}

class Priorities{
    public List<Student> getStudents(List<String> events){
        
        List<Student> studentlist = new ArrayList<Student>();
        
        for(String event : events){
            
            String[] temp = event.split(" ");
            
            if(temp[0].equals("ENTER")){
                
                Student student = new Student(Integer.parseInt(temp[3]),
                temp[1],
                Double.parseDouble(temp[2]));
                
                studentlist.add(student);
                
            }else if(temp[0].equals("SERVED")){
                if(!studentlist.isEmpty()){
                    studentlist = studentlist.stream().sorted(Comparator.comparing(Student::getCGPA)                                        .reversed().thenComparing(Student::getName)
                                    .thenComparing(Student::getID))
                                    .collect(Collectors.toList());
                    studentlist.remove(0);
                }
            }
        } 
        return studentlist;
    }
}

