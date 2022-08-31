package heap;

import list.ArrayList;
import list.List;

public abstract class AbstractHeap<E> implements Heap<E> {
    protected final List<E> heap = new ArrayList<E>();
    protected int size;

    @Override
    public void add(E data) {
        size++;
        heap.add(data);
        sortBack(0);
    }

    @Override
    public E remove() {
        if (size == 0) {
            return null;
        }

        heap.swap(0, size - 1);
        E data = heap.remove();
        size--;
        sortFront(0);

        return data;
    }

    protected abstract void sortBack(int index);

    protected abstract void sortFront(int index);

    public int getSize() {
        return size;
    }

    public String toString() {
        return heap.toString();
    }

}
