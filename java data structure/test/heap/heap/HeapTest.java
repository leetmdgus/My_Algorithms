package heap;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HeapTest1 {
    Heap heap = new Heap();

    @Test
    void add() {
        for (int i = 5; i > 0; i--) {
            heap.add(i);
        }
        assertEquals(heap.toString(), "[0, 1, 2, 4, 5, 3]");
    }

    @Test
    void remove() {
        for (int i = 5; i > 0; i--) {
            heap.add(i);
        }
        heap.remove();
        assertEquals(heap.toString(), "[0, 2, 3, 4, 5]");
    }
}