

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUtexObject.
 */
public class CUtexObject extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUtexObject
     */
    public CUtexObject()
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
        return "CUtexObject["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
