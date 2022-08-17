package heap;

import org.junit.jupiter.api.Test;

import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;

import static org.junit.jupiter.api.Assertions.*;

class MaxHeapTest1 {
    Heap myHeap = new MaxHeap();
    Queue<Integer> heap = new PriorityQueue<>(Collections.reverseOrder());

    @Test
    void add() {
        for(int i =1; i<10; i++) {
            heap.add(i);
            myHeap.add(i);
        }
        assertEquals(heap.toString(), myHeap.toString());
    }

    @Test
    void poll() {
        for(int i =1; i<10; i++) {
            heap.add(i);
            myHeap.add(i);
        }

        for(int i =0 ; i<2; i++) {
            heap.poll();
            myHeap.poll();
        }

        assertEquals(heap.toString(), myHeap.toString());
    }
}