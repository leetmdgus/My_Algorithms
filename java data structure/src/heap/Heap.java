package heap;

import java.util.ArrayList;
import java.util.Collections;

public class Heap {
    ArrayList<Integer> heap = new ArrayList<>();
    Heap() {
        heap.add(0);
    }

    void add(int n) {
        heap.add(n);

        int index = heap.size()-1;
        int parent = index/2;
        while(heap.get(parent) > n) {
            Collections.swap(heap, parent, index);
            parent = parent/2;
            index = index/2;
        }
    }

    int remove() {
        int size = heap.size();
        if(size == 1) {
            return -1;
        }

        Collections.swap(heap, 1, size-1);
        int data = heap.remove(size-1);
        size = heap.size();

        int index = 1;
        int left = index *2;
        int right = index*2+1;

        if(left >= size || right >= size) {
            return data;
        }

        while(heap.get(left) < heap.get(index) || heap.get(right) < heap.get(index)) {
            if(heap.get(left) <= heap.get(right)) {
                if(heap.get(left) < heap.get(index)) {
                    Collections.swap(heap, left, index);
                    index = index*2;
                }
            } else {
                if(heap.get(right) < heap.get(index)) {
                    Collections.swap(heap, right, index);
                    index = index*2+1;
                }
            }
            left = index *2;
            right = index*2+1;
            if(left >= size || right >= size) {
                return data;
            }
        }
        return data;
    }

    @Override
    public String toString() {
        return heap.toString();
    }
}
