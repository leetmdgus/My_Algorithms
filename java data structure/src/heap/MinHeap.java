package heap;

import java.util.*;

public class MinHeap implements Heap<Integer> {
    private final List<Integer> heap = new ArrayList<>();
    public MinHeap() {
    }

    public void add(Integer data) {
        heap.add(data);
        sortBack(0);
    }

    public Integer poll() {
        int size = heap.size();
        if (size == 0) {
            return null;
        }

        Collections.swap(heap, 0, size - 1);
        int data = heap.remove(size - 1);
        sortFront(0);
        return data;
    }

    private void sortBack(int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left < heap.size()) {
            sortBack(left);
        }
        if (right < heap.size()) {
            sortBack(right);
        }

        int parent = (index % 2 != 0 || index == 0) ? index / 2 : index / 2 - 1;
        if (heap.get(parent) > heap.get(index)) {
            Collections.swap(heap, parent, index);
        }
    }

    private void sortFront(int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if(left < heap.size() && right < heap.size()) {
            if (heap.get(index) > heap.get(left) || heap.get(index) > heap.get(right)) {
                int child= (heap.get(left) <= heap.get(right)) ? left : right;

                Collections.swap(heap, index, child);
                sortFront(child);
            }
        }
    }

    private String levelOrder() {
        ArrayList<Integer> result = new ArrayList<>();
        Queue<int[]> queueDataIndexes = new LinkedList<>();
        queueDataIndexes.add(new int[]{heap.get(0), 0});

        while (!queueDataIndexes.isEmpty()) {
            int[] element = queueDataIndexes.poll();
            int data = element[0];
            int index = element[1];

            result.add(data);

            int left = index * 2 + 1;
            int right = index * 2 + 2;
            if (left < heap.size()) {
                queueDataIndexes.add(new int[]{heap.get(left), left});
            }
            if (right < heap.size()) {
                queueDataIndexes.add(new int[]{heap.get(right), right});
            }
        }
        return result.toString();
    }

    public String toString() {
        return levelOrder();
    }
}
