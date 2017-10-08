
package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.runtime.cudaArray;

/**
 * Java port of a CUarray
 *
 * @see CUDAWrapperDriver#cuArrayCreate
 * @see CUDAWrapperDriver#cuArrayGetDescriptor
 * @see CUDAWrapperDriver#cuArray3DCreate
 * @see CUDAWrapperDriver#cuArray3DGetDescriptor
 * @see CUDAWrapperDriver#cuArrayDestroy
 */
public class CUarray extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUarray
     */
    public CUarray()
    {
    }

    /**
     * Creates a CUarray for the given {@link cudaArray}. This
     * corresponds to casting a cudaArray to a CUarray.
     *
     * @param array The other array
     */
    public CUarray(cudaArray array)
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
        return "CUarray["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
