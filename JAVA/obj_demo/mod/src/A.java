public class A {
    private static int priData;
    protected static int protData;
    public static int pubData;
    public void func() {
        protClass pC = new protClass();
        pC.func();
        System.out.println("func");
    }

    public void showPriData() {
        System.out.println(priData);
    }
}