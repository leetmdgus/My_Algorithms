package list;

public class ArrayList<E> implements List<E> {
    protected Object[] array = new Object[10];
    protected int size;
    protected int capacity = 10;

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

    public Integer getCapacity() {
        return capacity;
    }

    public Integer getSize() {
        return size;
    }

    public boolean isEmpty() {
        return (size == 0);
    }

    public void clear() {
        array = new Integer[capacity];
    }

    private void expand() {
        E[] newArr = this.clone();
        capacity *= 2;
        array = new Object[getCapacity()];

        for (int i = 0; i < getSize(); i++) {
            array[i] = newArr[i];
        }
    }

    public E[] clone() {
        Object[] newArr = new Object[getCapacity()];
        for (int i = 0; i < getSize(); i++) {
            newArr[i] = array[i];
        }

        return (E[]) newArr;
    }

    public void swap(int index1 , int index2) {
        if(isValidIndex(index1) && isValidIndex(index2)) {
            E tmp = (E) array[index1];
            array[index1] = array[index2];
            array[index2] = tmp;
        }
    }

    private boolean isValidIndex(int index) {
        if(index < size || index >= 0) {
            return true;
        }
        return false;
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
}
