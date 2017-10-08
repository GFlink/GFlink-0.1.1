package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.driver.CUarray;

/**
 * Java port of a cudaArray
 *
 * @see CUDAWrapper#cudaMallocArray
 * @see CUDAWrapper#cudaMalloc3DArray
 * @see CUDAWrapper#cudaFreeArray
 */
public class cudaArray extends NativePointerObject
{
    /**
     * Creates a new, uninitialized cudaArray
     */
    public cudaArray()
    {
    }

    /**
     * Creates a cudaArray for the given {@link CUarray}. This
     * corresponds to casting a CUarray to a cudaArray.
     *
     * @param array The other array
     */
    public cudaArray(CUarray array)
    {
        super(array);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "cudaArray["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }
}
