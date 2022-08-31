package list;

public interface List<E> {
    void add(E data);
    E remove();
    E get(int index);
    void swap(int index1, int index2);
    String toString();

    int getSize();
    void clear();
    boolean isEmpty();
    E[] clone();
}
