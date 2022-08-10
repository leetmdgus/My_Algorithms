package heap;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HeapTest2 {
    Heap heap = new Heap();

    @Test
    void add() {
        for(int i = 9; i>2; i--) {
            heap.add(i);
        }
        assertEquals(heap.toString(), "[0, 3, 6, 4, 9, 7, 8, 5]");
    }

    @Test
    void remove() {
        for(int i = 9; i>2; i--) {
            heap.add(i);
        }
        heap.remove();
        heap.remove();
        assertEquals(heap.toString(), "[0, 5, 6, 8, 9, 7]");

    }
}