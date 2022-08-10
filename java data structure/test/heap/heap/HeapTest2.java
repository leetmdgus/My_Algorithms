package heap;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HeapTest2 {
    Heap heap = new Heap();

    @Test
    void add() {
        for(int i = 1; i<=10; i++) {
            heap.add(i);
        }
        assertEquals(heap.toString(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]");
    }

    @Test
    void remove() {


    }
}