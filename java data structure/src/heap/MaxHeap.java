package heap;

import java.util.*;

public class MaxHeap implements Heap<Integer>{
    private final List<Integer> heap = new ArrayList<>();
    private int size;

    public MaxHeap(){}

    @Override
    public void add(Integer data) {
        size++;
        heap.add(data);
        sortBack(0);
    }

    @Override
    public Integer poll() {
        if (size == 0) {
            return null;
        }

        Collections.swap(heap, 0, size - 1);
        int data = heap.remove(size - 1);
        size--;

        sortFront(0);
        return data;
    }

    private void sortBack(int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left < size) {
            sortBack(left);
        }
        if (right < size) {
            sortBack(right);
        }

        int parent = (index % 2 != 0 || index == 0) ? index / 2 : index / 2 - 1;
        if (heap.get(parent) < heap.get(index)) {
            Collections.swap(heap, parent, index);
        }
    }

    private void sortFront(int index) {
        if (size == 2) {
            if(heap.get(0) < heap.get(1)) {
                Collections.swap(heap, 0, 1);
                return;
            }
        }
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if(left < size && right < size) {
            if (heap.get(index) < heap.get(left) || heap.get(index) < heap.get(right)) {
                int child= (heap.get(left) >= heap.get(right)) ? left : right;

                Collections.swap(heap, index, child);
                sortFront(child);
            }
        }
    }

    public int getSize() {
        return size;
    }

    public String toString() {
        return heap.toString();
    }
}
