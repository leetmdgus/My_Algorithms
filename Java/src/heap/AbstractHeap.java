package heap;

import list.ArrayList;
import list.List;

public abstract class AbstractHeap<E> implements Heap<E> {
    private final List<E> heap = new ArrayList<E>();

    @Override
    public void add(E data) {
        heap.add(data);
        sortBack(0);
    }

    @Override
    public E remove() {
        if (heap.isEmpty()) {
            return null;
        }

        heap.swap(0, heap.getSize() - 1);
        E data = heap.remove();
        sortFront(0);

        return data;
    }

    private void sortBack(int index){
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if (left < getSize()) {
            sortBack(left);
        }
        if (right < getSize()) {
            sortBack(right);
        }

        int parent = (index % 2 != 0 || index == 0) ? index / 2 : index / 2 - 1;
        if (compare(heap.get(index), heap.get(parent))) {
            heap.swap(parent, index);
        }
    }

    private void sortFront(int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if(heap.getSize() == 2 && compare(heap.get(1), heap.get(0))) {
            heap.swap(0, 1);
        }

        if (left < heap.getSize() && right < heap.getSize()) {
            if (compare(heap.get(left), heap.get(index)) || compare(heap.get(right), heap.get(index))) {
                int child = !compare(heap.get(right), heap.get(left)) ? left : right;

                heap.swap(index, child);
                sortFront(child);
            }
        }
    }

    protected abstract boolean compare(E data1, E data2);

    public int getSize() {
        return heap.getSize();
    }

    public String toString() {
        return heap.toString();
    }
}
