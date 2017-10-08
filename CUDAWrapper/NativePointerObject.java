package CUDAWrapper;

/**
 * Base class for all classes that store a native pointer
 */
public abstract class NativePointerObject
{
    /**
     * The native pointer, written by native methods
     */
    private long nativePointer;

    /**
     * Creates a new NativePointerObject with a <code>null</code> pointer.
     */
    protected NativePointerObject()
    {
        nativePointer = 0;
    }

    /**
     * Creates a new Pointer with the given native pointer value
     */
    protected NativePointerObject(long nativePointer)
    {
        this.nativePointer = nativePointer;
    }

    /**
     * Creates a new Pointer with the samme native pointer as the
     * given one
     *
     * @param other The other NativePointerObject
     */
    protected NativePointerObject(NativePointerObject other)
    {
        this.nativePointer = other.nativePointer;
    }

    /**
     * Obtain the native pointer value.
     *
     * @return The native pointer value
     */
    protected long getNativePointer()
    {
        return nativePointer;
    }

    @Override
    public String toString()
    {
        return "NativePointerObject[nativePointer=" + nativePointer + "]";
    }

    @Override
    public int hashCode()
    {
        final int prime = 31;
        int result = 1;
        result = prime * result + (int)(nativePointer ^ (nativePointer >>> 32));
        return result;
    }

    @Override
    public boolean equals(Object obj)
    {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        NativePointerObject other = (NativePointerObject)obj;
        if (nativePointer != other.nativePointer)
            return false;
        return true;
    }

}
