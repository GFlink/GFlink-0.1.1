
package CUDAWrapper.driver;

import CUDAWrapper.Pointer;

/**
 * Java port of a CUdeviceptr.
 */
public class CUdeviceptr extends Pointer
{
    /**
     * Creates a new (null) device pointer
     */
    public CUdeviceptr()
    {
    }

    /**
     * Copy constructor
     *
     * @param other The other pointer
     */
    protected CUdeviceptr(CUdeviceptr other)
    {
        super(other);
    }

    /**
     * Creates a copy of the given pointer, with an
     * additional byte offset
     *
     * @param other The other pointer
     * @param byteOffset The additional byte offset
     */
    protected CUdeviceptr(CUdeviceptr other, long byteOffset)
    {
        super(other, byteOffset);
    }

    @Override
    public CUdeviceptr withByteOffset(long byteOffset)
    {
        return new CUdeviceptr(this, byteOffset);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "CUdeviceptr["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+","+
            "byteOffset="+getByteOffset()+"]";
    }


}
