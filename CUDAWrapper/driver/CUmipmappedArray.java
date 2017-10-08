

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUmipmappedArray.
 */
public class CUmipmappedArray extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUmipmappedArray
     */
    public CUmipmappedArray()
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
        return "CUmipmappedArray["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
