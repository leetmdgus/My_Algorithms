package heap;

public interface Heap<E> {
    void add(E data);
    E poll();
}
