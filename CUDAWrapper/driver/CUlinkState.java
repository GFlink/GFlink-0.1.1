
package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;

/**
 * Java port of a CUlinkState
 */
public class CUlinkState extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUlinkState
     */
    public CUlinkState()
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
        return "CUlinkState["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
