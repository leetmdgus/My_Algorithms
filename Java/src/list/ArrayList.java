package list;

public class ArrayList<E> implements List<E> {
    private Object[] array = new Object[10];
    private int size;
    private int capacity = 10;

    public ArrayList() {
    }

    @Override
    public void add(E data) {
        size++;
        if (size == capacity) {
            expand();
        }
        array[size - 1] = data;
    }

    @Override
    public E remove() {
        if(isEmpty()) {
            return null;
        }
        return (E) array[--size];
    }

    @Override
    public E get(int index) {
        if(index < size || index >= 0) {
            return (E) array[index];
        }
        return null;
    }

    @Override
    public int getSize() {
        return size;
    }
    @Override
    public boolean isEmpty() {
        return (size == 0);
    }
    @Override
    public void clear() {
        array = new Integer[capacity];
    }

    @Override
    public E[] clone() {
        Object[] newArr = new Object[getCapacity()];
        for (int i = 0; i < getSize(); i++) {
            newArr[i] = array[i];
        }

        return (E[]) newArr;
    }

    @Override
    public void swap(int index1 , int index2) {
        if(isValidIndex(index1) && isValidIndex(index2)) {
            E tmp = (E) array[index1];
            array[index1] = array[index2];
            array[index2] = tmp;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for(int i = 0; i<getSize()-1; i++) {
            sb.append(get(i)+ ", ");
        }
        sb.append(get(size-1));
        sb.append(']');
        return sb.toString();
    }

    private boolean isValidIndex(int index) {
        if(index < size || index >= 0) {
            return true;
        }
        return false;
    }

    private void expand() {
        E[] newArr = this.clone();
        capacity *= 2;
        array = new Object[getCapacity()];

        for (int i = 0; i < getSize(); i++) {
            array[i] = newArr[i];
        }
    }
    public Integer getCapacity() {
        return capacity;
    }
}
