

package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a cudaMipmappedArray
 */
public class cudaMipmappedArray extends NativePointerObject
{
    /**
     * Creates a new, uninitialized cudaMipmappedArray
     */
    public cudaMipmappedArray()
    {
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "cudaMipmappedArray["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }
}
