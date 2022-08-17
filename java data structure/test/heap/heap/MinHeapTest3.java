package heap;

import org.junit.jupiter.api.Test;

import java.util.PriorityQueue;
import java.util.Queue;

import static org.junit.jupiter.api.Assertions.*;

class MinHeapTest3 {
    Heap myHeap = new MinHeap();
    Queue<Integer> heap = new PriorityQueue<>();

    @Test
    void add() {
        for(int j = 0; j< 3; j++) {
            for (int i = 5; i > 0; i--) {
                heap.add(i);
                myHeap.add(i);
            }
        }

        assertEquals(heap.toString(), myHeap.toString());
    }

    @Test
    void pop() {
        for(int j = 0; j< 3; j++) {
            for (int i = 5; i > 0; i--) {
                heap.add(i);
                myHeap.add(i);
            }
        }

        for (int i = 0; i < 10; i++) {
            heap.poll();
            myHeap.poll();
        }
        assertEquals(heap.toString(), myHeap.toString());
    }


}