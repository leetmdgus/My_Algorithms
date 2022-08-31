package list;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ArrayListTest1 {

    @Test
    void add() {
        List<Integer> array = new ArrayList<>();

        for(int i = 0; i<100; i++) {
            array.add(i);
        }
        System.out.println(array);
    }

    @Test
    void remove() {
        List<Integer> array = new ArrayList<>();
        for(int i = 0; i<100; i++) {
            array.add(i);
        }

        List<Integer> result = new ArrayList<>();
        for(int i = 0; i<100; i++) {
            result.add(array.remove());
        }
        System.out.println(result);
    }

    @Test
    void get() {
        List<Integer> array = new ArrayList<>();
        for(int i = 0; i<100; i++) {
            array.add(i);
        }

        List<Integer> result = new ArrayList<>();
        for(int i = 0; i<100; i++) {
            result.add(array.get(i));
        }
        System.out.println(result);
    }

    @Test
    void swap() {
        List<Integer> array = new ArrayList<>();
        for(int i = 0; i<10; i++) {
            array.add(i);
        }
        array.swap(0, 9);
        array.swap(1,8);
        System.out.println(array);
    }

}