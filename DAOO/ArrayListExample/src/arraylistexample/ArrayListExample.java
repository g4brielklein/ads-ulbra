package arraylistexample;

import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> animals = new ArrayList<>();

        // Add elements
        animals.add("Dog");
        animals.add("Cat");
        animals.add("Horse");
        System.out.println("ArrayList: " + animals);
        
        // Add using index number
        ArrayList<String> cars = new ArrayList<>();

        // Add elements
        cars.add(0,"Ford");
        cars.add(1,"Ferrari");
        cars.add(2,"BMW");
        System.out.println("ArrayList: " + cars);
    }  
}
