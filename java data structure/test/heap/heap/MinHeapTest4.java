package heap;

import org.junit.jupiter.api.Test;

import java.util.PriorityQueue;
import java.util.Queue;

import static org.junit.jupiter.api.Assertions.*;

class MinHeapTest4 {
    Heap<Integer> myHeap = new MinHeap();
    Queue<Integer> heap = new PriorityQueue<>();

    @Test
    void add() {
        for(int i = 0; i<10000; i++) {
            int randomNum = (int) (Math.random()*100+1);
            heap.add(randomNum);
            myHeap.add(randomNum);
        }

        assertEquals(heap.toString(), myHeap.toString());
    }

    @Test
    void remove() {
        for(int i = 0; i<100; i++) {
            int randomNum = (int) (Math.random()*100+1);
            heap.add(randomNum);
            myHeap.add(randomNum);
        }

        for(int i = 0; i<100; i++) {
            int randomNum = (int) (Math.random()*100+1);
            heap.remove(randomNum);
            myHeap.remove();
        }
        assertEquals(heap.toString(), myHeap.toString());
    }
}