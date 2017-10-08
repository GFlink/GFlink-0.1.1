

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUsurfObject.
 */
public class CUsurfObject extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUsurfObject
     */
    public CUsurfObject()
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
        return "CUsurfObject["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
