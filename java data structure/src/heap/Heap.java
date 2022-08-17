package heap;

interface Heap<E> {
    void add(E data);
    E poll();
}