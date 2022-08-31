package heap;

public class MaxHeap extends AbstractHeap<Integer> {
    public MaxHeap() {
    }

    @Override
    protected void sortBack(int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left < getSize()) {
            sortBack(left);
        }
        if (right < getSize()) {
            sortBack(right);
        }

        int parent = (index % 2 != 0 || index == 0) ? index / 2 : index / 2 - 1;
        if (heap.get(parent) < heap.get(index)) {
            heap.swap(parent, index);
        }
    }

    @Override
    protected void sortFront(int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if(size == 2 && heap.get(0) < heap.get(1)) {
            heap.swap(0, 1);
        }

        if (left < size && right < size) {
            if (heap.get(index) < heap.get(left) || heap.get(index) < heap.get(right)) {
                int child = (heap.get(left) >= heap.get(right)) ? left : right;

                heap.swap(index, child);
                sortFront(child);
            }
        }
    }
}
