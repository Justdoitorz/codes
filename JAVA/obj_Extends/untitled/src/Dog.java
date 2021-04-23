import java.util.ArrayList;

interface Animal {

}

class Mammal implements Animal {
    public void move() {
        System.out.println("Mammal can Move");
    }
}

public class Dog extends Mammal {
    @Override
    public void move() {
        System.out.println("Dog can Run and Walk");
    }
    
    public void bark(String mess) {
        System.out.println(mess);
    }
    public void bark() {
        System.out.println("Dog can Bark");
    }

    public static void overrideTest() {
        Mammal m = new Mammal();
        Dog d = new Dog();
        Mammal md = new Dog();

        m.move();
        d.move();
        d.bark();
        d.bark("WanWan");
        md.move();
        //md.bark();



    }

    public static void extendsTest() {
        Mammal mam = new Mammal();
        Dog dog = new Dog();
        Mammal mamB = new Dog();

        System.out.println(mam instanceof Animal);
        System.out.println(mam instanceof Mammal);

        System.out.println(dog instanceof Animal);
        System.out.println(dog instanceof Mammal);
        System.out.println(dog instanceof Dog);

        System.out.println(mamB instanceof Animal);
        System.out.println(mamB instanceof Mammal);
        System.out.println(mamB instanceof Dog);
    }

    public static void main(String []args) {
        extendsTest();
        overrideTest();
        ArrayList<Integer> als = new ArrayList();
        String str = "123456";
        String []arr = str.split("\\d", -1);
        System.out.println(arr.length);
        for (String s : arr) {
            System.out.println(s);
        }

    }
}

