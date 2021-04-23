
import java.io.Serializable;
//import fuck.wtf.*;

class protClass {
    public void func() {
        System.out.println("protClass func");
    }
}

class vvv implements Serializable
{

}
interface Animal {
    default void move() {
        System.out.println("Animal can move");
    }
}

class Mammal implements Animal {

    @Override
    public void move() {
        System.out.println("Mammal can move");
    }

    public static void eat() {
        System.out.println("Mammal can eat");
    }
}

class Dog extends Mammal {
    @Override
    public void move() {
        System.out.println("Dog can move");
    }

    //@Override   static method can't override
    public static void eat() {
        System.out.println("Dog self eat");
    }
}


class Vehicle {}
class Speed {}
class Van extends Vehicle {
    private Speed sp;
}

public class obj extends B {

    obj() {
        System.out.println("Constructor obj");
    }

    public static void override_demo() {

    }

    public static void extends_demo() {
        A a = new A();
        B b = new B();
        obj o = new obj();

        b.finalVarTest("I love you");

        System.out.println(a.protData);
        System.out.println(b.protData);
        System.out.println(obj.pubData);
        a.func();
        b.func();
        a.showPriData();

        protClass pC = new protClass();
        pC.func();

        System.out.println(a instanceof B);
        System.out.println(b instanceof B);
        System.out.println(o instanceof B);

        Mammal mam = new Mammal();
        Mammal dog = new Dog();

        mam.move();
        dog.move();

        System.out.println(mam instanceof Mammal);
        System.out.println(dog instanceof Mammal);
        System.out.println(dog instanceof Animal);
        System.out.println(dog instanceof Object);//JAVA every class extends Object

        Fruit1 f1 = new Fruit1() {
            @Override
            public String toString() {
                return "super.toString()";
            }
        };
        System.out.println(f1.toString());
        Fruit f = new Fruit() {
            @Override
            public String sayFuck() {
                return "Fuck";
            }
        };
        System.out.println(f.sayFuck());
        System.out.println(f.sayFuck());


    }

    public static void main(String []args) {
        extends_demo();
        System.out.println(java.lang.Math.PI);
        fuck.wtf.pp p = new fuck.wtf.pp();
        p.ppp();
        System.out.println(p.getData());
        Integer a = 128;
        Integer b = new Integer(128);
        Integer d = 128;
        Integer e = new Integer(128);;
        int c = 128;
        argsTest(a);
        System.out.println(a);
        System.out.println(a == b);
        System.out.println(a == d);
        System.out.println(b == c);

        System.out.println(b.equals(e));

        System.out.println(Integer.signum(0));
    }
    public static void argsTest(Integer a) {
        a = 9;
    }
}

abstract class Fruit {
    //final
    public String sayFuck() {
        return "I love you";
    }
}

interface Fruit1 {}

interface Fruit3 {}

interface Fruit2 extends Fruit3 {}

class Apple extends Fruit implements Fruit1, Fruit2 {

}


class grandpa {}
abstract class father extends grandpa {}
class son extends father {}

//final